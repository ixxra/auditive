/* playlist.c generated by valac 0.16.1, the Vala compiler
 * generated from playlist.vala, do not modify */

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
#include <curses.h>


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
#define _g_free0(var) (var = (g_free (var), NULL))
#define __g_list_free__g_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_free0_ (var), NULL)))
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

#define WORLD_WIDE_TYPE_PLAYING_TYPE (world_wide_playing_type_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define EXTERNAL_TYPE_KEY_HANDLED (external_key_handled_get_type ())

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

struct _playlistPrivate {
	gint playlist_position_number;
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

typedef enum  {
	EXTERNAL_KEY_HANDLED_none,
	EXTERNAL_KEY_HANDLED_resync,
	EXTERNAL_KEY_HANDLED_opened
} externalkey_handled;


static gpointer playlist_parent_class = NULL;

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
#define PLAYLIST_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYLIST, playlistPrivate))
enum  {
	PLAYLIST_DUMMY_PROPERTY
};
static void _g_free0_ (gpointer var);
static void _g_list_free__g_free0_ (GList* self);
playlist* playlist_new_play_start (world_wide* w, const gchar* full_path);
playlist* playlist_construct_play_start (GType object_type, world_wide* w, const gchar* full_path);
screen* screen_construct (GType object_type);
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
GType world_wide_playing_type_get_type (void) G_GNUC_CONST;
void dbg_add (dbg* self, const gchar* text);
static gchar* playlist_real_get_title (screen* base);
gchar* get_file_from_path (const gchar* full_path);
static gint playlist_real_get_size (screen* base);
static gchar* playlist_real_calc_target (screen* base, guint num);
static gchar* playlist_find_song_path (playlist* self, guint num);
static gchar* playlist_real_get_line (screen* base, guint num);
gchar* screen_list_prefix (screen* self);
static world_widescreen_type playlist_real_get_screen_type (screen* base);
gchar* get_base_from_path (const gchar* full_path);
void playlist_play_a_song (playlist* self, gint num);
gint screen_get_size (screen* self);
void auditive_stop (auditive* self);
void auditive_set_playing (auditive* self, const gchar* source);
static void playlist_real_advance_song (screen* base);
static void playlist_real_reset_stop (screen* base);
static void playlist_real_key_press (screen* base, gint key_num);
void auditive_draw (auditive* self);
#define CONSOLE_key_left ((gint) KEY_LEFT)
void screen_draw (screen* self);
GType external_key_handled_get_type (void) G_GNUC_CONST;
externalkey_handled external_external_key_press (external* self, gint key_num);
void screen_key_press (screen* self, gint key_num);
void playlist_empty (playlist* self);
playlist* playlist_new (void);
playlist* playlist_construct (GType object_type);
static void playlist_finalize (screen* obj);


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_list_free__g_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_free0_, NULL);
	g_list_free (self);
}


