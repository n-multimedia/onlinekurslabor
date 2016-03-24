
(function($) {
    Drupal.behaviors.h5p_annotationlist = {
        attach: function(context, settings) {
 
        },
         
        annotations_sortby: ['start', 'end', 'interactiontype', 'title'],
        annotations_sortby_label: ['Start', 'Ende', 'Typ', 'Titel'],
        /*attach: function (context, settings) {
         // Your Javascript code goes here
         
         },*/

          
        /*
         save_video_objects: ueberscrheibt temporär die funktion  H5P.InteractiveVideo.prototype.attach um sich einklinken zu koennen. führt die originalversion anschließend aus.
         */
        save_video_objects: function()
        { 
           
             if (typeof H5P === 'undefined' || typeof(H5PIntegration) === 'undefined' || typeof H5P.InteractiveVideo === 'undefined')
                return false;
          
              /*
               * 
               * ggf bei neuen versionen anpassen, ist das js-objekt des original-h5p-plugins
               * 
               * 
               */
              this.h5p_data_container = H5PIntegration.contents;
            

            var saved_object = null;
           
            var originalInteractiveVideoPrototypeAttachMethod = H5P.InteractiveVideo.prototype.attach;
            //Ueberschreibe original Funktionsaufruf
            H5P.InteractiveVideo.prototype.attach = function()
            {
                //Schreibe Object in Array
                var video_object = new Drupal.behaviors.h5p_annotationlist.video_object(this, arguments[0]);

                //speichert videoobjekt in einer liste
                Drupal.behaviors.h5p_annotationlist.addVideoContainerObjectToList(video_object);
                //fuegt dem videoobjekt eine sidebar hinzu
                Drupal.behaviors.h5p_annotationlist.addSideBarToVideoObject(video_object)


                //Rufe Originalfunktion auf
                var result = originalInteractiveVideoPrototypeAttachMethod.apply(this, arguments);
                return result;
            }

        },
        /*fuegt neben ein videoobjekt auf der webseite einen html-schnipsel ein, in dem spaeter eine liste der annotationen auftaucht*/
        attachSideBarToInteractiveVideo: function()
        {
            var video = Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P();

            the_great_list =
                    '<div id="h5p_annotationlist_' + video.contentId + '" class="h5p_annotationlist" style="display:none;">' +
                    '<div class="sort_region">' +
                    '<a href=# title="Sortieren" class="sort_label fa fa-sort fa-1"><span class=""></span></a><div class="sort_container">Sortieren nach<br>';

            /*sortierfunktion einbauen*/
            jQuery.each(Drupal.behaviors.h5p_annotationlist.annotations_sortby, function(index, item)
            {
                the_great_list += '<input type=radio name=annotations_sortby value="' + item + '">&nbsp;' +
                        Drupal.behaviors.h5p_annotationlist.annotations_sortby_label[index] + '</input><br>';
                //'<label for="'+item+'">'+ Drupal.behaviors.h5p_annotationlist.annotations_sortby_label[index]+'</label>';
            });
            the_great_list += '</div>' +
                    '</div>'; //sortregion

            the_great_list += '<div class="h5p_annotationlist_annotation_container"></div> </div><div style="clear:both;"></div>';
            /*eingebettetes h5p*/
            if (video.$container.prevObject.parents(".embeded_h5p")[0])
            { //fall video in seite eingebettet
                video.$container.prevObject.parents(".embeded_h5p").first().append(the_great_list);
            }
            else
            { //fall view interactive content ohne einbettung
                video.$container.prevObject.after(the_great_list);

            }


            /*oeffnen & schliessen sortierung*/
            jQuery("body *").click(function() {
                jQuery(".sort_container").slideUp(200);
            });
            jQuery('a.sort_label').click(function() {
                var that = this;
                setTimeout(function() {
                    jQuery(that).parent().find(".sort_container:hidden").slideDown(200);
                }, 200);
                return false;
            });

            //letztendlich schreibe die annotationen in die neue sidebar.
            Drupal.behaviors.h5p_annotationlist.addAnnotationsToSidebar(null);



        },
        /*fuegt dem container '#h5p_annotationlist_'+json_video_id  eine liste der annotationen hinzu*/
        addAnnotationsToSidebar: function( sortby)
        {
            var video =  Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P();
                    
            if (!sortby || !this.annotations_sortby.indexOf(sortby))
                sortby = "start";

            var sidebar_div = jQuery('#h5p_annotationlist_' + video.contentId);
            /*setze korrekten wert in der sortierliste*/
            sidebar_div.find('.sort_container').find('input[name="annotations_sortby"][value="' + sortby + '"]').attr('checked', 'checked');
            /*Setze Verhalten des Sortierers*/
            sidebar_div.find('.sort_container').find('input[name="annotations_sortby"]').change(function() {
                Drupal.behaviors.h5p_annotationlist.addAnnotationsToSidebar( jQuery(this).attr("value"));
            });
            
            var all_interactions = Drupal.behaviors.h5p_connector_api.interactivevideo.getAllAnnotations();
            if (all_interactions == null || all_interactions.length == 0)
            	return false;
            all_interactions.sort(this.SortfunctionForAnnotations(sortby));
	//console.debug(all_interactions);

            var new_annotation_html = "";
            var new_annotation_template;

            new_annotation_template =
                    '<div class="h5p_annotationlist_annotation_item annotation_%s">' +
                    '<div class="interaction_icon">' +
                    '<a href=# data="%s" class="interaction_icon_%s fa fa-inverse  fa-1">' +
                    '</a>' +
                    '</div>' +
                    '<div class="interaction_content">' +
                    '<h3><a href=# data="%s">%s&nbsp;</a></h3>' +
                    '<span class="duration"><a href=# data="%s">%s</a>&nbsp;-&nbsp;<a href=# data="%s">%s</a></span>' +
                    '</div>' +
                    '</div>';
            var item_label;
            jQuery.each(all_interactions, function(index, item) {
                item_label = item.label;
                if ((typeof item_label === 'undefined') || item_label.length === 0 )
                {
                    item_label = '- ohne -';
                }
                //entferne formatierungen
                item_label = item_label.replace(/<[^>]*>?/g, '');
                /*fuelle das oben definierte HTMl-Template mit den echten Daten*/
                var annotation_type_minimized = item.action.library.removeeverythingbutchars();
                new_annotation_html += sprintf(new_annotation_template,
                        annotation_type_minimized,
                        item.duration.from,
                        annotation_type_minimized,
                        item.duration.from,
                        item_label,
                        item.duration.from,
                        H5P.InteractiveVideo.humanizeTime(item.duration.from),
                        item.duration.to,
                        H5P.InteractiveVideo.humanizeTime(item.duration.to)
                        );


            });
            new_annotation_html = '<div class="h5p_annotationlist_annotation_container_nowrap">' + new_annotation_html + '</div>'
            //offenbar haben wir annotationen, also setzen wir die liste auf visible
            sidebar_div.css('display','block');
            //haenge html an
            sidebar_div.find("div.h5p_annotationlist_annotation_container").html(new_annotation_html);
            var total_width = sidebar_div.find("div.h5p_annotationlist_annotation_item").width() * all_interactions.length;

            sidebar_div.find("div.h5p_annotationlist_annotation_container_nowrap").css('width', total_width * 1.2);
            //mache nun die zeitmarken in der annotationsliste anspringbar
            Drupal.behaviors.h5p_annotationlist.convertElementToVideoSeekable('#h5p_annotationlist_' + video.contentId, video);
            if (all_interactions.length === 0)
            {
                sidebar_div.find("div.h5p_annotationlist_annotation_container").html('<i>Keine Annotationen vorhanden</i>');
            }

        },
        /*sortierfunktion: wird benoetigt, um das array von annotationen zu sortieren*/
        SortfunctionForAnnotations: function(sortby_what)
        {
            //sortierung nacgh beginn
            if (sortby_what == 'start')
            {
                return function(a, b) {
                    return a.duration.from - b.duration.from;
                }
            }
            //sortierung nach endzeitpunkt
            else if (sortby_what == 'end')
            {
                return function(a, b) {

                    return a.duration.to - b.duration.to;
                }
            }
            //sortierung nach typ
            else if (sortby_what == 'interactiontype')
            {
                return function(a, b) {
                    return (a.action.library).localeCompare(b.action.library);
                }
            }
            //sortierung nach title, großkleinschreibung egal
            else if (sortby_what == 'title')
            {
                return function(a, b) {
                    if (typeof a.label !== 'undefined' && typeof b.label !== 'undefined')
                    {
                        return (a.label.toLocaleLowerCase()).localeCompare(b.label.toLocaleLowerCase());
                    }
                    else {
                        if (typeof a.label === 'undefined')
                            return -1;
                        else
                            return 1;
                    }
                }
            }

        }
        ,
        /*wenn man auf eine annotation klickt soll man auch an die stelle im video springen*/
        convertElementToVideoSeekable: function(HTML_Selector, video_object) {
            var value_to_jump_to;
           
						
            jQuery(HTML_Selector).find("a[data]").click(function()
            {
                value_to_jump_to = jQuery(this).attr("data");
                Drupal.behaviors.h5p_connector_api.interactivevideo.goTo(value_to_jump_to);
                 
                return false;
            });
        } 
    }
}(jQuery));

jQuery(document).ready(function() {
//jQuery.proxy(Drupal.behaviors.h5p_annotationlist.save_video_objects, Drupal.behaviors.h5p_annotationlist  
Drupal.behaviors.h5p_connector_api.onH5Pready(function(){Drupal.behaviors.h5p_annotationlist.attachSideBarToInteractiveVideo();});
//Drupal.behaviors.h5p_annotationlist.addSideBar( Drupal.behaviors.h5p_annotationlist.getAllVideoObjects());
});

/*String-Funktion: entferne leerzeichen punkte etc*/
String.prototype.removeeverythingbutchars = function() {
    return this.replace(/[ .]/g, "").replace(/[0-9](?!p)/ig, "").toLowerCase();
    ;
}
