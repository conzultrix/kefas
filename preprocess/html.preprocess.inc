<?php

/**
 * Implements hook_preprocess_html().
 */
function kefas_preprocess_html(&$variables) {
  //dpm($variables);
  // if postscript_first and postscript are
  // not empty, add class postscript-both to body
  if (!empty($variables['page']['postscript_first']) && !empty($variables['page']['postscript_second'])) {
    $variables['classes_array'][] = 'postscript-both';
  }
}