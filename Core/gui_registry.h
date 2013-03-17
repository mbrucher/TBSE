/**
 * \file gui_registry.h
 */

#ifndef GUI_REGISTRY_H
#define GUI_REGISTRY_H

#include "template_registry.h"

class QWidget;

namespace TBSE
{
  /// A registry for GUI plugins
  typedef Registry<QWidget* (*)(QWidget*)> GUIRegistry;
  /// The class that can auto-register a plugin
  typedef RegistryLoader<GUIRegistry> GUIRegistryLoader;
}

#define TBSEEXPORTGUIPLUGIN(name, function) \
  TBSE::GUIRegistryLoader guiRegistryLoader##name( #name, function);

#endif
