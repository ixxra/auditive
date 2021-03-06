/* viewlist.c generated by valac 0.16.1, the Vala compiler
 * generated from viewlist.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define TYPE_SCREEN (screen_get_type ())
#define SCREEN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SCREEN, screen))
#define SCREEN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SCREEN, screenClass))
#define IS_SCREEN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SCREEN))
#define IS_SCREEN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SCREEN))
#define SCREEN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SCREEN, screenClass))

typedef struct _screen screen;
typedef struct _screenClass screenClass;
typedef struct _screenPrivate screenPrivate;

#define WORLD_WIDE_TYPE_SCREEN_TYPE (world_wide_screen_type_get_type ())

#define TYPE_WORLD_WIDE (world_wide_get_type ())
#define WORLD_WIDE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WORLD_WIDE, world_wide))
#define WORLD_WIDE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WORLD_WIDE, world_wideClass))
#define IS_WORLD_WIDE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WORLD_WIDE))
#define IS_WORLD_WIDE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WORLD_WIDE))
#define WORLD_WIDE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WORLD_WIDE, world_wideClass))

typedef struct _world_wide world_wide;
typedef struct _world_wideClass world_wideClass;

#define TYPE_PLAYLIST (playlist_get_type ())
#define PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYLIST, playlist))
#define PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYLIST, playlistClass))
#define IS_PLAYLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYLIST))
#define IS_PLAYLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYLIST))
#define PLAYLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYLIST, playlistClass))

typedef struct _playlist playlist;
typedef struct _playlistClass playlistClass;
typedef struct _playlistPrivate playlistPrivate;

#define TYPE_VIEWLIST (viewlist_get_type ())
#define VIEWLIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VIEWLIST, viewlist))
#define VIEWLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VIEWLIST, viewlistClass))
#define IS_VIEWLIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VIEWLIST))
#define IS_VIEWLIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VIEWLIST))
#define VIEWLIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VIEWLIST, viewlistClass))

typedef struct _viewlist viewlist;
typedef struct _viewlistClass viewlistClass;
typedef struct _viewlistPrivate viewlistPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
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

#define WORLD_WIDE_TYPE_PLAYING_TYPE (world_wide_playing_type_get_type ())
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

typedef enum  {
	WORLD_WIDE_SCREEN_TYPE_none,
	WORLD_WIDE_SCREEN_TYPE_file_list,
	WORLD_WIDE_SCREEN_TYPE_view_list,
	WORLD_WIDE_SCREEN_TYPE_play_list,
	WORLD_WIDE_SCREEN_TYPE_ext_list,
	WORLD_WIDE_SCREEN_TYPE_debug,
	WORLD_WIDE_SCREEN_TYPE_help
} world_widescreen_type;

struct _screen {
	GTypeInstance parent_instance;
	volatile int ref_count;
	screenPrivate * priv;
	world_wide* world;
	gint screen_pos;
	gint row_pos;
	world_widescreen_type last_screen;
	gint key_handled;
};

struct _screenClass {
	GTypeClass parent_class;
	void (*finalize) (screen *self);
	gboolean (*has_title) (screen* self);
	gchar* (*get_title) (screen* self);
	void (*advance_song) (screen* self);
	gint (*get_size) (screen* self);
	gchar* (*calc_target) (screen* self, guint num);
	gchar* (*get_line) (screen* self, guint num);
	world_widescreen_type (*get_screen_type) (screen* self);
	void (*reset_stop) (screen* self);
	void (*draw) (screen* self);
	void (*key_press) (screen* self, gint key_num);
};

struct _playlist {
	screen parent_instance;
	playlistPrivate * priv;
	gchar* m3u_path;
	GList* entry;
};

struct _playlistClass {
	screenClass parent_class;
};

struct _viewlist {
	playlist parent_instance;
	viewlistPrivate * priv;
};

struct _viewlistClass {
	playlistClass parent_class;
};

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


static gpointer viewlist_parent_class = NULL;

gpointer screen_ref (gpointer instance);
void screen_unref (gpointer instance);
GParamSpec* param_spec_screen (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_screen (GValue* value, gpointer v_object);
void value_take_screen (GValue* value, gpointer v_object);
gpointer value_get_screen (const GValue* value);
GType screen_get_type (void) G_GNUC_CONST;
GType world_wide_screen_type_get_type (void) G_GNUC_CONST;
gpointer world_wide_ref (gpointer instance);
void world_wide_unref (gpointer instance);
GParamSpec* param_spec_world_wide (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_world_wide (GValue* value, gpointer v_object);
void value_take_world_wide (GValue* value, gpointer v_object);
gpointer value_get_world_wide (const GValue* value);
GType world_wide_get_type (void) G_GNUC_CONST;
GType playlist_get_type (void) G_GNUC_CONST;
GType viewlist_get_type (void) G_GNUC_CONST;
enum  {
	VIEWLIST_DUMMY_PROPERTY
};
viewlist* viewlist_new_view_start (world_wide* w, const gchar* full_path);
viewlist* viewlist_construct_view_start (GType object_type, world_wide* w, const gchar* full_path);
playlist* playlist_new (void);
playlist* playlist_construct (GType object_type);
gchar* remove_slashes (const gchar* path);
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
GType world_wide_playing_type_get_type (void) G_GNUC_CONST;
void dbg_add (dbg* self, const gchar* text);
static gchar* viewlist_real_get_line (screen* base, guint num);
gchar* get_file_from_path (const gchar* full_path);
static world_widescreen_type viewlist_real_get_screen_type (screen* base);
static void viewlist_real_key_press (screen* base, gint key_num);
void playlist_empty (playlist* self);
playlist* playlist_new_play_start (world_wide* w, const gchar* full_path);
playlist* playlist_construct_play_start (GType object_type, world_wide* w, const gchar* full_path);
void playlist_play_a_song (playlist* self, gint num);
void screen_draw (screen* self);
void screen_key_press (screen* self, gint key_num);
viewlist* viewlist_new (void);
viewlist* viewlist_construct (GType object_type);


viewlist* viewlist_construct_view_start (GType object_type, world_wide* w, const gchar* full_path) {
	viewlist* self = NULL;
	world_wide* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (full_path != NULL, NULL);
	self = (viewlist*) playlist_construct (object_type);
	_tmp0_ = w;
	((screen*) self)->world = _tmp0_;
	_tmp1_ = full_path;
	_tmp2_ = remove_slashes (_tmp1_);
	_g_free0 (((playlist*) self)->m3u_path);
	((playlist*) self)->m3u_path = _tmp2_;
	{
		gchar* line = NULL;
		const gchar* _tmp3_;
		GFile* _tmp4_ = NULL;
		GFile* file;
		GFile* _tmp5_;
		GFileInputStream* _tmp6_ = NULL;
		GFileInputStream* _tmp7_;
		GFileInputStream* _tmp8_;
		GDataInputStream* _tmp9_;
		GDataInputStream* _tmp10_;
		GDataInputStream* in_stream;
		_tmp3_ = ((playlist*) self)->m3u_path;
		_tmp4_ = g_file_new_for_path (_tmp3_);
		file = _tmp4_;
		_tmp5_ = file;
		_tmp6_ = g_file_read (_tmp5_, NULL, &_inner_error_);
		_tmp7_ = _tmp6_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (file);
			_g_free0 (line);
			goto __catch6_g_error;
		}
		_tmp8_ = _tmp7_;
		_tmp9_ = g_data_input_stream_new ((GInputStream*) _tmp8_);
		_tmp10_ = _tmp9_;
		_g_object_unref0 (_tmp8_);
		in_stream = _tmp10_;
		while (TRUE) {
			GDataInputStream* _tmp11_;
			gchar* _tmp12_ = NULL;
			gchar* _tmp13_;
			const gchar* _tmp14_;
			const gchar* _tmp15_;
			_tmp11_ = in_stream;
			_tmp12_ = g_data_input_stream_read_line (_tmp11_, NULL, NULL, &_inner_error_);
			_tmp13_ = _tmp12_;
			if (_inner_error_ != NULL) {
				_g_object_unref0 (in_stream);
				_g_object_unref0 (file);
				_g_free0 (line);
				goto __catch6_g_error;
			}
			_g_free0 (line);
			line = _tmp13_;
			_tmp14_ = line;
			if (!(_tmp14_ != NULL)) {
				break;
			}
			_tmp15_ = line;
			if (g_strcmp0 (_tmp15_, "") != 0) {
				const gchar* _tmp16_;
				gchar* _tmp17_;
				_tmp16_ = line;
				_tmp17_ = g_strdup (_tmp16_);
				((playlist*) self)->entry = g_list_append (((playlist*) self)->entry, _tmp17_);
			}
		}
		_g_object_unref0 (in_stream);
		_g_object_unref0 (file);
		_g_free0 (line);
	}
	goto __finally6;
	__catch6_g_error:
	{
		GError* err = NULL;
		world_wide* _tmp18_;
		dbg* _tmp19_;
		const gchar* _tmp20_;
		gchar* _tmp21_;
		gchar* _tmp22_;
		gchar* _tmp23_;
		gchar* _tmp24_;
		GError* _tmp25_;
		const gchar* _tmp26_;
		gchar* _tmp27_;
		gchar* _tmp28_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp18_ = ((screen*) self)->world;
		_tmp19_ = _tmp18_->debug;
		_tmp20_ = ((playlist*) self)->m3u_path;
		_tmp21_ = g_strconcat ("Read text file error: ", _tmp20_, NULL);
		_tmp22_ = _tmp21_;
		_tmp23_ = g_strconcat (_tmp22_, ": ", NULL);
		_tmp24_ = _tmp23_;
		_tmp25_ = err;
		_tmp26_ = _tmp25_->message;
		_tmp27_ = g_strconcat (_tmp24_, _tmp26_, NULL);
		_tmp28_ = _tmp27_;
		dbg_add (_tmp19_, _tmp28_);
		_g_free0 (_tmp28_);
		_g_free0 (_tmp24_);
		_g_free0 (_tmp22_);
		_g_error_free0 (err);
	}
	__finally6:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


viewlist* viewlist_new_view_start (world_wide* w, const gchar* full_path) {
	return viewlist_construct_view_start (TYPE_VIEWLIST, w, full_path);
}


static gchar* viewlist_real_get_line (screen* base, guint num) {
	viewlist * self;
	gchar* result = NULL;
	GList* _tmp0_;
	guint _tmp1_;
	gconstpointer _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	self = (viewlist*) base;
	_tmp0_ = ((playlist*) self)->entry;
	_tmp1_ = num;
	_tmp2_ = g_list_nth_data (_tmp0_, _tmp1_);
	_tmp3_ = get_file_from_path ((const gchar*) _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strconcat ("  ", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	result = _tmp6_;
	return result;
}


static world_widescreen_type viewlist_real_get_screen_type (screen* base) {
	viewlist * self;
	world_widescreen_type result = 0;
	self = (viewlist*) base;
	result = WORLD_WIDE_SCREEN_TYPE_view_list;
	return result;
}


static void viewlist_real_key_press (screen* base, gint key_num) {
	viewlist * self;
	gint _tmp0_;
	self = (viewlist*) base;
	_tmp0_ = key_num;
	switch (_tmp0_) {
		case '\n':
		{
			world_wide* _tmp1_;
			playlist* _tmp2_;
			world_wide* _tmp5_;
			world_wide* _tmp6_;
			const gchar* _tmp7_;
			playlist* _tmp8_;
			world_wide* _tmp9_;
			playlist* _tmp10_;
			gint _tmp11_;
			world_wide* _tmp12_;
			playlist* _tmp13_;
			gint _tmp14_;
			world_wide* _tmp15_;
			playlist* _tmp16_;
			gint _tmp17_;
			gint _tmp18_;
			world_wide* _tmp19_;
			playlist* _tmp20_;
			_tmp1_ = ((screen*) self)->world;
			_tmp2_ = _tmp1_->play_screen;
			if (_tmp2_ != NULL) {
				world_wide* _tmp3_;
				playlist* _tmp4_;
				_tmp3_ = ((screen*) self)->world;
				_tmp4_ = _tmp3_->play_screen;
				playlist_empty (_tmp4_);
			}
			_tmp5_ = ((screen*) self)->world;
			_tmp6_ = ((screen*) self)->world;
			_tmp7_ = ((playlist*) self)->m3u_path;
			_tmp8_ = playlist_new_play_start (_tmp6_, _tmp7_);
			_tmp5_->play_screen = _tmp8_;
			_tmp9_ = ((screen*) self)->world;
			_tmp10_ = _tmp9_->play_screen;
			_tmp11_ = ((screen*) self)->screen_pos;
			((screen*) _tmp10_)->screen_pos = _tmp11_;
			_tmp12_ = ((screen*) self)->world;
			_tmp13_ = _tmp12_->play_screen;
			_tmp14_ = ((screen*) self)->row_pos;
			((screen*) _tmp13_)->row_pos = _tmp14_;
			_tmp15_ = ((screen*) self)->world;
			_tmp16_ = _tmp15_->play_screen;
			_tmp17_ = ((screen*) self)->screen_pos;
			_tmp18_ = ((screen*) self)->row_pos;
			playlist_play_a_song (_tmp16_, _tmp17_ + _tmp18_);
			_tmp19_ = ((screen*) self)->world;
			_tmp20_ = _tmp19_->play_screen;
			screen_draw ((screen*) _tmp20_);
			break;
		}
		default:
		{
			gint _tmp21_;
			_tmp21_ = key_num;
			SCREEN_CLASS (viewlist_parent_class)->key_press ((screen*) PLAYLIST (self), _tmp21_);
			break;
		}
	}
}


viewlist* viewlist_construct (GType object_type) {
	viewlist* self = NULL;
	self = (viewlist*) playlist_construct (object_type);
	return self;
}


viewlist* viewlist_new (void) {
	return viewlist_construct (TYPE_VIEWLIST);
}


static void viewlist_class_init (viewlistClass * klass) {
	viewlist_parent_class = g_type_class_peek_parent (klass);
	SCREEN_CLASS (klass)->get_line = viewlist_real_get_line;
	SCREEN_CLASS (klass)->get_screen_type = viewlist_real_get_screen_type;
	SCREEN_CLASS (klass)->key_press = viewlist_real_key_press;
}


static void viewlist_instance_init (viewlist * self) {
}


GType viewlist_get_type (void) {
	static volatile gsize viewlist_type_id__volatile = 0;
	if (g_once_init_enter (&viewlist_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (viewlistClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) viewlist_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (viewlist), 0, (GInstanceInitFunc) viewlist_instance_init, NULL };
		GType viewlist_type_id;
		viewlist_type_id = g_type_register_static (TYPE_PLAYLIST, "viewlist", &g_define_type_info, 0);
		g_once_init_leave (&viewlist_type_id__volatile, viewlist_type_id);
	}
	return viewlist_type_id__volatile;
}



