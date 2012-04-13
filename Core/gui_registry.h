/**
 * \file gui_registry.h
 */

#ifndef GUI_REGISTRY_H
#define GUI_REGISTRY_H

#include "template_registry.h"

class QWidget;

namespace TBSE
{
  typedef Registry<QWidget* (*)(QWidget*)> GUIRegistry;
  typedef RegistryLoader<GUIRegistry> GUIRegistryLoader;
}

#define TBSEEXPORTGUIPLUGIN(name, function) \
  TBSE::GUIRegistryLoader gui_registry_loader##name( #name, function);

#endif
