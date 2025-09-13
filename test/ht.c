/* See the COPYRIGHT file for copyright details. */
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
