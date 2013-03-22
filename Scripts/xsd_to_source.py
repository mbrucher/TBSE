#!/usr/bin/env python

def parse_xsd(filename):
  pass

def generate_header(structure):
  pass

def generate_source(structure):
  pass

if __name__ == "__main__":
  import sys

  structure = parse_xsd(sys.argv[1])
  generate_header(structure)
  generate_source(structure)
