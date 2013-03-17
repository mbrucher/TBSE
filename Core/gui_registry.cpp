/**
 * \file gui_registry.cpp
 */

#include <iostream>
#include <stdexcept>

#include "gui_registry.h"

namespace TBSE
{
  template<>
  GUIRegistry& GUIRegistry::get()
  {
    static GUIRegistry registry;
    return registry;
  }
}
