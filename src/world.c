/* world.c generated by valac 0.16.1, the Vala compiler
 * generated from world.vala, do not modify */

/*

This file is part of Auditive.

Copyright 2010-2012 Graeme Sheppard.

Auditive is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Auditive is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Auditive. If not, see <http://www.gnu.org/licenses/>.

*/

#include <glib.h>
#include <glib-object.h>
#include <gobject/gvaluecollector.h>


#define TYPE_WORLD_WIDE (world_wide_get_type ())
#define WORLD_WIDE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WORLD_WIDE, world_wide))
#define WORLD_WIDE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WORLD_WIDE, world_wideClass))
#define IS_WORLD_WIDE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WORLD_WIDE))
#define IS_WORLD_WIDE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WORLD_WIDE))
#define WORLD_WIDE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WORLD_WIDE, world_wideClass))

typedef struct _world_wide world_wide;
typedef struct _world_wideClass world_wideClass;
typedef struct _world_widePrivate world_widePrivate;

#define TYPE_CONSOLE (console_get_type ())
#define CONSOLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONSOLE, console))
#define CONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONSOLE, consoleClass))
#define IS_CONSOLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONSOLE))
#define IS_CONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONSOLE))
#define CONSOLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONSOLE, consoleClass))

typedef struct _console console;
typedef struct _consoleClass consoleClass;

#define TYPE_AUDITIVE (auditive_get_type ())
#define AUDITIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_AUDITIVE, auditive))
#define AUDITIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_AUDITIVE, auditiveClass))
#define IS_AUDITIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_AUDITIVE))
#define IS_AUDITIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_AUDITIVE))
#define AUDITIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_AUDITIVE, auditiveClass))

typedef struct _auditive auditive;
typedef struct _auditiveClass auditiveClass;

#define TYPE_SCREEN (screen_get_type ())
#define SCREEN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SCREEN, screen))
#define SCREEN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SCREEN, screenClass))
#define IS_SCREEN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SCREEN))
#define IS_SCREEN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SCREEN))
#define SCREEN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SCREEN, screenClass))

typedef struct _screen screen;
typedef struct _screenClass screenClass;

#define TYPE_PLAYLIST (playlist_get_type ())
#define PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYLIST, playlist))
#define PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYLIST, playlistClass))
#define IS_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYLIST))
#define IS_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYLIST))
#define PLAYLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYLIST, playlistClass))

typedef struct _playlist playlist;
typedef struct _playlistClass playlistClass;

#define TYPE_VIEWLIST (viewlist_get_type ())
#define VIEWLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VIEWLIST, viewlist))
#define VIEWLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VIEWLIST, viewlistClass))
#define IS_VIEWLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VIEWLIST))
#define IS_VIEWLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VIEWLIST))
#define VIEWLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VIEWLIST, viewlistClass))

typedef struct _viewlist viewlist;
typedef struct _viewlistClass viewlistClass;

#define TYPE_EXTERNAL (external_get_type ())
#define EXTERNAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_EXTERNAL, external))
#define EXTERNAL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_EXTERNAL, externalClass))
#define IS_EXTERNAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_EXTERNAL))
#define IS_EXTERNAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_EXTERNAL))
#define EXTERNAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_EXTERNAL, externalClass))

typedef struct _external external;
typedef struct _externalClass externalClass;

#define TYPE_DBG (dbg_get_type ())
#define DBG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DBG, dbg))
#define DBG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DBG, dbgClass))
#define IS_DBG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DBG))
#define IS_DBG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DBG))
#define DBG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DBG, dbgClass))

typedef struct _dbg dbg;
typedef struct _dbgClass dbgClass;

#define TYPE_HELP (help_get_type ())
#define HELP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_HELP, help))
#define HELP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_HELP, helpClass))
#define IS_HELP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_HELP))
#define IS_HELP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_HELP))
#define HELP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_HELP, helpClass))

typedef struct _help help;
typedef struct _helpClass helpClass;

#define TYPE_FILES (files_get_type ())
#define FILES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FILES, files))
#define FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FILES, filesClass))
#define IS_FILES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FILES))
#define IS_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FILES))
#define FILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FILES, filesClass))

typedef struct _files files;
typedef struct _filesClass filesClass;

#define TYPE_METHOD (method_get_type ())
#define METHOD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_METHOD, method))
#define METHOD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_METHOD, methodClass))
#define IS_METHOD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_METHOD))
#define IS_METHOD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_METHOD))
#define METHOD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_METHOD, methodClass))

typedef struct _method method;
typedef struct _methodClass methodClass;

#define WORLD_WIDE_TYPE_SCREEN_TYPE (world_wide_screen_type_get_type ())

#define WORLD_WIDE_TYPE_PLAYING_TYPE (world_wide_playing_type_get_type ())
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define __g_list_free__method_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__method_unref0_ (var), NULL)))
typedef struct _ParamSpecworld_wide ParamSpecworld_wide;

