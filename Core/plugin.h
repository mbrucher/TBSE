/**
 * \file plugin.h
 */

#ifndef PLUGIN_H
#define PLUGIN_H

#include "TBSE_Core_config.h"

namespace TBSE
{
  /// Function to load all plugins in TBSEPLUGINPATH
  TBSE_Core_EXPORT void visit_all_plugin_paths();
}

#endif
