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
#
# libminds - minimal data structures library
.POSIX:
.SUFFIXES:

VERSION_MAJOR = 0
VERSION_MINOR = 0
VERSION_PATCH = 0
MAN_DATE      =

include config.mk

VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

TEST =\
	test/ht\

MAN3 =\
	man/minds_ht_head\
	man/minds_ht_init\
	man/minds_ht_index\
	man/minds_ht_set\
	man/minds_ht_get\
	man/minds_ht_grow\

MAN7 =\
	man/libminds\

all: check

#$(TEST:=$(BINSUFFIX)):
#	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) test/

check: test

#test: $(TEST:=$(BINSUFFIX))
#	for m in $(TEST:=$(BINSUFFIX)); do ./$$m; done
SRC = test/ht.c
OBJ = test/ht.o
BIN = test/ht
test: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o test/ht $(SRC)
	-./$(BIN)
	rm $(BIN)

.PHONY: all check test
