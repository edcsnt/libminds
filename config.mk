# See the COPYING file for copyright details.
DESTDIR   =
PREFIX    = /usr/local
MANPREFIX = $(PREFIX)/share/man

BINSUFFIX =

CPPFLAGS  =
CFLAGS    = -std=c89 -pedantic -Wextra -Wall -Os $(CPPFLAGS)
LDFLAGS   = -s -static

CC        = cc
LD        = $(CC)
