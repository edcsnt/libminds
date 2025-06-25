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

#ifndef HT_H
#define HT_H

#include <string.h>

#define HT_OFFSET 2166136261u
#define HT_PRIME    16777619u

#define HT_HEAD(T, TK, TV)                                                    \
        struct T##Entry {                                                     \
                TK k;                                                         \
                size_t n;                                                     \
                TV v;                                                         \
        };                                                                    \
                                                                              \
        struct T {                                                            \
                struct T##Entry *entries;                                     \
                size_t cap;                                                   \
                size_t len;                                                   \
        };

#define HT_INIT(ht)                                                           \
        do {                                                                  \
                memset((ht)->entries, 0, (ht)->cap * sizeof(*(ht)->entries)); \
                (ht)->len = 0;                                                \
        } while (0)

#define HT_INDEX(ht, k, n, i)                                                 \
        do {                                                                  \
                unsigned ht_h = HT_OFFSET;                                    \
                const unsigned char *ht_b = (const unsigned char *)(k);       \
                size_t ht_n = (n);                                            \
                while (ht_n--)                                                \
                        ht_h = (ht_h ^ (*ht_b++)) * HT_PRIME;                 \
                (i) = ht_h & ((ht)->cap - 1);                                 \
        } while (0)

#define HT_SET(ht, k, n, v)                                                   \
        do {                                                                  \
                size_t ht_i;                                                  \
                HT_INDEX((ht), (k), (n), ht_i);                               \
                while ((ht)->entries[ht_i].k &&
                     !((ht)->entries[ht_i].k == (k) &&
                       (ht)->entries[ht_i].n == (n)))                         \
                        ht_i = (ht_i + 1) & ((ht)->cap - 1);                  \
                if (!(ht)->entries[ht_i].k)                                   \
                        ++(ht)->len;                                          \
                (ht)->entries[ht_i].k = (k);                                  \
                (ht)->entries[ht_i].n = (n);                                  \
                (ht)->entries[ht_i].v = (v);                                  \
        } while (0)

#define HT_GET(ht, k, n, v)                                                   \
        do {                                                                  \
                size_t ht_i;                                                  \
                (v) = NULL;                                                   \
                HT_INDEX((ht), (k), (n), ht_i);                               \
                while ((ht)->entries[ht_i].k) {                               \
                        if ((ht)->entries[ht_i].k == (k) &&                   \
                            (ht)->entries[ht_i].n == (n)) {                   \
                                (v) = &((ht)->entries[ht_i].v);               \
                                break;                                        \
                        }                                                     \
                        ht_i = (ht_i + 1) & ((ht)->cap - 1);                  \
                }                                                             \
        } while (0)

#define HT_GROW(dst, src)                                                     \
        do {                                                                  \
                size_t ht_i;                                                  \
                HT_INIT(dst);                                                 \
                for (ht_i = 0; ht_i < (src)->cap; ++ht_i)                     \
                        if ((src)->entries[ht_i].k)                           \
                                HT_SET((dst),                                 \
                                       (src)->entries[ht_i].k,                \
                                       (src)->entries[ht_i].n,                \
                                       (src)->entries[ht_i].v);               \
        } while (0)

#endif  /* HT_H */
