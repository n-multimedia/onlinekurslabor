<?php

$oDateTimeLocal = new DateTime("now", new DateTimeZone(date_default_timezone_get())); //first argument "must" be a string
$oDateTimeLocal->setTimestamp($timestamp); //adjust the object to correct timestamp
$formatted_ts_for_JS = $oDateTimeLocal->format('F d, Y H:i:s');

if ($hide_days_secs) {
  $eolcountdown_additional_theme_classes = $timestamp - time() > 24 * 60 * 60 ? 'eolcountdown_no_secs' : 'eolcountdown_no_days';
}

echo $before;
?>
<div class="eol_countdown_counter" style="display:none;"></div>
<script>


  jQuery(document).ready(function ($) {
      $(".eol_countdown_counter").dsCountDown({
          endDate: new Date("<?php echo $formatted_ts_for_JS; ?>"),
          titleDays: "<?= t('Days') ?>",
          titleHours: "<?= t('Hours') ?>",
          titleMinutes: "<?= t('Minutes') ?>",
          titleSeconds: "<?= t('Seconds') ?>",
          theme: '<?php echo $theme . ' ' . $eolcountdown_additional_theme_classes; ?>',
          onFinish: <?php echo $white_out ? 'Drupal.behaviors.eol_countdown.whiteout_screen' : 'null' ?>// callback if the count down is finished or 0 timer defined
      });
      //avoid flickering
      setTimeout(function () {
        $(".eol_countdown_counter").show();
      }, 1000);
              
  });

</script>


<?php
echo $after;
