/* 
 * Copyright (C) 2007 Zeeshan Ali <zeenix@gstreamer.net>
 * Copyright (C) 2006, 2007 OpenedHand Ltd.
 *
 * Author: Zeeshan Ali <zeenix@gstreamer.net>
 *         Jorn Baayen <jorn@openedhand.com>
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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GUPNP_SERVICE_INTROSPECTION_H__
#define __GUPNP_SERVICE_INTROSPECTION_H__

#include <glib-object.h>

G_BEGIN_DECLS

GType
gupnp_service_introspection_get_type (void) G_GNUC_CONST;

#define GUPNP_TYPE_SERVICE_INTROSPECTION \
                (gupnp_service_introspection_get_type ())
#define GUPNP_SERVICE_INTROSPECTION(obj) \
                (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
                 GUPNP_TYPE_SERVICE_INTROSPECTION, \
                 GUPnPServiceIntrospection))
#define GUPNP_SERVICE_INTROSPECTION_CLASS(obj) \
                (G_TYPE_CHECK_CLASS_CAST ((obj), \
                 GUPNP_TYPE_SERVICE_INTROSPECTION, \
                 GUPnPServiceIntrospectionClass))
#define GUPNP_IS_SERVICE_INTROSPECTION(obj) \
                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
                 GUPNP_TYPE_SERVICE_INTROSPECTION))
#define GUPNP_IS_SERVICE_INTROSPECTION_CLASS(obj) \
                (G_TYPE_CHECK_CLASS_TYPE ((obj), \
                 GUPNP_TYPE_SERVICE_INTROSPECTION))
#define GUPNP_SERVICE_INTROSPECTION_GET_CLASS(obj) \
                (G_TYPE_INSTANCE_GET_CLASS ((obj), \
                 GUPNP_TYPE_SERVICE_INTROSPECTION, \
                 GUPnPServiceIntrospectionClass))

typedef enum
{
        GUPNP_SERVICE_ACTION_ARG_DIRECTION_IN,
        GUPNP_SERVICE_ACTION_ARG_DIRECTION_OUT
} GUPnPServiceActionArgDirection;

typedef struct {
        char                          *name;
        GUPnPServiceActionArgDirection direction;
        char                          *related_state_variable;
        gboolean                       retval; /* Is this the return value? */
} GUPnPServiceActionArgInfo;

typedef struct {
        char  *name;
        GList *arguments; /* list of #GUPnPServiceActionArgInfo */
} GUPnPServiceActionInfo;

typedef struct {
        char    *name;
        gboolean send_events;     /* Capable of sourcing events?           */
        gboolean is_numeric;      /* Is this a numeric type?               */
        GType    type;
        GValue   default_value;
        GValue   minimum;         /* only for numeric data types           */
        GValue   maximum;         /* only for numeric data types           */
        GValue   step;            /* only for numeric data types           */
        GList   *allowed_values;  /* only for string data type; list of    */
                                  /* (char *) strings rather than GValues  */
} GUPnPServiceStateVariableInfo;

typedef struct _GUPnPServiceIntrospectionPrivate
                GUPnPServiceIntrospectionPrivate;

typedef struct {
        GObject parent;
        
        GUPnPServiceIntrospectionPrivate *priv;
} GUPnPServiceIntrospection;

typedef struct {
        GObjectClass parent_class;
} GUPnPServiceIntrospectionClass;

const GList *
gupnp_service_introspection_list_action_names
                                (GUPnPServiceIntrospection *introspection);

const GList *
gupnp_service_introspection_list_actions
                                (GUPnPServiceIntrospection *introspection);

const GList *
gupnp_service_introspection_list_state_variable_names
                                (GUPnPServiceIntrospection *introspection);

const GList *
gupnp_service_introspection_list_state_variables
                                (GUPnPServiceIntrospection *introspection);

G_END_DECLS

#endif /* __GUPNP_SERVICE_INTROSPECTION_H__ */
