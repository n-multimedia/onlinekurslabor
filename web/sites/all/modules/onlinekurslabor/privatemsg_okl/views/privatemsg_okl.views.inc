<?php

/**
 * Implements hook_views_data().
 * Für Informationen siehe
 *  https://api.drupal.org/api/views/handlers!views_handler_field.inc/group/views_field_handlers/7.x-3.x
 * https://api.drupal.org/api/views/handlers!views_handler_sort.inc/group/views_sort_handlers/7.x-3.x
 * http://www.mydons.com/how-to-expose-custom-module-table-to-views-in-drupal/
 * http://stackoverflow.com/questions/3544380/exposing-a-table-to-views
 */

/**
 * hook_views_data()
 * Definition von durch views nutzbare Datenbanktabellen
 * @return array
 */
function privatemsg_okl_views_data() {
// siehe https://www.sitepoint.com/exposing-tables-views-drupal-7/ fuer basic info und 
    // und 
    // fuer joins
    $data = array();
    //pm_index: die tabelle1
    $data['pm_index']['table']['group'] = t('Private messages');

    $data['pm_index']['table']['base'] = array(
        //das erscheint in der view-ansicht neben bspw. node
        'title' => t('Private messages List'),
        'help' => t('Load private messages to expose to Views.'),
    );
    //da im index nicht alle daten vorhanden, joinen wir auf pm_message wobei pm_index.mid = pm_message.mid
    $data['pm_index']['join'] = array(
        // to join to pm_message, we'll use a field in modulename_table called 'mid'
        'pm_message' => array(
            'left_field' => 'mid',
            'field' => 'mid',
    ));

    $data['pm_index']['mid'] = array(
        'title' => 'mid',
        'help' => 'the message id in table {pm_message}',
        'field' => array(
            'handler' => 'views_handler_field',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'argument' =>
        array(
            'handler' => 'views_handler_argument_numeric',
            'numeric' => TRUE,
            'validate type' => 'mid',
        ),
        // here we implement a relationship to mid
        //to the other pm-table
        //you need to add this relationship in your view.
        'relationship' => array(
            'base' => 'pm_message',
            //field: auf pm_index
            'field' => 'mid',
            'handler' => 'views_handler_relationship',
            'label' => 'relationship to pm_message',
            //field auf pm_message
            'base field' => 'mid',
        ),
            // this relationship can be turned on in views
    );
    // now we define the fields in the table like this
    // check out modules/views/handlers to see more specific handlers
    //db-field is_new fuer ungelesen
    $data['pm_index']['is_new'] = array(
        'title' => 'is_new',
        'help' => 'true: message hasn\'t been read',
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'field' => array(
            'handler' => 'views_handler_field_numeric',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    //db-feld thread_id
    $data['pm_index']['thread_id'] = array(
        'title' => 'thread_id',
        'help' => 'if there are multiple messages between two people they can be threaded',
        'field' => array(
            'handler' => 'views_handler_field_numeric',
        ),
    );

    //db-feld deleted fuer geloeschte nachrichten
    $data['pm_index']['deleted'] = array(
        'title' => 'deleted',
        'help' => 'deleted: timestamp or zero if not deleted',
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'field' => array(
            'handler' => 'views_handler_field_numeric',
        ),
    );

    //db-feld empfaenger
    $data['pm_index']['recipient'] = array(
        'title' => 'recipient',
        'help' => 'the recipient\'s ID',
        'field' => array(
            'handler' => 'views_handler_field_numeric',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'argument' =>
        array(
            'handler' => 'views_handler_argument_user_uid',
            'numeric' => TRUE,
            'validate type' => 'recipient',
        ),
    );

   /**
    * 
    *
    *   jetzt kommen definitionen zur tabelle pm_message, auf die wir ganz am anfang gejoined haben 
    * 
    */
    $data['pm_message']['table']['group'] = t('Private messages');

    //timestamp der nachricht
    $data['pm_message']['timestamp'] = array(
        'title' => 'timestamp',
        'help' => 'The date this message was sent',
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
        'field' => array(
            'handler' => 'views_handler_field_date',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort_date',
        ),
    );
//subject der nachricht
    $data['pm_message']['subject'] = array(
        'title' => 'Subject',
        'help' => 'subject of the message',
        'field' => array(
            'handler' => 'views_handler_field',
        ),
    );

//body der nachrciht
    $data['pm_message']['body'] = array(
        'title' => 'Message content',
        'help' => 'content of the message',
        'field' => array(
            'handler' => 'views_handler_field_markup',
        ),
    );
    
//author der nachricht. um auf den author im view zuzugreifen, muss man unter relationship eine weitere
//auf user einrichten. die kann dann dieses feld nutzen.
//auf diese art kann man dann auf email und nutzername etc zugreifen
    $data['pm_message']['author'] = array(
        'title' => 'Author',
        'help' => 'Sender of the message (uid)',
        'field' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'argument' =>
        array(
            'handler' => 'views_handler_argument_user_uid',
            'numeric' => TRUE,
            'validate type' => 'author',
        ),
        // here we implement a relationship from the author-uid in pm_index to the user-table
        'relationship' => array(
            'base' => 'users',
            //field: auf pm_index
            'field' => 'author',
            'handler' => 'views_handler_relationship',
            'label' => 'relationship from pm_message (author) to user',
            //field auf user
            'base field' => 'uid',
        ),
            // this relationship can be turned on in views
    );


 
    return $data;
}
