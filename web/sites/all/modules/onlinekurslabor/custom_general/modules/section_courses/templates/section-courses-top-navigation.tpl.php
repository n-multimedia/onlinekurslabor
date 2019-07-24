<?php
/**
 * User: naumenko-multimedia
 * Date: 17.05.2019
 * Time: 17:16
 */

?>

<nav class="navbar navbar-default section_navigation_course"
     id="section_navigation">
  <div class="container-fluid">
    <div class="col-md-6">
      <div class="navbar-header">
        <div id="course_top_nav_single-icon"></div>
      </div>
      <ul class="nav navbar-nav okl-nav-course-bar">
        <?php foreach ($single_links as $link): ?>
          <?php print $link['rendered_link']; ?>
        <?php endforeach; ?>
      </ul>
    </div>
    <div class="col-md-6">
      <div class="navbar-header">
        <div id="course_top_nav_collab-icon"></div>
      </div>
      <ul class="nav navbar-nav okl-nav-course-bar">
        <?php foreach ($collab_links as $link): ?>
          <?php print $link['rendered_link']; ?>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</nav>
<?php if (!empty($admin_tools)): ?>
  <nav class="navbar navbar-inverse" id="section-nav-instructor-tools">
    <div class="container-fluid">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle okl-toolbar-btn"
                id="instructor_tools_toggle_button"
                data-toggle="collapse"
                data-target="#instructor-tools" aria-expanded="false">
          <div class="animated-icon2">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </div>
        </button>
      </div>
      <div class="collapse navbar-collapse" id="instructor-tools">
        <?php print $admin_tools; ?>
      </div>
    </div>
  </nav>
<?php endif; ?>

