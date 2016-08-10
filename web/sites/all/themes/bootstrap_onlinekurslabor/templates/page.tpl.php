<nav class="navbar navbar-inverse" id="page_top_navigation">
  <div class="container">
    <div class="navbar-header">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>                        
      </button>
          <?php if (!empty($logo)): ?>
                <a class="navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" height="27"/>
                </a>
      <?endif?>
    </div>
       <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
    <div class="collapse navbar-collapse" id="myNavbar">
      
          <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
 
    </div>
      <?endif?>
  </div>
</nav>

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-md-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>  

    <section class="<?php print @_bootstrap_content_span($columns); ?>">  
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>

      <?php /* if (!empty($breadcrumb)): print $breadcrumb; endif; */ ?>
      <a id="main-content"></a>
      <div class="main-content">
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <h3 class="page-header"><?php print $title; ?></h3>
        <?php endif; ?>
          <div class="main-contet-wo-title">
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($page['help'])): ?>
          <div class="well"><?php print render($page['help']); ?></div>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
          </div>
      </div>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-md-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<footer class="footer container">
  <div class="footer_powered_by_wrapper row">
    <div id="footer_regions_container col-md-12">
      <div class="col-md-4 footer_region_left">
         <?php print render($page['footer_region_left']); ?>
      </div>
      <div class="col-md-8 footer_region_right">
        <?php print render($page['footer_region_right']); ?>
        <a href="http://ml.phil.uni-augsburg.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_ml.png" /></a>
      </div>
      <?php print render($page['footer']); ?>
    </div>
    
  </div>

</footer>
