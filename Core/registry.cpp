/**
 * \file registry.cpp
 */

#include <iostream>
#include <stdexcept>

#include "registry.h"

namespace TGSE
{
  Registry& Registry::get()
  {
    static Registry registry;
    return registry;
  }

  Registry::Registry()
  {
  }

  void Registry::set_function(const std::string& name, RegistryFunction function)
  {
    std::cout << "Discovered plugin " << name << std::endl;
    registry[name] = function;
  }

  Registry::RegistryFunction Registry::get_function(const std::string& name) const
  {
    RegistryInnerType::const_iterator it = registry.find(name);
    if (it == registry.end())
    {
      throw std::runtime_error("No such loaded plugins");
    }
    return it->second;
  }

  RegistryLoader::RegistryLoader(const std::string& name, Registry::RegistryFunction function)
  {
    Registry::get().set_function(name, function);
  }
}
