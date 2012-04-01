/**
 * \file main.cpp
 */

#include <cstdlib>

#include "Core/plugin.h"

int main(int argc, char** argv)
{
  TBSE::visit_all_plugin_paths();

  return EXIT_SUCCESS;
}