typedef enum  {
	WORLD_WIDE_SCREEN_TYPE_none,
	WORLD_WIDE_SCREEN_TYPE_file_list,
	WORLD_WIDE_SCREEN_TYPE_view_list,
	WORLD_WIDE_SCREEN_TYPE_play_list,
	WORLD_WIDE_SCREEN_TYPE_ext_list,
	WORLD_WIDE_SCREEN_TYPE_debug,
	WORLD_WIDE_SCREEN_TYPE_help
} world_widescreen_type;

typedef enum  {
	WORLD_WIDE_PLAYING_TYPE_stop,
	WORLD_WIDE_PLAYING_TYPE_play,
	WORLD_WIDE_PLAYING_TYPE_pause
} world_wideplaying_type;

struct _world_wide {
	GTypeInstance parent_instance;
	volatile int ref_count;
	world_widePrivate * priv;
	console* con;
	auditive* player;
	playlist* play_screen;
	viewlist* view_screen;
	external* ext_screen;
	dbg* debug;
	help* help_screen;
	GList* files_array;
	GList* keys_array;
	world_widescreen_type screen_current;
	world_wideplaying_type playing_state;
	gint screen_files;
	gboolean play_advance;
	screen* playing_screen;
	gint playlist_position;
};

struct _world_wideClass {
	GTypeClass parent_class;
	void (*finalize) (world_wide *self);
};

struct _ParamSpecworld_wide {
	GParamSpec parent_instance;
};


static gpointer world_wide_parent_class = NULL;

gpointer world_wide_ref (gpointer instance);
void world_wide_unref (gpointer instance);
GParamSpec* param_spec_world_wide (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_world_wide (GValue* value, gpointer v_object);
void value_take_world_wide (GValue* value, gpointer v_object);
gpointer value_get_world_wide (const GValue* value);
GType world_wide_get_type (void) G_GNUC_CONST;
gpointer console_ref (gpointer instance);
void console_unref (gpointer instance);
GParamSpec* param_spec_console (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_console (GValue* value, gpointer v_object);
void value_take_console (GValue* value, gpointer v_object);
gpointer value_get_console (const GValue* value);
GType console_get_type (void) G_GNUC_CONST;
gpointer auditive_ref (gpointer instance);
void auditive_unref (gpointer instance);
GParamSpec* param_spec_auditive (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_auditive (GValue* value, gpointer v_object);
void value_take_auditive (GValue* value, gpointer v_object);
gpointer value_get_auditive (const GValue* value);
GType auditive_get_type (void) G_GNUC_CONST;
gpointer screen_ref (gpointer instance);
void screen_unref (gpointer instance);
GParamSpec* param_spec_screen (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_screen (GValue* value, gpointer v_object);
void value_take_screen (GValue* value, gpointer v_object);
gpointer value_get_screen (const GValue* value);
GType screen_get_type (void) G_GNUC_CONST;
GType playlist_get_type (void) G_GNUC_CONST;
GType viewlist_get_type (void) G_GNUC_CONST;
GType external_get_type (void) G_GNUC_CONST;
GType dbg_get_type (void) G_GNUC_CONST;
GType help_get_type (void) G_GNUC_CONST;
GType files_get_type (void) G_GNUC_CONST;
gpointer method_ref (gpointer instance);
void method_unref (gpointer instance);
GParamSpec* param_spec_method (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_method (GValue* value, gpointer v_object);
void value_take_method (GValue* value, gpointer v_object);
gpointer value_get_method (const GValue* value);
GType method_get_type (void) G_GNUC_CONST;
GType world_wide_screen_type_get_type (void) G_GNUC_CONST;
GType world_wide_playing_type_get_type (void) G_GNUC_CONST;
enum  {
	WORLD_WIDE_DUMMY_PROPERTY
};
console* console_new (void);
console* console_construct (GType object_type);
static void _method_unref0_ (gpointer var);
static void _g_list_free__method_unref0_ (GList* self);
world_wide* world_wide_new (void);
world_wide* world_wide_construct (GType object_type);
static void world_wide_finalize (world_wide* obj);


GType world_wide_screen_type_get_type (void) {
	static volatile gsize world_wide_screen_type_type_id__volatile = 0;
	if (g_once_init_enter (&world_wide_screen_type_type_id__volatile)) {
		static const GEnumValue values[] = {{WORLD_WIDE_SCREEN_TYPE_none, "WORLD_WIDE_SCREEN_TYPE_none", "none"}, {WORLD_WIDE_SCREEN_TYPE_file_list, "WORLD_WIDE_SCREEN_TYPE_file_list", "file-list"}, {WORLD_WIDE_SCREEN_TYPE_view_list, "WORLD_WIDE_SCREEN_TYPE_view_list", "view-list"}, {WORLD_WIDE_SCREEN_TYPE_play_list, "WORLD_WIDE_SCREEN_TYPE_play_list", "play-list"}, {WORLD_WIDE_SCREEN_TYPE_ext_list, "WORLD_WIDE_SCREEN_TYPE_ext_list", "ext-list"}, {WORLD_WIDE_SCREEN_TYPE_debug, "WORLD_WIDE_SCREEN_TYPE_debug", "debug"}, {WORLD_WIDE_SCREEN_TYPE_help, "WORLD_WIDE_SCREEN_TYPE_help", "help"}, {0, NULL, NULL}};
		GType world_wide_screen_type_type_id;
		world_wide_screen_type_type_id = g_enum_register_static ("world_widescreen_type", values);
		g_once_init_leave (&world_wide_screen_type_type_id__volatile, world_wide_screen_type_type_id);
	}
	return world_wide_screen_type_type_id__volatile;
}


GType world_wide_playing_type_get_type (void) {
	static volatile gsize world_wide_playing_type_type_id__volatile = 0;
	if (g_once_init_enter (&world_wide_playing_type_type_id__volatile)) {
		static const GEnumValue values[] = {{WORLD_WIDE_PLAYING_TYPE_stop, "WORLD_WIDE_PLAYING_TYPE_stop", "stop"}, {WORLD_WIDE_PLAYING_TYPE_play, "WORLD_WIDE_PLAYING_TYPE_play", "play"}, {WORLD_WIDE_PLAYING_TYPE_pause, "WORLD_WIDE_PLAYING_TYPE_pause", "pause"}, {0, NULL, NULL}};
		GType world_wide_playing_type_type_id;
		world_wide_playing_type_type_id = g_enum_register_static ("world_wideplaying_type", values);
		g_once_init_leave (&world_wide_playing_type_type_id__volatile, world_wide_playing_type_type_id);
	}
	return world_wide_playing_type_type_id__volatile;
}


static void _method_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (method_unref (var), NULL));
}


static void _g_list_free__method_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _method_unref0_, NULL);
	g_list_free (self);
}


world_wide* world_wide_construct (GType object_type) {
	world_wide* self = NULL;
	self = (world_wide*) g_type_create_instance (object_type);
	return self;
}


world_wide* world_wide_new (void) {
	return world_wide_construct (TYPE_WORLD_WIDE);
}


static void value_world_wide_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_world_wide_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		world_wide_unref (value->data[0].v_pointer);
	}
}


