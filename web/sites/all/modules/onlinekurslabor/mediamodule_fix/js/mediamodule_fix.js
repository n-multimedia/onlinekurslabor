/**
 *  @file
 *  fixes  media in html editing.
 */
(function($) {

    /**
     * Utility to deal with media tokens / placeholders.
     */
    Drupal.behaviors.mediamodule_fix = {
        /**
         * adds additional html to original function getWysiwygHTML
         * @param content
         */
        attach: function(context, settings) {
            //typprüfung, ob plugin benötigt
            if (typeof Drupal.media !== "undefined" && typeof Drupal.media.filter !== "undefined")
            {
                var old_getWysiwygHTML_function = Drupal.media.filter.getWysiwygHTML;
                Drupal.media.filter.getWysiwygHTML = function(element)
                {   //problem: in der originalfunktion ist nach dem span-tag kein separator. ckeditor verschluckt sich dann nach enter.
                    //  folge: Nach File-Upload wird nachfolgender Text in eine File-Verlinkung konvertiert
                    //prinzipiell verantwortlich ist https://dev.ckeditor.com/ticket/6955 => begründung https://www.drupal.org/node/2153851#comment-8697585
                    return old_getWysiwygHTML_function(element) + "&nbsp;" + "<br>";
                }
            }


        }
    }

})(jQuery);

 