playlist* playlist_construct_play_start (GType object_type, world_wide* w, const gchar* full_path) {
	playlist* self = NULL;
	world_wide* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	world_wide* _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (full_path != NULL, NULL);
	self = (playlist*) screen_construct (object_type);
	_tmp0_ = w;
	((screen*) self)->world = _tmp0_;
	_tmp1_ = full_path;
	_tmp2_ = remove_slashes (_tmp1_);
	_g_free0 (self->m3u_path);
	self->m3u_path = _tmp2_;
	_tmp3_ = ((screen*) self)->world;
	_tmp3_->playlist_position = -1;
	{
		gchar* line = NULL;
		const gchar* _tmp4_;
		GFile* _tmp5_ = NULL;
		GFile* file;
		GFile* _tmp6_;
		GFileInputStream* _tmp7_ = NULL;
		GFileInputStream* _tmp8_;
		GFileInputStream* _tmp9_;
		GDataInputStream* _tmp10_;
		GDataInputStream* _tmp11_;
		GDataInputStream* in_stream;
		_tmp4_ = self->m3u_path;
		_tmp5_ = g_file_new_for_path (_tmp4_);
		file = _tmp5_;
		_tmp6_ = file;
		_tmp7_ = g_file_read (_tmp6_, NULL, &_inner_error_);
		_tmp8_ = _tmp7_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (file);
			_g_free0 (line);
			goto __catch5_g_error;
		}
		_tmp9_ = _tmp8_;
		_tmp10_ = g_data_input_stream_new ((GInputStream*) _tmp9_);
		_tmp11_ = _tmp10_;
		_g_object_unref0 (_tmp9_);
		in_stream = _tmp11_;
		while (TRUE) {
			GDataInputStream* _tmp12_;
			gchar* _tmp13_ = NULL;
			gchar* _tmp14_;
			const gchar* _tmp15_;
			const gchar* _tmp16_;
			_tmp12_ = in_stream;
			_tmp13_ = g_data_input_stream_read_line (_tmp12_, NULL, NULL, &_inner_error_);
			_tmp14_ = _tmp13_;
			if (_inner_error_ != NULL) {
				_g_object_unref0 (in_stream);
				_g_object_unref0 (file);
				_g_free0 (line);
				goto __catch5_g_error;
			}
			_g_free0 (line);
			line = _tmp14_;
			_tmp15_ = line;
			if (!(_tmp15_ != NULL)) {
				break;
			}
			_tmp16_ = line;
			if (g_strcmp0 (_tmp16_, "") != 0) {
				const gchar* _tmp17_;
				gchar* _tmp18_;
				_tmp17_ = line;
				_tmp18_ = g_strdup (_tmp17_);
				self->entry = g_list_append (self->entry, _tmp18_);
			}
		}
		_g_object_unref0 (in_stream);
		_g_object_unref0 (file);
		_g_free0 (line);
	}
	goto __finally5;
	__catch5_g_error:
	{
		GError* err = NULL;
		world_wide* _tmp19_;
		dbg* _tmp20_;
		const gchar* _tmp21_;
		gchar* _tmp22_;
		gchar* _tmp23_;
		gchar* _tmp24_;
		gchar* _tmp25_;
		GError* _tmp26_;
		const gchar* _tmp27_;
		gchar* _tmp28_;
		gchar* _tmp29_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp19_ = ((screen*) self)->world;
		_tmp20_ = _tmp19_->debug;
		_tmp21_ = self->m3u_path;
		_tmp22_ = g_strconcat ("Read text file error: ", _tmp21_, NULL);
		_tmp23_ = _tmp22_;
		_tmp24_ = g_strconcat (_tmp23_, ": ", NULL);
		_tmp25_ = _tmp24_;
		_tmp26_ = err;
		_tmp27_ = _tmp26_->message;
		_tmp28_ = g_strconcat (_tmp25_, _tmp27_, NULL);
		_tmp29_ = _tmp28_;
		dbg_add (_tmp20_, _tmp29_);
		_g_free0 (_tmp29_);
		_g_free0 (_tmp25_);
		_g_free0 (_tmp23_);
		_g_error_free0 (err);
	}
	__finally5:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


playlist* playlist_new_play_start (world_wide* w, const gchar* full_path) {
	return playlist_construct_play_start (TYPE_PLAYLIST, w, full_path);
}


