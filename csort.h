/* CairoSort
 * Copyright (C) <2014> Fabian Orccon <fabian.orccon@pucp.pe>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* TODO This thing is not being used. We should use it */
typedef void (* CSortCmpFunction) (void *, void *);
typedef void (* CSortFunction) (void *, int, int, int (*) (void *, void *),
    void (*) (void *, int, void *, void *, void *, void *), void *);

int csort_cmp_int_func (void * a, void * b);

void csort_bubble_sort (void * array, int len, int size,
    int (* csort_cmp_func) (void *, void *),
    void (* do_something) (void *, int, void *, void *, void *), 
    void * do_something_data);

void csort_do_int_print_example (void * array, int len, void * a, void * b,
    void * data);
