/* Copyright (C) 2025 Eduardo Santos <eduardo.experimental@gmail.com>
 *
 * This file is part of libminds.
 *
 * libminds is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * libminds is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libminds. If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>

#include "../minds.h"

#define CAP 16

HT_HEAD(HashTable, const char *, int)

int
main(void)
{
	int *found = NULL;
	struct HashTable ht;
	struct HashTableEntry entries[CAP];

	ht.entries = entries;
	ht.cap = CAP;
	HT_INIT(&ht);
	HT_SET(&ht, "leet", 4, 1337);
	HT_GET(&ht, "leet", 4, found);

	if (found)
		fprintf(stderr, "found: %d\n", *found);
	else
		fprintf(stderr, "not found\n");

	return 0;
}