static gchar* playlist_real_get_title (screen* base) {
	playlist * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	self = (playlist*) base;
	_tmp0_ = self->m3u_path;
	if (g_strcmp0 (_tmp0_, "") == 0) {
		gchar* _tmp1_;
		_tmp1_ = g_strdup ("");
		result = _tmp1_;
		return result;
	}
	_tmp2_ = self->m3u_path;
	_tmp3_ = get_file_from_path (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_strconcat ("  ", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	result = _tmp6_;
	return result;
}


static gint playlist_real_get_size (screen* base) {
	playlist * self;
	gint result = 0;
	GList* _tmp0_;
	guint _tmp1_ = 0U;
	self = (playlist*) base;
	_tmp0_ = self->entry;
	_tmp1_ = g_list_length (_tmp0_);
	result = (gint) _tmp1_;
	return result;
}


static gchar* playlist_real_calc_target (screen* base, guint num) {
	playlist * self;
	gchar* result = NULL;
	guint _tmp0_;
	gchar* _tmp1_ = NULL;
	self = (playlist*) base;
	_tmp0_ = num;
	_tmp1_ = playlist_find_song_path (self, _tmp0_);
	result = _tmp1_;
	return result;
}


static gchar* playlist_real_get_line (screen* base, guint num) {
	playlist * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* prefix;
	gboolean _tmp1_ = FALSE;
	world_wide* _tmp2_;
	screen* _tmp3_;
	gboolean _tmp6_;
	const gchar* _tmp8_;
	GList* _tmp9_;
	guint _tmp10_;
	gconstpointer _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	self = (playlist*) base;
	_tmp0_ = g_strdup ("  ");
	prefix = _tmp0_;
	_tmp2_ = ((screen*) self)->world;
	_tmp3_ = _tmp2_->playing_screen;
	if (_tmp3_ == ((screen*) self)) {
		guint _tmp4_;
		gint _tmp5_;
		_tmp4_ = num;
		_tmp5_ = self->priv->playlist_position_number;
		_tmp1_ = _tmp4_ == ((guint) _tmp5_);
	} else {
		_tmp1_ = FALSE;
	}
	_tmp6_ = _tmp1_;
	if (_tmp6_) {
		gchar* _tmp7_ = NULL;
		_tmp7_ = screen_list_prefix ((screen*) self);
		_g_free0 (prefix);
		prefix = _tmp7_;
	}
	_tmp8_ = prefix;
	_tmp9_ = self->entry;
	_tmp10_ = num;
	_tmp11_ = g_list_nth_data (_tmp9_, _tmp10_);
	_tmp12_ = get_file_from_path ((const gchar*) _tmp11_);
	_tmp13_ = _tmp12_;
	_tmp14_ = g_strconcat (_tmp8_, _tmp13_, NULL);
	_tmp15_ = _tmp14_;
	_g_free0 (_tmp13_);
	result = _tmp15_;
	_g_free0 (prefix);
	return result;
}


static world_widescreen_type playlist_real_get_screen_type (screen* base) {
	playlist * self;
	world_widescreen_type result = 0;
	self = (playlist*) base;
	result = WORLD_WIDE_SCREEN_TYPE_play_list;
	return result;
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* _tmp0_;
	glong _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* end;
	gchar* _tmp3_;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_substring (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_;
	gboolean _tmp3_;
	glong _tmp9_;
	glong _tmp15_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		glong _tmp4_;
		glong _tmp5_;
		glong _tmp6_ = 0L;
		_tmp4_ = offset;
		_tmp5_ = len;
		_tmp6_ = string_strnlen ((gchar*) self, _tmp4_ + _tmp5_);
		string_length = _tmp6_;
	} else {
		gint _tmp7_;
		gint _tmp8_;
		_tmp7_ = strlen (self);
		_tmp8_ = _tmp7_;
		string_length = (glong) _tmp8_;
	}
	_tmp9_ = offset;
	if (_tmp9_ < ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		glong _tmp12_;
		_tmp10_ = string_length;
		_tmp11_ = offset;
		offset = _tmp10_ + _tmp11_;
		_tmp12_ = offset;
		g_return_val_if_fail (_tmp12_ >= ((glong) 0), NULL);
	} else {
		glong _tmp13_;
		glong _tmp14_;
		_tmp13_ = offset;
		_tmp14_ = string_length;
		g_return_val_if_fail (_tmp13_ <= _tmp14_, NULL);
	}
	_tmp15_ = len;
	if (_tmp15_ < ((glong) 0)) {
		glong _tmp16_;
		glong _tmp17_;
		_tmp16_ = string_length;
		_tmp17_ = offset;
		len = _tmp16_ - _tmp17_;
	}
	_tmp18_ = offset;
	_tmp19_ = len;
	_tmp20_ = string_length;
	g_return_val_if_fail ((_tmp18_ + _tmp19_) <= _tmp20_, NULL);
	_tmp21_ = offset;
	_tmp22_ = len;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp21_, (gsize) _tmp22_);
	result = _tmp23_;
	return result;
}


static gchar* playlist_find_song_path (playlist* self, guint num) {
	gchar* result = NULL;
	gchar* filename = NULL;
	GList* _tmp0_;
	guint _tmp1_;
	gconstpointer _tmp2_ = NULL;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_;
	gboolean _tmp7_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->entry;
	_tmp1_ = num;
	_tmp2_ = g_list_nth_data (_tmp0_, _tmp1_);
	_tmp3_ = g_strdup ((const gchar*) _tmp2_);
	_g_free0 (filename);
	filename = _tmp3_;
	_tmp4_ = filename;
	_tmp5_ = string_substring (_tmp4_, (glong) 0, (glong) 1);
	_tmp6_ = _tmp5_;
	_tmp7_ = g_strcmp0 (_tmp6_, "/") == 0;
	_g_free0 (_tmp6_);
	if (_tmp7_) {
		result = filename;
		return result;
	} else {
		const gchar* _tmp8_;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		const gchar* _tmp13_;
		gchar* _tmp14_;
		gchar* _tmp15_;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		_tmp8_ = self->m3u_path;
		_tmp9_ = get_base_from_path (_tmp8_);
		_tmp10_ = _tmp9_;
		_tmp11_ = g_strconcat (_tmp10_, "/", NULL);
		_tmp12_ = _tmp11_;
		_tmp13_ = filename;
		_tmp14_ = g_strconcat (_tmp12_, _tmp13_, NULL);
		_tmp15_ = _tmp14_;
		_tmp16_ = remove_slashes (_tmp15_);
		_tmp17_ = _tmp16_;
		_g_free0 (_tmp15_);
		_g_free0 (_tmp12_);
		_g_free0 (_tmp10_);
		result = _tmp17_;
		_g_free0 (filename);
		return result;
	}
	_g_free0 (filename);
}


void playlist_play_a_song (playlist* self, gint num) {
	gchar* _tmp0_;
	gchar* path;
	gint _tmp1_;
	gint _tmp2_ = 0;
	gint _tmp5_;
	gchar* _tmp6_ = NULL;
	world_wide* _tmp7_;
	world_wide* _tmp8_;
	auditive* _tmp9_;
	const gchar* _tmp10_;
	gint _tmp11_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup ("");
	path = _tmp0_;
	_tmp1_ = num;
	_tmp2_ = screen_get_size ((screen*) self);
	if (_tmp1_ >= _tmp2_) {
		world_wide* _tmp3_;
		auditive* _tmp4_;
		_tmp3_ = ((screen*) self)->world;
		_tmp4_ = _tmp3_->player;
		auditive_stop (_tmp4_);
		_g_free0 (path);
		return;
	}
	_tmp5_ = num;
	_tmp6_ = playlist_find_song_path (self, (guint) _tmp5_);
	_g_free0 (path);
	path = _tmp6_;
	_tmp7_ = ((screen*) self)->world;
	_tmp7_->playing_screen = (screen*) self;
	_tmp8_ = ((screen*) self)->world;
	_tmp9_ = _tmp8_->player;
	_tmp10_ = path;
	auditive_set_playing (_tmp9_, _tmp10_);
	_tmp11_ = num;
	self->priv->playlist_position_number = _tmp11_;
	_g_free0 (path);
}


static void playlist_real_advance_song (screen* base) {
	playlist * self;
	gint _tmp0_;
	self = (playlist*) base;
	_tmp0_ = self->priv->playlist_position_number;
	playlist_play_a_song (self, _tmp0_ + 1);
}


static void playlist_real_reset_stop (screen* base) {
	playlist * self;
	self = (playlist*) base;
	self->priv->playlist_position_number = -1;
}


static void playlist_real_key_press (screen* base, gint key_num) {
	playlist * self;
	gint _tmp0_;
	self = (playlist*) base;
	_tmp0_ = key_num;
	switch (_tmp0_) {
		world_wide* _tmp5_;
		console* _tmp6_;
		case '\n':
		{
			gint _tmp1_;
			gint _tmp2_;
			world_wide* _tmp3_;
			auditive* _tmp4_;
			_tmp1_ = ((screen*) self)->screen_pos;
			_tmp2_ = ((screen*) self)->row_pos;
			playlist_play_a_song (self, _tmp1_ + _tmp2_);
			_tmp3_ = ((screen*) self)->world;
			_tmp4_ = _tmp3_->player;
			auditive_draw (_tmp4_);
			break;
		}
		_tmp5_ = ((screen*) self)->world;
		_tmp6_ = _tmp5_->con;
		case CONSOLE_key_left:
		{
			world_wide* _tmp7_;
			GList* _tmp8_;
			world_wide* _tmp9_;
			gint _tmp10_;
			gconstpointer _tmp11_ = NULL;
			_tmp7_ = ((screen*) self)->world;
			_tmp8_ = _tmp7_->files_array;
			_tmp9_ = ((screen*) self)->world;
			_tmp10_ = _tmp9_->screen_files;
			_tmp11_ = g_list_nth_data (_tmp8_, (guint) _tmp10_);
			screen_draw ((screen*) _tmp11_);
			break;
		}
		default:
		{
			world_wide* _tmp12_;
			external* _tmp13_;
			gint _tmp14_;
			externalkey_handled _tmp15_ = 0;
			_tmp12_ = ((screen*) self)->world;
			_tmp13_ = _tmp12_->ext_screen;
			_tmp14_ = key_num;
			_tmp15_ = external_external_key_press (_tmp13_, _tmp14_);
			if (_tmp15_ == EXTERNAL_KEY_HANDLED_none) {
				gint _tmp16_;
				_tmp16_ = key_num;
				SCREEN_CLASS (playlist_parent_class)->key_press (SCREEN (self), _tmp16_);
			}
			break;
		}
	}
}


void playlist_empty (playlist* self) {
	gchar* _tmp4_;
	gint _tmp5_;
	g_return_if_fail (self != NULL);
	while (TRUE) {
		GList* _tmp0_;
		guint _tmp1_ = 0U;
		GList* _tmp2_;
		GList* _tmp3_ = NULL;
		_tmp0_ = self->entry;
		_tmp1_ = g_list_length (_tmp0_);
		if (!(_tmp1_ > ((guint) 0))) {
			break;
		}
		_tmp2_ = self->entry;
		_tmp3_ = g_list_last (_tmp2_);
		self->entry = g_list_delete_link (self->entry, _tmp3_);
	}
	_tmp4_ = g_strdup ("");
	_g_free0 (self->m3u_path);
	self->m3u_path = _tmp4_;
	((screen*) self)->screen_pos = 0;
	_tmp5_ = ((screen*) self)->screen_pos;
	((screen*) self)->row_pos = _tmp5_;
}


playlist* playlist_construct (GType object_type) {
	playlist* self = NULL;
	self = (playlist*) screen_construct (object_type);
	return self;
}


playlist* playlist_new (void) {
	return playlist_construct (TYPE_PLAYLIST);
}


static void playlist_class_init (playlistClass * klass) {
	playlist_parent_class = g_type_class_peek_parent (klass);
	SCREEN_CLASS (klass)->finalize = playlist_finalize;
	g_type_class_add_private (klass, sizeof (playlistPrivate));
	SCREEN_CLASS (klass)->get_title = playlist_real_get_title;
	SCREEN_CLASS (klass)->get_size = playlist_real_get_size;
	SCREEN_CLASS (klass)->calc_target = playlist_real_calc_target;
	SCREEN_CLASS (klass)->get_line = playlist_real_get_line;
	SCREEN_CLASS (klass)->get_screen_type = playlist_real_get_screen_type;
	SCREEN_CLASS (klass)->advance_song = playlist_real_advance_song;
	SCREEN_CLASS (klass)->reset_stop = playlist_real_reset_stop;
	SCREEN_CLASS (klass)->key_press = playlist_real_key_press;
}


static void playlist_instance_init (playlist * self) {
	self->priv = PLAYLIST_GET_PRIVATE (self);
	self->priv->playlist_position_number = -1;
}


static void playlist_finalize (screen* obj) {
	playlist * self;
	self = PLAYLIST (obj);
	_g_free0 (self->m3u_path);
	__g_list_free__g_free0_0 (self->entry);
	SCREEN_CLASS (playlist_parent_class)->finalize (obj);
}


GType playlist_get_type (void) {
	static volatile gsize playlist_type_id__volatile = 0;
	if (g_once_init_enter (&playlist_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (playlistClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) playlist_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (playlist), 0, (GInstanceInitFunc) playlist_instance_init, NULL };
		GType playlist_type_id;
		playlist_type_id = g_type_register_static (TYPE_SCREEN, "playlist", &g_define_type_info, 0);
		g_once_init_leave (&playlist_type_id__volatile, playlist_type_id);
	}
	return playlist_type_id__volatile;
}