static void value_world_wide_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = world_wide_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_world_wide_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_world_wide_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		world_wide* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = world_wide_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_world_wide_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	world_wide** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = world_wide_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_world_wide (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecworld_wide* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_WORLD_WIDE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_world_wide (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_WORLD_WIDE), NULL);
	return value->data[0].v_pointer;
}


void value_set_world_wide (GValue* value, gpointer v_object) {
	world_wide* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_WORLD_WIDE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_WORLD_WIDE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		world_wide_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		world_wide_unref (old);
	}
}


void value_take_world_wide (GValue* value, gpointer v_object) {
	world_wide* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_WORLD_WIDE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_WORLD_WIDE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		world_wide_unref (old);
	}
}


static void world_wide_class_init (world_wideClass * klass) {
	world_wide_parent_class = g_type_class_peek_parent (klass);
	WORLD_WIDE_CLASS (klass)->finalize = world_wide_finalize;
}


static void world_wide_instance_init (world_wide * self) {
	console* _tmp0_;
	_tmp0_ = console_new ();
	self->con = _tmp0_;
	self->play_screen = NULL;
	self->view_screen = NULL;
	self->ext_screen = NULL;
	self->debug = NULL;
	self->help_screen = NULL;
	self->play_advance = TRUE;
	self->playing_screen = NULL;
	self->playlist_position = -1;
	self->ref_count = 1;
}


static void world_wide_finalize (world_wide* obj) {
	world_wide * self;
	self = WORLD_WIDE (obj);
	_g_list_free0 (self->files_array);
	__g_list_free__method_unref0_0 (self->keys_array);
}


GType world_wide_get_type (void) {
	static volatile gsize world_wide_type_id__volatile = 0;
	if (g_once_init_enter (&world_wide_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_world_wide_init, value_world_wide_free_value, value_world_wide_copy_value, value_world_wide_peek_pointer, "p", value_world_wide_collect_value, "p", value_world_wide_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (world_wideClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) world_wide_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (world_wide), 0, (GInstanceInitFunc) world_wide_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType world_wide_type_id;
		world_wide_type_id = g_type_register_fundamental (g_type_fundamental_next (), "world_wide", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&world_wide_type_id__volatile, world_wide_type_id);
	}
	return world_wide_type_id__volatile;
}


gpointer world_wide_ref (gpointer instance) {
	world_wide* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void world_wide_unref (gpointer instance) {
	world_wide* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		WORLD_WIDE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


