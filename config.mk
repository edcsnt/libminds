# Copyright (C) 2025 Eduardo Santos <eduardo.experimental@gmail.com>
#
# This file is part of libminds.
#
# libminds is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or (at your
# option) any later version.
#
# libminds is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libminds. If not, see <https://www.gnu.org/licenses/>.
DESTDIR   =
PREFIX    = /usr/local
MANPREFIX = $(PREFIX)/share/man

BINSUFFIX =

CPPFLAGS  =
CFLAGS    = -std=c89 -pedantic -Wextra -Wall -Os $(CPPFLAGS)
LDFLAGS   = -s -static

CC        = cc
LD        = $(CC)
