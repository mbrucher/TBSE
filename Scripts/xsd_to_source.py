#!/usr/bin/env python

type_map = {
  'integer' : 'int',
  'string' : 'std::string',
  }

class XSDContent(object):
  pass

def parse_xsd(filename):
  """
  Parses an XSD file in a crude manner and populates a simple structure
  """
  from xml.etree.ElementTree import parse
  f = open(filename)
  xmlstructure = parse(f)
  structure = XSDContent()
  structure.filename = filename.replace('Schemas', 'Generated').replace('.xsd', '')
  structure.includes = [{"relative":False, "name":"string"}]
  structure.objects = []

  for child in xmlstructure.getroot():
    kind = child.tag.split("}")[1]
    if kind == "include":
      header_name = child.attrib["schemaLocation"].replace("xsd", "h")
      structure.includes.append({"relative":True, "name":header_name})
    if kind == "element":
      struct = XSDContent()
      struct.name = child.attrib["name"]
      child.attrib["name"] = child.attrib["name"]
      struct.attributes = [(subchild.attrib["name"], subchild.attrib["type"].split(':')[-1]) for subchild in child[0][0]]
      structure.objects.append(struct)

  return structure

def generate_folders(filename):
  """
  Creates the destination folders if needed
  """
  import os
  dirname = os.path.dirname(filename)
  if not os.path.exists(dirname):
    os.makedirs(dirname)

def generate_open_guard(structure, f):
  """
  Writes in the file a specific block guard
  """
  import os
  header_file = structure.filename + '.h'
  basename = os.path.basename(header_file).upper().replace('.', '_')
  f.write("""/**
 * \\file %s
 * Autogenerated from %s.xsd
 */

#ifndef %s
#define %s

class QDomElement;

""" % (os.path.basename(header_file), structure.filename, basename, basename))

def generate_close_guard(structure, f):
  """
  Closes the specific block guard
  """
  import os
  header_file = structure.filename + '.h'
  basename = os.path.basename(header_file).upper().replace('.', '_')
  f.write("""
#endif /* %s */
""" % (basename))

def generate_include_header(structure, f):
  """
  Writes in the file all needed inclusions
  """
  for header in structure.includes:
    if header["relative"]:
      f.write("""
#include "%s"
""" % header["name"])
    else:
      f.write("""
#include <%s>
        """ % header["name"])

def generate_accessors(struct):
  """
  Writes the accesors for the attributes
  """
  types = [type_map.get(attribute[1], attribute[1]) for attribute in struct.attributes]
  get_variable = [attribute[0].capitalize() for attribute in struct.attributes]
  return "\n".join(["""  const %s& get%s() const
  {
    return %s;
  }

  %s& get%s()
  {
    return %s;
  }
""" % (type, get, attributes[0], type, get, attributes[0]) for (attributes, type, get) in zip(struct.attributes, types, get_variable)])

def generate_attributes(struct):
  """
  Writes the declaration for all the attributes
  """
  return "\n".join(["  %s %s;" % (type_map.get(attribute[1], attribute[1]), attribute[0]) for attribute in struct.attributes])

def generate_prototypes(structure, f):
  """
  Writes the prototypes for all functions
  """
  for struct in structure.objects:
    f.write("""
struct %s
{
public:
%s

  void serialize(QDomElement* node);
  void unserialize(const QDomElement* node);
protected:
%s
};
""" % (struct.name, generate_accessors(struct), generate_attributes(struct)))

def generate_header(structure):
  """
  Generates the header associated to an XSD parse
  """
  filename = structure.filename + '.h'
  generate_folders(filename)
  f = open(filename, "w")

  generate_open_guard(structure, f)
  generate_include_header(structure, f)
  generate_prototypes(structure, f)
  generate_close_guard(structure, f)

def generate_includes(structure, f):
  """
  Writes to the source the inclusion of the associated header
  """
  import os
  header_file = structure.filename + '.h'
  f.write("""/**
 * \\file %s
 * Autogenerated from %s.xsd
 */

#include "%s"
""" % (os.path.basename(header_file), structure.filename, os.path.basename(header_file)))


def generate_source(structure):
  """
  Generates the source file associated to an XSD parse
  """
  filename = structure.filename + '.cpp'
  generate_folders(filename)
  f = open(filename, "w")

  generate_includes(structure, f)

if __name__ == "__main__":
  import sys

  structure = parse_xsd(sys.argv[1])
  generate_header(structure)
  generate_source(structure)
