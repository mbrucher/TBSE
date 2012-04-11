/**
 * \file main_registry.h
 */

#ifndef MAIN_REGISTRY_H
#define MAIN_REGISTRY_H

#include <list>
#include <map>
#include <string>

#include "TBSE_Core_config.h"

namespace TBSE
{
  class MainRegistry
  {
    MainRegistry();
  public:
    typedef int (*MainRegistryFunction)(int& argc, char** argv);
  private:
    typedef std::map<std::string, MainRegistryFunction> MainRegistryInnerType;
    MainRegistryInnerType registry;
  public:
    TBSE_Core_EXPORT static MainRegistry& get();

    TBSE_Core_EXPORT void set_function(const std::string& name, MainRegistryFunction function);
    TBSE_Core_EXPORT MainRegistryFunction get_function(const std::string& name) const;
    TBSE_Core_EXPORT std::list<std::string> get_plugins() const;
  };

  class MainRegistryLoader
  {
  public:
    TBSE_Core_EXPORT MainRegistryLoader(const std::string& name, MainRegistry::MainRegistryFunction function);
  };
}

#define TBSEEXPORTMAINPLUGIN(name, function) \
  TBSE::MainRegistryLoader main_registry_loader##name( #name, function);

#endif
