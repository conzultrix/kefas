<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Kefas theme.
 */

// Remove Height and Width from Drupal Images
function kefas_preprocess_image(&$variables) {
  foreach (array('width', 'height') as $key) {
    unset($variables[$key]);
  }
}