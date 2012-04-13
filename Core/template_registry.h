/**
 * \file template_registry.h
 */

#ifndef TEMPLATE_REGISTRY_H
#define TEMPLATE_REGISTRY_H

#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>

#include "TBSE_Core_config.h"

namespace TBSE
{
  template<class RegistryFunction_>
  class Registry
  {
    Registry()
    {
    }
  public:
    typedef RegistryFunction_ RegistryFunction;
  private:
    typedef std::map<std::string, RegistryFunction> RegistryInnerType;
    RegistryInnerType registry;
  public:
    TBSE_Core_EXPORT static Registry& get();

    void setFunction(const std::string& name, RegistryFunction function)
    {
      std::cout << "Discovered plugin " << name << std::endl;
      registry[name] = function;
    }

    RegistryFunction getFunction(const std::string& name) const
    {
      RegistryInnerType::const_iterator it = registry.find(name);
      if (it == registry.end())
      {
        throw std::runtime_error("No such loaded plugins");
      }
      return it->second;
    }

    std::list<std::string> getPlugins() const
    {
      std::list<std::string> names;

      for(RegistryInnerType::const_iterator it = registry.begin(); it != registry.end(); ++it)
      {
        names.push_back(it->first);
      }

      return names;
    }
  };

  template<class Registry>
  class RegistryLoader
  {
  public:
    RegistryLoader(const std::string& name, typename Registry::RegistryFunction function)
    {
      Registry::get().setFunction(name, function);
    }
  };
}

#endif
