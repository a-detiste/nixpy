# Copyright (c) 2014, German Neuroinformatics Node (G-Node)
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted under the terms of the BSD License. See
# LICENSE file in the root of the Project.

from __future__ import (absolute_import, division, print_function)#, unicode_literals)

try:
    import nixio.util.inject
    from nixio.core import LinkType
except ImportError:
    LinkType = None


from nixio.pycore.file import File, FileMode
from nixio.value import Value, DataType
from nixio.pycore.dimensions import DimensionType

from nixio.section import S


__all__ = ("File", "FileMode", "DataType", "Value", "LinkType", "DimensionType")

__author__ = ('Christian Kellner, Adrian Stoewer, Andrey Sobolev, Jan Grewe,'
              ' Balint Morvai')
