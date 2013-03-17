/**
 * \file main.cpp
 */

#include <cstdlib>

#include "Core/plugin.h"
#include "GUI/main.h"

int main(int argc, char** argv)
{
  TBSE::visit_all_plugin_paths();

  return TBSE::GUI::main(argc, argv);
}
