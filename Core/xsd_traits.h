/**
 * /file xsd_traits.h
 */

#ifndef CORE_XSD_TRAITS_H
#define CORE_XSD_TRAITS_H

#include <string>
#include <vector>

class QDomElement;
class QDomElement;

template<typename DataType>
struct XSDTraits
{
  static void serialize(const DataType& object, QDomElement* fragment)
  {
    object.serialize(fragment);
  }
  static void unserialize(DataType& object, const QDomElement* fragment)
  {
    object.unserialize(fragment);
  }
};

template<>
struct XSDTraits<int>
{
  static void serialize(const int& object, QDomElement* fragment);
  static void unserialize(int& object, const QDomElement* fragment);
};

template<>
struct XSDTraits<std::string>
{
  static void serialize(const std::string& object, QDomElement* fragment);
  static void unserialize(std::string& object, const QDomElement* fragment);
};

template<>
struct XSDTraits<std::vector<std::vector<long> > >
{
  static void serialize(const std::vector<std::vector<long> >& object, QDomElement* fragment);
  static void unserialize(std::vector<std::vector<long> >& object, const QDomElement* fragment);
};

#endif /* CORE_XSD_TRAITS_H */
