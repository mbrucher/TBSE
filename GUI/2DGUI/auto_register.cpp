/**
 * \file auto_register.cpp
 */

#include "../../Core/gui_registry.h"

#include "scene_model.h"

QWidget* create_widgets(QWidget* parent)
{
  return NULL;
}

TBSEEXPORTGUIPLUGIN(2DGUI, create_widgets);
