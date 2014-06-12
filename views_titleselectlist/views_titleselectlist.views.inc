<?php

/**
 * Implements hook_views_data().
 */
function views_titleselectlist_views_data() {
  $data = array();
  $data['node']['node_title'] = array(
    'title' => t('Title Select List'),
    'help' => t('Displays a select list of Node Titles from current view. It must be exposed to work.'),
    'real field' => 'nid',
    'group' => t('Node'),
    'filter' => array(
      'handler' => 'titleselectlist_handler_filter_nodetitleselectlist',
      'many to one' => TRUE,
    ),
  );
  return $data;
}

/**
 * Implement hook_views_handlers().
 */
function views_titleselectlist_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_titleselectlist')
    ),
    'handlers' => array(
      'titleselectlist_handler_filter_nodetitleselectlist' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ), // The name of the handler we are extending. 
    ),
  );
}
