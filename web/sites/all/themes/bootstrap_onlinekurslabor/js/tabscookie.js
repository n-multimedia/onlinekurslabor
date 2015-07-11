/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.okl_bootstrap_tabscookie = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {
            var tabsid = "#tabs-0-center";
            var cookieid = "tabs_0_center_selected";
            if ($(tabsid).length > 0) {
                $(tabsid).tabs({
                    show: function(event, ui) {
                        //expire tab cookie in 30 minutes
                        var edate = new Date();
                        var minutes = 30;
                        edate.setTime(edate.getTime() + (minutes * 60 * 1000));
                        var tabname = $(ui.tab).html()
                        $.cookie(cookieid, tabname, {
                            expires: edate
                        });
                    },
                });
                var tabs_tmp = $(tabsid + ' li');
                $.each(tabs_tmp, function(i, val) {
                    if($(val).find('a').html() == $.cookie(cookieid)) {
                        $(tabsid).tabs("select", i);
                    }
                    //console.log();
                });
                
            }
        }
    }
}(jQuery));
