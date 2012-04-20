/**
 * \file registry.h
 */

#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <string>

#include "TBSE_Core_config.h"

namespace TBSE
{
  class Registry
  {
    Registry();
  public:
    typedef void (*RegistryFunction)();
  private:
    typedef std::map<std::string, RegistryFunction> RegistryInnerType;
    RegistryInnerType registry;
  public:
    TBSE_Core_EXPORT static Registry& get();

    TBSE_Core_EXPORT void set_function(const std::string& name, RegistryFunction function);
    TBSE_Core_EXPORT RegistryFunction get_function(const std::string& name) const;
  };

  class RegistryLoader
  {
  public:
    TBSE_Core_EXPORT RegistryLoader(const std::string& name, Registry::RegistryFunction function);
  };
}

#define TBSEEXPORTPLUGIN(name, function) \
  TBSE::RegistryLoader registry_loader##name( #name, function);

#endif
