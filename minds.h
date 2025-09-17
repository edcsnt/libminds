/* Copyright 2025 Eduardo Santos. All rights reserved. */
#ifndef MINDS_H
#define MINDS_H

#include <string.h>

#define HT_OFFSET 2166136261u
#define HT_PRIME    16777619u

#define HT_HEAD(T, TK, TV)                                                  \
        struct T##Entry {                                                   \
                TK k;                                                       \
                size_t n;                                                   \
                TV v;                                                       \
        };                                                                  \
                                                                            \
        struct T {                                                          \
                struct T##Entry *entries;                                   \
                size_t cap;                                                 \
                size_t len;                                                 \
        };

#define HT_INIT(ht)                                                         \
        do {                                                                \
                size_t ht_i;                                                \
                for (ht_i = 0; ht_i < (ht)->cap; ++ht_i) {                  \
                        (ht)->entries[ht_i].k = NULL;                       \
                        (ht)->entries[ht_i].n = 0;                          \
                }                                                           \
                (ht)->len = 0;                                              \
        } while (0)

#define HT_DESTROY(ht) HT_INIT(ht)

#define HT_INDEX(ht, key, siz, idx)                                         \
        do {                                                                \
                unsigned ht_h = HT_OFFSET;                                  \
                const unsigned char *ht_b = (const unsigned char *)(key);   \
                size_t ht_n = (siz);                                        \
                while (ht_n--)                                              \
                        ht_h = (ht_h ^ *ht_b++) * HT_PRIME;                 \
                (idx) = ht_h & ((ht)->cap - 1);                             \
        } while (0)

#define HT_SET(ht, key, siz, val)                                           \
        do {                                                                \
                size_t ht_i;                                                \
                HT_INDEX((ht), (key), (siz), ht_i);                         \
                while ((ht)->entries[ht_i].k &&                             \
                     !((ht)->entries[ht_i].n == (siz) &&                    \
                       !memcmp((ht)->entries[ht_i].k, (key), (siz))))       \
                        ht_i = (ht_i + 1) & ((ht)->cap - 1);                \
                if (!(ht)->entries[ht_i].k)                                 \
                        ++(ht)->len;                                        \
                (ht)->entries[ht_i].k = (key);                              \
                (ht)->entries[ht_i].n = (siz);                              \
                (ht)->entries[ht_i].v = (val);                              \
        } while (0)

#define HT_GET(ht, key, siz, val)                                           \
        do {                                                                \
                size_t ht_i;                                                \
                HT_INDEX((ht), (key), (siz), ht_i);                         \
                (val) = NULL;                                               \
                while ((ht)->entries[ht_i].k) {                             \
                        if ((ht)->entries[ht_i].n == (siz) &&               \
                            !memcmp((ht)->entries[ht_i].k, (key), (siz))) { \
                                (val) = &(ht)->entries[ht_i].v;             \
                                break;                                      \
                        }                                                   \
                        ht_i = (ht_i + 1) & ((ht)->cap - 1);                \
                }                                                           \
        } while (0)

#define HT_GROW(dst, src)                                                   \
        do {                                                                \
                size_t ht_i;                                                \
                HT_INIT(dst);                                               \
                for (ht_i = 0; ht_i < (src)->cap; ++ht_i)                   \
                        if ((src)->entries[ht_i].k)                         \
                                HT_SET((dst),                               \
                                       (src)->entries[ht_i].k,              \
                                       (src)->entries[ht_i].n,              \
                                       (src)->entries[ht_i].v);             \
        } while (0)

#endif  /* MINDS_H */
