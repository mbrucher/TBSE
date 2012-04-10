/**
 * \file main.cpp
 */

#include <cstdlib>

#include "Core/plugin.h"
#include "Core/main_registry.h"

int main(int argc, char** argv)
{
  TBSE::visit_all_plugin_paths();

  return (*TBSE::MainRegistry::get().get_function("2DGUI"))(argc, argv);
}
