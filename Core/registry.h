/**
 * \file registry.h
 */

#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <string>

#include "TGSE_Core_config.h"

namespace TGSE
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
    TGSE_Core_EXPORT static Registry& get();

    TGSE_Core_EXPORT void set_function(const std::string& name, RegistryFunction function);
    TGSE_Core_EXPORT RegistryFunction get_function(const std::string& name) const;
  };

  class RegistryLoader
  {
  public:
    TGSE_Core_EXPORT RegistryLoader(const std::string& name, Registry::RegistryFunction function);
  };
}

#define TGSEEXPORTPLUGIN(name, function) \
  TGSE::RegistryLoader registry_loader##name( #name, function);

#endif
