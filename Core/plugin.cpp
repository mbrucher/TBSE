/**
 * \file plugin.cpp
 */

#include <iostream>
#include <string>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include "plugin.h"

namespace TBSE
{
  /// Function to load all plugins in a specific path
  void visit_plugin_path(const std::string& path);
  /// Function to load one plugin
  void try_load_plugin(const boost::filesystem::directory_entry& entry);

  void visit_all_plugin_paths()
  {
    std::string tbse_plugin_path;
#ifdef _WIN32
    char* result;
    std::size_t result_size;
    errno_t err = _dupenv_s(&result, & result_size, "TBSEPLUGINPATH");
    if(!err)
    {
      tbse_plugin_path = result;
    }
#else
    char* result = getenv("TBSEPLUGINPATH");
    if(result)
    {
      tbse_plugin_path = result;
    }
#endif

    typedef std::vector< std::string > find_vector_type;

    find_vector_type find_vec;
    boost::algorithm::split( find_vec, tbse_plugin_path, boost::algorithm::is_any_of(
#ifdef _WIN32
      ";"
#else
      ":"
#endif
      ));

    std::for_each(find_vec.begin(), find_vec.end(), visit_plugin_path);
  }

  void visit_plugin_path(const std::string& path)
  {
    if(boost::filesystem::exists(path) && boost::filesystem::is_directory(path))
    {
      std::for_each(boost::filesystem::directory_iterator(path), boost::filesystem::directory_iterator(), try_load_plugin);
    }
  }

  void try_load_plugin(const boost::filesystem::directory_entry& entry)
  {
    std::string path = entry.path().string();
#ifdef _WIN32
    if (boost::algorithm::iends_with(path, ".dll"))
    {
      HMODULE hModule = LoadLibraryEx(path.c_str(), NULL, LOAD_LIBRARY_AS_IMAGE_RESOURCE);
    }
#else
    void* lib_handle = dlopen(path.c_str(), RTLD_NOW);
    if (!lib_handle)
    {
      std::cout << "    Path " << path << " is not a plugin: " << dlerror() << std::endl;
    }

#endif
  }
}
