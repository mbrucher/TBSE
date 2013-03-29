/**
 * /file xsd_traits.h
 */

#ifndef CORE_XSD_TRAITS_H
#define CORE_XSD_TRAITS_H

#include <string>

class QDomElement;
class QDomElement;

template<typename DataType>
struct XSDTraits
{
  void serialize(const DataType& object, QDomElement* fragment)
  {
    object.serialize(fragment);
  }
  void unserialize(DataType& object, const QDomElement* fragment)
  {
    object.unserialize(fragment);
  }
};

template<>
struct XSDTraits<int>
{
  void serialize(const int& object, QDomElement* fragment);
  void unserialize(int& object, const QDomElement* fragment);
};

template<>
struct XSDTraits<std::string>
{
  void serialize(const std::string& object, QDomElement* fragment);
  void unserialize(std::string& object, const QDomElement* fragment);
};

#endif /* CORE_XSD_TRAITS_H */
