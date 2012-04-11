/**
 * \file main_registry.cpp
 */

#include <iostream>
#include <stdexcept>

#include "main_registry.h"

namespace TBSE
{
  MainRegistry& MainRegistry::get()
  {
    static MainRegistry registry;
    return registry;
  }

  MainRegistry::MainRegistry()
  {
  }

  void MainRegistry::set_function(const std::string& name, MainRegistryFunction function)
  {
    std::cout << "Discovered plugin " << name << std::endl;
    registry[name] = function;
  }

  MainRegistry::MainRegistryFunction MainRegistry::get_function(const std::string& name) const
  {
    MainRegistryInnerType::const_iterator it = registry.find(name);
    if (it == registry.end())
    {
      throw std::runtime_error("No such loaded plugins");
    }
    return it->second;
  }

  MainRegistryLoader::MainRegistryLoader(const std::string& name, MainRegistry::MainRegistryFunction function)
  {
    MainRegistry::get().set_function(name, function);
  }

  std::list<std::string> MainRegistry::get_plugins() const
  {
    std::list<std::string> names;

    for(MainRegistryInnerType::const_iterator it = registry.begin(); it != registry.end(); ++it)
    {
      names.push_back(it->first);
    }

    return names;
  }
}
