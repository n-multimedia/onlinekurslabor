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
                    activate:function(event,ui){
                        var edate = new Date();
 												//expire tab cookie in 30 minutes
                        edate.setTime(edate.getTime() + (30 * 60 * 1000));
                        var tabname = jQuery(ui.newTab.context).html();
                        if(typeof tabname === null)
                       	 throw new Error('Selected tab could not be found in /sites/all/themes/bootstrap_onlinekurslabor/js/tabcookie')
                       	 else
                       	 {
                       	     $.cookie(cookieid, tabname, {
                        		    expires: edate
                     			   });
													}
                    
                    },
                });
                var tabs_tmp = $(tabsid + ' li');
                $.each(tabs_tmp, function(i, val) {
                    if($(val).find('a').html() == $.cookie(cookieid)) {
                        $(tabsid).tabs( "option", "active", i);
                    }
                });
                
            }
        }
    }
}(jQuery));
