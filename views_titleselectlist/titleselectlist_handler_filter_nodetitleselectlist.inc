<?php

class titleselectlist_handler_filter_nodetitleselectlist extends views_handler_filter_many_to_one {

  function value_form(&$form, &$form_state) {
    $options = array();
    if ($form_state['form_id'] != 'views_ui_config_item_form') {
      static $called = 0;
      if ($called === $form['#id']) {
        return;
      }
      $called = $form['#id']; // flag as called
      $base_view = views_get_current_view();
      $display_id = $base_view->current_display;
      $view = views_get_view($base_view->name);
      $view->set_display($display_id);
      $view->pre_execute();
      $view->execute($display_id);
      $view_result = $view->result;
      $options = array();
      foreach ($view_result as $node) {
        if (!array_key_exists($node->nid, $options)) {
          $options[$node->nid] = $node->node_title;
        }
      }
      asort($options);
    }
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Node Title'),
      '#multiple' => TRUE,
      '#size' => 10,
      '#options' => $options,
    );

    return $form['value'];
  }

}
