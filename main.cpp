/**
 * \file main.cpp
 */

#include <cstdlib>
#include <string>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char** argv)
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

  typedef std::vector< boost::iterator_range<std::string::iterator> > find_vector_type;
    
  find_vector_type find_vec;
  boost::algorithm::split( find_vec, tbse_plugin_path, boost::algorithm::is_any_of(
#ifdef _WIN32
    ";"
#else
    ":"
#endif
    ));

  return EXIT_SUCCESS;
}
