/**
 * \file main_registry.h
 */

#ifndef MAIN_REGISTRY_H
#define MAIN_REGISTRY_H

#include <map>
#include <string>

#include "TGSE_Core_config.h"

namespace TGSE
{
  class MainRegistry
  {
    MainRegistry();
  public:
    typedef void (*MainRegistryFunction)();
  private:
    typedef std::map<std::string, MainRegistryFunction> MainRegistryInnerType;
    MainRegistryInnerType registry;
  public:
    TGSE_Core_EXPORT static MainRegistry& get();

    TGSE_Core_EXPORT void set_function(const std::string& name, MainRegistryFunction function);
    TGSE_Core_EXPORT MainRegistryFunction get_function(const std::string& name) const;
  };

  class MainRegistryLoader
  {
  public:
    TGSE_Core_EXPORT MainRegistryLoader(const std::string& name, MainRegistry::MainRegistryFunction function);
  };
}

#define TGSEEXPORTMAINPLUGIN(name, function) \
  TGSE::MainRegistryLoader main_registry_loader##name( #name, function);

#endif
