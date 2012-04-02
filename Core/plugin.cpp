/**
 * \file plugin.cpp
 */

#include <string>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#endif

#include "plugin.h"

namespace TBSE
{
  void visit_plugin_path(const std::string& path);
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
    std::for_each(boost::filesystem::directory_iterator(path), boost::filesystem::directory_iterator(), try_load_plugin);
  }

  void try_load_plugin(const boost::filesystem::directory_entry& entry)
  {
#ifdef _WIN32
    HMODULE hModule = LoadLibraryEx(entry.path().string().c_str(), NULL, LOAD_LIBRARY_AS_DATAFILE);
#else
#endif
  }
}