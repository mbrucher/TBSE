/**
 * /file xsd_traits.cpp
 * Implementation of XSD traits
 */

#include "xsd_traits.h"

#include <cmath>

#include <QtXml/QDomElement>
#include <QStringList>

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

void XSDTraits<std::vector<std::vector<long> > >::serialize(const std::vector<std::vector<long> >& object, QDomElement* fragment)
{
  long height = object.size();
  long width = object[0].size();
  fragment->setAttribute("width", QString::number(width));
  fragment->setAttribute("height", QString::number(height));
  for(int i = 0; i < height; ++i)
  {
//    QDomText nodeText = fragment->ownerDocument().createTextNode(QString::fromStdString(object));
//    fragment->appendChild(nodeText);
  }
}

void XSDTraits<std::vector<std::vector<long> > >::unserialize(std::vector<std::vector<long> >& object, const QDomElement* fragment)
{
  long height = fragment->attribute("height").toLong();
  long width = fragment->attribute("width").toLong();
  object.clear();
  object.resize(height);
  QDomElement element = fragment->firstChildElement();
  while(!element.isNull())
  {
    if(element.tagName() == "line")
    {
      QStringList list = element.text().split(",");
      long minsize = std::min(static_cast<long>(list.size()), width);
      long id = element.attribute("id").toLong();
      object[id].resize(width);
      for(int i = 0; i < minsize; ++i)
      {
        object[id][i] = list[i].toLong();
      }
    }
    element = element.nextSiblingElement();
  }

}
