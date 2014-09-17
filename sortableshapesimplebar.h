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

/* inclusion guard */
#ifndef __SORTABLE_SHAPE_SIMPLE_BAR_H__
#define __SORTABLE_SHAPE_SIMPLE_BAR_H__

#include "sortableshape.h"
/*
 * Potentially, include other headers on which this header depends.
 */

/*
 * Type macros.
 */
#define SORTABLE_SHAPE_TYPE_SIMPLE_BAR                  (sortable_shape_simple_bar_get_type ())
#define SORTABLE_SHAPE_SIMPLE_BAR(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBar))
#define SORTABLE_SHAPE_IS_SIMPLE_BAR(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR))
#define SORTABLE_SHAPE_SIMPLE_BAR_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBarClass))
#define SORTABLE_SHAPE_IS_SIMPLE_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), SORTABLE_SHAPE_TYPE_SIMPLE_BAR))
#define SORTABLE_SHAPE_SIMPLE_BAR_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), SORTABLE_SHAPE_TYPE_SIMPLE_BAR, SortableShapeSimpleBarClass))

typedef struct _SortableShapeSimpleBarPrivate SortableShapeSimpleBarPrivate;

typedef struct _SortableShapeSimpleBar        SortableShapeSimpleBar;
typedef struct _SortableShapeSimpleBarClass   SortableShapeSimpleBarClass;


struct _SortableShapeSimpleBar
{
  /* Parent instance structure */
  SortableShapeObject parent_instance;

  /* instance members */
};

struct _SortableShapeSimpleBarClass
{
  /* Parent class structure */
  SortableShapeObjectClass parent_class;

  /* class members */
};

/* used by SORTABLE_SHAPE_TYPE_SIMPLE_BAR */
GType sortable_shape_simple_bar_get_type (void);

/*
 * Method definitions.
 */

#endif /* __SORTABLE_SHAPE_SIMPLE_BAR_H__ */
