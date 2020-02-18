/**
 * Created by Naumenko Multimedia on 29.07.2016.
 */


(function ($) {

  Drupal.behaviors.section_content_outline = {
    /*toggle solution for qaa questions*/
    attach: function (context, settings) {
      var outline_tree = $('.panels-flexible-column-first ul.menu').first();

      //$(".panels-flexible-column-first ul.menu").treemenu();
      outline_tree.once('nm_content', function () {
        //get outline dom


        //parse dom and get tree structure
        var tree = section_content_parse_tree(outline_tree);

        //search input dom
        var content_search = outline_tree.before('<div id="outline-search-element"><input id="countent-outline-search" class="outline-search-element" type="text" placeholder="' + Drupal.t("Search outline...") + '">&nbsp;<span class="no-result-badge glyphicon glyphicon-exclamation-sign" title="Kein Ergebnis" ></span></div>');
        var search_input = $("#countent-outline-search");

        var expand_all = outline_tree.before('<a href="#" id="content-outline-expand-all">' + Drupal.t("Expand all") + '</a>');
        var expand_button = $("#content-outline-expand-all");

        var collapse_all = outline_tree.before('<a href="#" id="content-outline-collapse-all">' + Drupal.t("Collapse all") + '</a>');
        var collapse_button = $("#content-outline-collapse-all");

        var lastPattern = '';

        // search callback
        var search = function (e) {
          var pattern = search_input.val();
          if (pattern === lastPattern) {
            return;
          }
          lastPattern = pattern;
          var tree = outline_tree.treeview(true);
          reset(tree);
          if (pattern.length < 3) { // avoid heavy operation
            tree.clearSearch();
            tree.expandNode(0);
          } else {
           /*direction-independent searchpattern */
           var pattern_no_direction = Drupal.behaviors.section_content_outline.convertInputToDirectionIndependentPattern(pattern);
           tree.search(pattern_no_direction);
            // get all root nodes: node 0 who is assumed to be
            //   a root node, and all siblings of node 0.
            var roots = tree.getSiblings(0);
            roots.push(tree.getNode(0));
            //first collect all nodes to disable, then call disable once.
            //  Calling disable on each of them directly is extremely slow!
            var unrelated = collectUnrelated(roots);
            var all_node_count = recurisvelyCountNodes(roots);
            if(unrelated.length == all_node_count)
            {
                $("#outline-search-element").addClass("no-result");
            }
            tree.disableNode(unrelated, {silent: true});  return;
          }
        };

        // collapse and enable all before search //
        function reset(tree) {
          tree.collapseAll();
          tree.enableAll();
          $("#outline-search-element").removeClass("no-result");
        }

        // find all nodes that are not related to search and should be disabled:
        // This excludes found nodes, their children and their parents.
        // Call this after collapsing all nodes and letting search() reveal.
        function collectUnrelated(nodes) {
          var unrelated = [];
          $.each(nodes, function (i, n) {
            if (!n.searchResult && !n.state.expanded) { // no hit, no parent
              unrelated.push(n.nodeId);
            }
            if (!n.searchResult && n.nodes) { // recurse for non-result children
              $.merge(unrelated, collectUnrelated(n.nodes));
            }
          });
          return unrelated;
        }
        
        /**
         * counts all nodes in a tree
         * @param {type} nodes
         * @returns {Number}
         */
        function recurisvelyCountNodes(nodes) {
             
          var counter = 0;
          $.each(nodes, function (i, n) {
             counter++; 
 
            if (n.nodes) { // recurse for non-result children
              counter +=  recurisvelyCountNodes
            (n.nodes);
            }
          });
          return counter;
       
        }


        /**
         * get tree structure from html dom tree
         * @param element
         */
        function section_content_parse_tree(element) {
          var tree = [];


          element = $(element);

          element.find("> li").each(function (i) {
            var a_element = $(this).find("> a");
            var item = {
              text: a_element.html(),
              href: a_element.attr("href"),
              selectable: true
            };

            if (a_element.hasClass("active-trail")) {
              item.state = {expanded: true};
            }else {
              item.state = {expanded: false};
            }

            if (a_element.hasClass("active")) {
              item.backColor = "#dee9ef";
            }

            var children = $(this).find("> ul");

            if (children.length > 0) {
              var nodes = section_content_parse_tree(children);
              item.nodes = nodes;
            }



            tree.push(item);
          });

          return tree;
        }


        //init tree
        outline_tree.treeview({
          data: tree,         // data is not optional
          backColor: 'transparent',
          enableLinks: true
        });

        //bind search callback
        search_input.on('keyup', search);

        expand_button.on('click', function () {
          outline_tree.treeview('expandAll');
        });

        collapse_button.on('click', function () {
          outline_tree.treeview('collapseAll');
        });
        ////initial collapse
        //outline_tree.treeview('collapseAll');
      });


    }
    ,
    /**
     * convertiert aus einem suchstring ein einfaches reihenfolgeunabhängiges pattern 
     * aus 
     *       1 2 3 wird
     *       1|2|3 1|2|3 1|2|3 
     * @param {type} inputstring
     * @returns {String}
     */
     convertInputToDirectionIndependentPattern: function (inputstring)
    {
        inputstring = inputstring.trim();
        //erlaube wort- statt textbasierter Suche
        var split_pattern = inputstring.split(" ");

        var single_search_term = "(";

        for (let i = 0; i < split_pattern.length; i++) {
            split_pattern[i] = split_pattern[i].trim();
            if (i < split_pattern.length - 1)
            {
                single_search_term += split_pattern[i] + '|';
            } else
            {
                single_search_term += split_pattern[i] + ')';
            }
        }
        var pattern_no_direction = "";
        for (let i = 0; i < split_pattern.length; i++) {
            pattern_no_direction += single_search_term;
            if (i < split_pattern.length - 1)
            {
                pattern_no_direction += '.*'
            }
        }
        
        return(pattern_no_direction);

    }
  };

}(jQuery));


