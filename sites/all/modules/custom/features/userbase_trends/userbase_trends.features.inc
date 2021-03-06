<?php
/**
 * @file
 * userbase_trends.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function userbase_trends_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function userbase_trends_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function userbase_trends_flag_default_flags() {
  $flags = array();
  // Exported flag: "Collect Points".
  $flags['collect_points'] = array(
    'entity_type' => 'node',
    'title' => 'Collect Points',
    'global' => 0,
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => 'Collect Points',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unredeem points',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Points Collected',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 1,
    'module' => 'userbase_trends',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function userbase_trends_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like Trends, news, press releases, blog posts...'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
