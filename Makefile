# Copyright 2025 Eduardo Santos. All rights reserved.
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
