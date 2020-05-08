<?php
/**
 * @file
 * ViewsEFFieldsetData class file.
 */

/**
 * Class ViewsEFFieldsetData
 */
class ViewsEFFieldsetData {

  /**
   * @param array $elements
   * @param array $form
   * @param array $resulting_array
   */
  function __construct(array $data, array &$form = array()) {
    $this->data = $data;
    $this->elements = $data;
    $this->form = &$form;
  }

  /**
   * @param $elements
   * @return array
   */
  public function buildTreeData() {
    // Build the tree.
    $elements = $this->elements;

    $tree = $this->parseTree($elements);

    return $tree;
  }

  /**
   * @param array $elements
   * @param string $parentId
   * @param int $depth
   * @return array
   */
  private function parseTree(array &$elements, $rootParentID = '', $depth = -1) {
    $branch = array();
    ++$depth;

    foreach ($elements as $key => $element) {
      $element['depth'] = $depth;
      if ($element['pid'] != $rootParentID) {
        continue;
      }
      $branch[] = array(
        'item' => $element,
        'children' => $this->parseTree($elements, $element['id'], $depth)
      );
    }

    // Automatically get sorted results.
    usort($branch, array($this, 'sortByWeight'));

    return empty($branch) ? array() : $branch;
  }

  /**
   * @param array $tree
   * @return array
   */
  public function buildFlat() {
    $data = array();

    $recursive_iter_iter = new RecursiveIteratorIterator(
      new ArrayDataItemIterator($this->buildTreeData()),
      RecursiveIteratorIterator::SELF_FIRST
    );

    foreach($recursive_iter_iter as $item) {
      $data[] = $item;
    }

    return $data;
  }

  /**
   * Internal function used to sort array items by weight.
   */
  private function sortByWeight($a, $b) {
    if ($a['item']['weight'] == $b['item']['weight']) {
      return 0;
    }
    return ($a['item']['weight'] < $b['item']['weight'] ? -1 : 1);
  }

  public function treeToFAPI() {
    $elements = array();
    $tree = $this->buildTreeData();

    $this->recursiveTreeToFAPI($tree, $this->form, $elements);

    return $elements;
  }

  /**
   * @param $data
   * @param $form
   * @param array $element
   */
  private function recursiveTreeToFAPI($data, &$form, &$element = array()) {
    foreach($data as $key => $item) {

      // If it's a filter field
      if ($item['item']['type'] == 'filter') {
        $field_name = $form['#info']['filter-' . $item['item']['id']]['value'];

        if(isset($form[$field_name]) && is_array($form[$field_name])) {
          $element[$field_name] = $form[$field_name] +
            array(
              '#weight' => $item['item']['weight'],
              '#title' => $form['#info']['filter-' . $item['item']['id']]['label']
            );
          unset($form['#info']['filter-' . $item['item']['id']]);
          unset($form[$field_name]);
        }
      }

      // If it's a sort field
      if ($item['item']['type'] == 'sort') {
        $field_name = $item['item']['id'];

        if(isset($form[$field_name]) && is_array($form[$field_name])) {
          $element[$field_name] = $form[$field_name];
          $element[$field_name]['#weight'] = $item['item']['weight'];
          unset($form[$field_name]);
        }
      }

      // If it's the action buttons
      if ($item['item']['type'] == 'buttons') {
        $field_name = $item['item']['id'];

        if(isset($form[$field_name]) && is_array($form[$field_name])) {
          $element[$field_name] = $form[$field_name];
          $element[$field_name]['#weight'] = $item['item']['weight'];
          $form[$field_name]['#attributes']['style'][] = 'display:none;';
        }
      }

      if (!empty($item['children']) && $item['item']['type'] == 'container') {

        $element['container-' . $item['item']['id']] = array(
          '#type' => $item['item']['container_type'],
          '#title' => $item['item']['title'],
          '#description' => $item['item']['description'],
          '#collapsible' => (bool) $item['item']['collapsible'],
          '#collapsed' => (bool) $item['item']['collapsed'],
          '#attributes' => array(
            'class' => array(
              'views-ef-fieldset-container',
              'views-ef-fieldset-container-' . $item['item']['id']
            )
          ),
          '#weight' => $item['item']['weight']
        );

        $element['container-' . $item['item']['id']]['children'] = $this->recursiveTreeToFAPI($item['children'], $form, $element['container-'.$item['item']['id']]);
      }
    }
  }
}
