<?php

/**
 * Implements hook_preprocess_html().
 */
function kefas_preprocess_html(&$variables) { //dpm($variables);
  // if stack_first and stack_second are
  // not empty, add class stack-both to body
  if (!empty($variables['page']['stack_first']) && !empty($variables['page']['stack_second'])) {
    $variables['classes_array'][] = 'stack-both';
  }
  
  $postscript_first = !empty($variables['page']['postscript_first']);
  $postscript_second = !empty($variables['page']['postscript_second']);
  $postscript_third = !empty($variables['page']['postscript_third']);
  
  $postscripts = _kefas_body_class_prefix($postscript_first, $postscript_second, $postscript_third);
  
  switch ($postscripts) {
    case 'three':
      $variables['classes_array'][] = 'three-postscripts';
      break;
    
    case 'two':
      $variables['classes_array'][] = 'two-postscripts';
      $variables['classes_array'][] = 'postscript-' . _kefas_last_region($postscript_second, $postscript_third) . '-last';
      break;
  }
  
  // Footertop region
  $ft_first = !empty($variables['page']['footertop_first']);
  $ft_second = !empty($variables['page']['footertop_second']);
  $ft_third = !empty($variables['page']['footertop_third']);
  
  $footertops = _kefas_body_class_prefix($ft_first, $ft_second, $ft_third);
  
  switch ($footertops) {
    case 'three':
      $variables['classes_array'][] = 'three-footertops';
      break;
    
    case 'two':
      $variables['classes_array'][] = 'two-footertops';
      $variables['classes_array'][] = 'footertop-' . _kefas_last_region($ft_second, $ft_third) . '-last';
      if ($ft_second && $ft_third) {
        $variables['classes_array'][] = 'footertop-second-third';
      }
      break;
  }
  
}

function _kefas_body_class_prefix($first, $second, $third) {
  if ($first && $second && $third) {
    return 'three';
  }
  
  if (($first && $second) || ($first && $third) || ($second && $third)) {
    return 'two';
  }
  
  return FALSE;
}

function _kefas_last_region($second, $third) {
  return $third ? 'third' : 'second';
}