#!/usr/bin/env python

class XSDContent(object):
  pass

def parse_xsd(filename):
  from xml.etree.ElementTree import parse
  f = open(filename)
  xmlstructure = parse(f)
  structure = XSDContent()
  structure.filename = filename.replace('Schemas', 'Generated').replace('.xsd', '')
  structure.includes = []
  structure.objects = []

  for child in xmlstructure.getroot():
    kind = child.tag.split("}")[1]
    if kind == "include":
      pass
    if kind == "element":
      pass

  return structure

def generate_folders(filename):
  import os
  dirname = os.path.dirname(filename)
  if not os.path.exists(dirname):
    os.makedirs(dirname)

def generate_open_guard(structure, f):
  import os
  header_file = structure.filename + '.h'
  basename = os.path.basename(header_file).upper().replace('.', '_')
  f.write("""/**
 * \\file %s
 * Autogenerated from %s.xsd
 */

#ifndef %s
#define %s
""" % (os.path.basename(header_file), structure.filename, basename, basename))

def generate_close_guard(structure, f):
  import os
  header_file = structure.filename + '.h'
  basename = os.path.basename(header_file).upper().replace('.', '_')
  f.write("""
#endif /* %s */
""" % (basename))

def generate_header(structure):
  filename = structure.filename + '.h'
  generate_folders(filename)
  f = open(filename, "w")

  generate_open_guard(structure, f)
  generate_close_guard(structure, f)

def generate_includes(structure, f):
  import os
  header_file = structure.filename + '.h'
  f.write("""/**
 * \\file %s
 * Autogenerated from %s.xsd
 */

#include "%s"
""" % (os.path.basename(header_file), structure.filename, os.path.basename(header_file)))


def generate_source(structure):
  filename = structure.filename + '.cpp'
  generate_folders(filename)
  f = open(filename, "w")

  generate_includes(structure, f)

if __name__ == "__main__":
  import sys

  structure = parse_xsd(sys.argv[1])
  generate_header(structure)
  generate_source(structure)
