/**
 * \file main_registry.h
 */

#ifndef MAIN_REGISTRY_H
#define MAIN_REGISTRY_H

#include "TBSE_Core_config.h"
#include "template_registry.h"

namespace TBSE
{
  typedef Registry<int (*)(int& argc, char** argv)> MainRegistry;
  typedef RegistryLoader<MainRegistry> MainRegistryLoader;
}

#define TBSEEXPORTMAINPLUGIN(name, function) \
  TBSE::MainRegistryLoader main_registry_loader##name( #name, function);

#endif
