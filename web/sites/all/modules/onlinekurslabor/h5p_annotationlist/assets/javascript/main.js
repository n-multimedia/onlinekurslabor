
(function($) {
    Drupal.behaviors.h5p_annotationlist = {
        attach: function(context, settings) {


        },
        video_object_list: [], // new Array(),
        annotations_sortby: ['start', 'end', 'interactiontype', 'title'],
        annotations_sortby_label: ['Start', 'Ende', 'Typ', 'Titel'],
        /*attach: function (context, settings) {
         // Your Javascript code goes here
         
         },*/

        /*Klassendefinition fuer ein gespeichertes Videoobjekt*/
        video_object: function(object_g, container_g) {

            this.container = container_g;
            this.object = object_g;
            //console.debug(this);
        },
        getAllVideoObjects: function()
        {
            return this.video_object_list;
        },
        /*parameter darf entweder ein video_object oder ein container sein*/
        findVideoObject: function(parameter)
        {
            var list = this.getAllVideoObjects();
            jQuery.each(list, function(index, item) {
                if (item.container == parameter || item.object == parameter)
                    return item;

            });

        },
        /*video_object ist vom Typ {container, parameter}*/
        addVideoContainerObjectToList: function(video_object)
        {
            this.video_object_list.push(video_object);
            return 	this.video_object_list.length;
        },
        /*object: h5p-interaction-objekt; container: jQuery-Objekt*/
        addVideoObjectToList: function(object, container)
        {
            var video_object = new Drupal.behaviors.h5p_annotationlist.video_object(object, container);
            this.video_object_list.push(video_object);
            return 	this.video_object_list.length;
        },
        /*
         save_video_objects: ueberscrheibt temporär die funktion  H5P.InteractiveVideo.prototype.attach um sich einklinken zu koennen. führt die originalversion anschließend aus.
         */
        save_video_objects: function()
        {
            //console.debug("doing");

            var saved_object = null;
            if (typeof H5P === 'undefined')
                return false;
            if (typeof H5P.InteractiveVideo === 'undefined')
                return false;

            //speichere Originalfunktionsaufruf
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
        addSideBarToVideoObject: function(video_object)
        {
            var the_great_list;
            jQuery.each(H5PIntegration.contents, function(json_video_id, some_video_object)
            {
                //console.debug(json_video_id);
                //console.debug(some_video_object);


                the_great_list =
                        '<div id="h5p_annotationlist_' + json_video_id + '" class="h5p_annotationlist">' +
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
                /*sidebar in seite einfügen*/
                if (video_object.container.parents(".embeded_h5p")[0])
                { //fall video in seite eingebettet
                    video_object.container.parents(".embeded_h5p").first().append(the_great_list);
                }
                else
                { //fall view interactive content
                    video_object.container.after(the_great_list);
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
                Drupal.behaviors.h5p_annotationlist.addAnnotationsToSidebar(json_video_id, null, video_object);

            });




        },
        /*fuegt dem container '#h5p_annotationlist_'+json_video_id  eine liste der annotationen hinzu*/
        addAnnotationsToSidebar: function(json_video_id, sortby, video_object)
        {
            if (!sortby || !this.annotations_sortby.indexOf(sortby))
                sortby = "start";

            var sidebar_div = jQuery('#h5p_annotationlist_' + json_video_id);
            /*setze korrekten wert in der sortierliste*/
            sidebar_div.find('.sort_container').find('input[name="annotations_sortby"][value="' + sortby + '"]').attr('checked', 'checked');
            /*Setze Verhalten des Sortierers*/
            sidebar_div.find('.sort_container').find('input[name="annotations_sortby"]').change(function() {
                Drupal.behaviors.h5p_annotationlist.addAnnotationsToSidebar(json_video_id, jQuery(this).attr("value"), video_object);
            });
            /*extrahiere annotationsdaten*/
            var videojson = (H5PIntegration.contents[json_video_id]);

            if (videojson !== undefined)
            {
                videojson = videojson['jsonContent'];
            }
            else
            {
                //console.log('ERROR: Sorry, but no annotations could be found.');
                return;
            }

            /*extrahiere annotationsdaten und sortiere diese*/
            var videojsonparsed = jQuery.parseJSON(videojson);
            var all_interactions = videojsonparsed.interactiveVideo.interactions;
            all_interactions.sort(this.SortfunctionForAnnotations(sortby));


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
                if (typeof item_label === 'undefined')
                    item_label = '  ';
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
            //haenge html an
            sidebar_div.find("div.h5p_annotationlist_annotation_container").html(new_annotation_html);
            var total_width = sidebar_div.find("div.h5p_annotationlist_annotation_item").width() * all_interactions.length;

            sidebar_div.find("div.h5p_annotationlist_annotation_container_nowrap").css('width', total_width * 1.2);
            //mache nun die zeitmarken in der annotationsliste anspringbar
            Drupal.behaviors.h5p_annotationlist.convertElementToVideoSeekable('#h5p_annotationlist_' + json_video_id, video_object);
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
            var click_delay = 100;

            jQuery(HTML_Selector).find("a[data]").click(function()
            {
                value_to_jump_to = jQuery(this).attr("data");
                video_object.object.video.seek(value_to_jump_to);

                //wenn video schon abspielt muss man keinen klick simulieren. sonst schon.
                if (!video_object.object.video.isPlaying())
                {

                    //ist auf pause, auf play setzen (pause bedeutet, video ist pausiert, bei klick startets wieder)
                    setTimeout(function() {
                        jQuery(video_object.container).find(".h5p-pause")[0].click();
                    }, click_delay);
                    //und wieder auf pause (viceversa))
                    setTimeout(function() {
                        //ist NICHT pausiert, dann auf Pause drücken
                        if (jQuery(video_object.container).find(".h5p-pause").length == 0)
                        {
                            jQuery(video_object.container).find(".h5p-play")[0].click();
                        }

                    }, click_delay * 2);
                }


                return false;
            });
        }
    }
}(jQuery));

jQuery(document).ready(function() {
    Drupal.behaviors.h5p_annotationlist.save_video_objects();
//Drupal.behaviors.h5p_annotationlist.addSideBar( Drupal.behaviors.h5p_annotationlist.getAllVideoObjects());
});

/*String-Funktion: entferne leerzeichen punkte etc*/
String.prototype.removeeverythingbutchars = function() {
    return this.replace(/[ .]/g, "").toLowerCase();
    ;
}
