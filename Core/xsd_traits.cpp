/**
 * /file xsd_traits.cpp
 * Implementation of XSD traits
 */

#include "xsd_traits.h"

#include <QtXml/QDomElement>

void XSDTraits<int>::serialize(const int& object, QDomElement* fragment)
{
  QString text = QString::number(object);
  QDomText nodeText = fragment->ownerDocument().createTextNode(text);
  fragment->appendChild(nodeText);
}

void XSDTraits<int>::unserialize(int& object, const QDomElement* fragment)
{
  object = fragment->toText().data().toInt();
}

void XSDTraits<std::string>::serialize(const std::string& object, QDomElement* fragment)
{
  QDomText nodeText = fragment->ownerDocument().createTextNode(QString::fromStdString(object));
  fragment->appendChild(nodeText);
}

void XSDTraits<std::string>::unserialize(std::string& object, const QDomElement* fragment)
{
  object = fragment->toText().data().toStdString();
}
