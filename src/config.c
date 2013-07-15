/* config.c generated by valac 0.16.1, the Vala compiler
 * generated from config.vala, do not modify */

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
#define __g_list_free__method_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__method_unref0_ (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
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



gpointer world_wide_ref (gpointer instance);
void world_wide_unref (gpointer instance);
GParamSpec* param_spec_world_wide (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_world_wide (GValue* value, gpointer v_object);
void value_take_world_wide (GValue* value, gpointer v_object);
gpointer value_get_world_wide (const GValue* value);
GType world_wide_get_type (void) G_GNUC_CONST;
void config_setup (world_wide* world);
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
static void _method_unref0_ (gpointer var);
static void _g_list_free__method_unref0_ (GList* self);
void dbg_add (dbg* self, const gchar* text);
method* method_new (gint k, const gchar* n, const gchar* c);
method* method_construct (GType object_type, gint k, const gchar* n, const gchar* c);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static void _method_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (method_unref (var), NULL));
}


static void _g_list_free__method_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _method_unref0_, NULL);
	g_list_free (self);
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static gchar* string_slice (const gchar* self, glong start, glong end) {
	gchar* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	glong string_length;
	glong _tmp2_;
	glong _tmp5_;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_;
	gboolean _tmp12_;
	gboolean _tmp13_ = FALSE;
	glong _tmp14_;
	gboolean _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_;
		glong _tmp4_;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_;
		glong _tmp7_;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	_tmp12_ = _tmp8_;
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp14_ = end;
	if (_tmp14_ >= ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
		_tmp15_ = end;
		_tmp16_ = string_length;
		_tmp13_ = _tmp15_ <= _tmp16_;
	} else {
		_tmp13_ = FALSE;
	}
	_tmp17_ = _tmp13_;
	g_return_val_if_fail (_tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	g_return_val_if_fail (_tmp18_ <= _tmp19_, NULL);
	_tmp20_ = start;
	_tmp21_ = end;
	_tmp22_ = start;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) (_tmp21_ - _tmp22_));
	result = _tmp23_;
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


void config_setup (world_wide* world) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* cfg_file;
	world_wide* _tmp2_;
	GError * _inner_error_ = NULL;
	_tmp0_ = g_get_home_dir ();
	_tmp1_ = g_strconcat (_tmp0_, "/.auditive", NULL);
	cfg_file = _tmp1_;
	_tmp2_ = world;
	__g_list_free__method_unref0_0 (_tmp2_->keys_array);
	_tmp2_->keys_array = NULL;
	{
		gchar* line = NULL;
		const gchar* _tmp3_;
		GFile* _tmp4_ = NULL;
		GFile* file;
		GFile* _tmp5_;
		gboolean _tmp6_ = FALSE;
		world_wide* _tmp12_;
		dbg* _tmp13_;
		const gchar* _tmp14_;
		gchar* _tmp15_;
		gchar* _tmp16_;
		GFile* _tmp17_;
		GFileInputStream* _tmp18_ = NULL;
		GFileInputStream* _tmp19_;
		GFileInputStream* _tmp20_;
		GDataInputStream* _tmp21_;
		GDataInputStream* _tmp22_;
		GDataInputStream* in_stream;
		gint count;
		gboolean good = FALSE;
		_tmp3_ = cfg_file;
		_tmp4_ = g_file_new_for_path (_tmp3_);
		file = _tmp4_;
		_tmp5_ = file;
		_tmp6_ = g_file_query_exists (_tmp5_, NULL);
		if (!_tmp6_) {
			world_wide* _tmp7_;
			dbg* _tmp8_;
			const gchar* _tmp9_;
			gchar* _tmp10_;
			gchar* _tmp11_;
			_tmp7_ = world;
			_tmp8_ = _tmp7_->debug;
			_tmp9_ = cfg_file;
			_tmp10_ = g_strconcat ("Non-fatal: no cfg ", _tmp9_, NULL);
			_tmp11_ = _tmp10_;
			dbg_add (_tmp8_, _tmp11_);
			_g_free0 (_tmp11_);
			_g_object_unref0 (file);
			_g_free0 (line);
			_g_free0 (cfg_file);
			return;
		}
		_tmp12_ = world;
		_tmp13_ = _tmp12_->debug;
		_tmp14_ = cfg_file;
		_tmp15_ = g_strconcat ("reading ", _tmp14_, NULL);
		_tmp16_ = _tmp15_;
		dbg_add (_tmp13_, _tmp16_);
		_g_free0 (_tmp16_);
		_tmp17_ = file;
		_tmp18_ = g_file_read (_tmp17_, NULL, &_inner_error_);
		_tmp19_ = _tmp18_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (file);
			_g_free0 (line);
			goto __catch0_g_error;
		}
		_tmp20_ = _tmp19_;
		_tmp21_ = g_data_input_stream_new ((GInputStream*) _tmp20_);
		_tmp22_ = _tmp21_;
		_g_object_unref0 (_tmp20_);
		in_stream = _tmp22_;
		count = 0;
		while (TRUE) {
			GDataInputStream* _tmp23_;
			gchar* _tmp24_ = NULL;
			gchar* _tmp25_;
			const gchar* _tmp26_;
			gint _tmp27_;
			gboolean _tmp28_ = FALSE;
			const gchar* _tmp29_;
			gboolean _tmp32_;
			gboolean empty;
			gboolean _tmp48_;
			gboolean _tmp98_;
			_tmp23_ = in_stream;
			_tmp24_ = g_data_input_stream_read_line (_tmp23_, NULL, NULL, &_inner_error_);
			_tmp25_ = _tmp24_;
			if (_inner_error_ != NULL) {
				_g_object_unref0 (in_stream);
				_g_object_unref0 (file);
				_g_free0 (line);
				goto __catch0_g_error;
			}
			_g_free0 (line);
			line = _tmp25_;
			_tmp26_ = line;
			if (!(_tmp26_ != NULL)) {
				break;
			}
			_tmp27_ = count;
			count = _tmp27_ + 1;
			_tmp29_ = line;
			if (g_strcmp0 (_tmp29_, "") == 0) {
				_tmp28_ = TRUE;
			} else {
				const gchar* _tmp30_;
				gchar _tmp31_ = '\0';
				_tmp30_ = line;
				_tmp31_ = string_get (_tmp30_, (glong) 0);
				_tmp28_ = _tmp31_ == '#';
			}
			_tmp32_ = _tmp28_;
			if (_tmp32_) {
				continue;
			}
			empty = TRUE;
			{
				gint index;
				index = 0;
				{
					gboolean _tmp33_;
					_tmp33_ = TRUE;
					while (TRUE) {
						gboolean _tmp34_;
						gint _tmp36_;
						const gchar* _tmp37_;
						gint _tmp38_;
						gint _tmp39_;
						gboolean _tmp40_ = FALSE;
						const gchar* _tmp41_;
						gint _tmp42_;
						gchar _tmp43_ = '\0';
						gboolean _tmp47_;
						_tmp34_ = _tmp33_;
						if (!_tmp34_) {
							gint _tmp35_;
							_tmp35_ = index;
							index = _tmp35_ + 1;
						}
						_tmp33_ = FALSE;
						_tmp36_ = index;
						_tmp37_ = line;
						_tmp38_ = strlen (_tmp37_);
						_tmp39_ = _tmp38_;
						if (!(_tmp36_ < _tmp39_)) {
							break;
						}
						_tmp41_ = line;
						_tmp42_ = index;
						_tmp43_ = string_get (_tmp41_, (glong) _tmp42_);
						if (_tmp43_ != ' ') {
							const gchar* _tmp44_;
							gint _tmp45_;
							gchar _tmp46_ = '\0';
							_tmp44_ = line;
							_tmp45_ = index;
							_tmp46_ = string_get (_tmp44_, (glong) _tmp45_);
							_tmp40_ = _tmp46_ != '\t';
						} else {
							_tmp40_ = FALSE;
						}
						_tmp47_ = _tmp40_;
						if (_tmp47_) {
							empty = FALSE;
							break;
						}
					}
				}
			}
			_tmp48_ = empty;
			if (_tmp48_) {
				continue;
			}
			good = FALSE;
			while (TRUE) {
				const gchar* _tmp49_;
				const gchar* _tmp51_;
				const gchar* _tmp53_;
				gchar* _tmp54_ = NULL;
				gchar* _tmp55_;
				gboolean _tmp56_;
				const gchar* _tmp57_;
				gchar* _tmp58_ = NULL;
				gchar* _tmp59_;
				gchar** _tmp60_;
				gchar** _tmp61_ = NULL;
				gchar** _tmp62_;
				gint _tmp62__length1;
				gchar** bits;
				gint bits_length1;
				gint _bits_size_;
				gchar** _tmp63_;
				gint _tmp63__length1;
				gboolean _tmp64_ = FALSE;
				gchar** _tmp65_;
				gint _tmp65__length1;
				const gchar* _tmp66_;
				gboolean _tmp69_;
				gint keystroke = 0;
				gchar** _tmp70_;
				gint _tmp70__length1;
				const gchar* _tmp71_;
				world_wide* _tmp91_;
				gint _tmp92_;
				gchar** _tmp93_;
				gint _tmp93__length1;
				const gchar* _tmp94_;
				gchar** _tmp95_;
				gint _tmp95__length1;
				const gchar* _tmp96_;
				method* _tmp97_;
				_tmp49_ = line;
				if (g_strcmp0 (_tmp49_, "advance=y") == 0) {
					world_wide* _tmp50_;
					_tmp50_ = world;
					_tmp50_->play_advance = TRUE;
					good = TRUE;
					break;
				}
				_tmp51_ = line;
				if (g_strcmp0 (_tmp51_, "advance=n") == 0) {
					world_wide* _tmp52_;
					_tmp52_ = world;
					_tmp52_->play_advance = FALSE;
					good = TRUE;
					break;
				}
				_tmp53_ = line;
				_tmp54_ = string_slice (_tmp53_, (glong) 0, (glong) 4);
				_tmp55_ = _tmp54_;
				_tmp56_ = g_strcmp0 (_tmp55_, "ext=") != 0;
				_g_free0 (_tmp55_);
				if (_tmp56_) {
					break;
				}
				_tmp57_ = line;
				_tmp58_ = string_substring (_tmp57_, (glong) 4, (glong) (-1));
				_tmp59_ = _tmp58_;
				_tmp61_ = _tmp60_ = g_strsplit (_tmp59_, ",", 3);
				_tmp62_ = _tmp61_;
				_tmp62__length1 = _vala_array_length (_tmp60_);
				_g_free0 (_tmp59_);
				bits = _tmp62_;
				bits_length1 = _tmp62__length1;
				_bits_size_ = bits_length1;
				_tmp63_ = bits;
				_tmp63__length1 = bits_length1;
				if (_tmp63__length1 != 3) {
					bits = (_vala_array_free (bits, bits_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_tmp65_ = bits;
				_tmp65__length1 = bits_length1;
				_tmp66_ = _tmp65_[1];
				if (g_strcmp0 (_tmp66_, "") == 0) {
					_tmp64_ = TRUE;
				} else {
					gchar** _tmp67_;
					gint _tmp67__length1;
					const gchar* _tmp68_;
					_tmp67_ = bits;
					_tmp67__length1 = bits_length1;
					_tmp68_ = _tmp67_[2];
					_tmp64_ = g_strcmp0 (_tmp68_, "") == 0;
				}
				_tmp69_ = _tmp64_;
				if (_tmp69_) {
					bits = (_vala_array_free (bits, bits_length1, (GDestroyNotify) g_free), NULL);
					break;
				}
				_tmp70_ = bits;
				_tmp70__length1 = bits_length1;
				_tmp71_ = _tmp70_[0];
				if (g_strcmp0 (_tmp71_, "") == 0) {
					keystroke = 0;
				} else {
					gchar** _tmp72_;
					gint _tmp72__length1;
					const gchar* _tmp73_;
					gchar _tmp74_ = '\0';
					_tmp72_ = bits;
					_tmp72__length1 = bits_length1;
					_tmp73_ = _tmp72_[0];
					_tmp74_ = string_get (_tmp73_, (glong) 0);
					if (_tmp74_ == '"') {
						gboolean _tmp75_ = FALSE;
						gchar** _tmp76_;
						gint _tmp76__length1;
						const gchar* _tmp77_;
						gint _tmp78_;
						gint _tmp79_;
						gboolean _tmp83_;
						gchar** _tmp84_;
						gint _tmp84__length1;
						const gchar* _tmp85_;
						gchar _tmp86_ = '\0';
						_tmp76_ = bits;
						_tmp76__length1 = bits_length1;
						_tmp77_ = _tmp76_[0];
						_tmp78_ = strlen (_tmp77_);
						_tmp79_ = _tmp78_;
						if (_tmp79_ != 3) {
							_tmp75_ = TRUE;
						} else {
							gchar** _tmp80_;
							gint _tmp80__length1;
							const gchar* _tmp81_;
							gchar _tmp82_ = '\0';
							_tmp80_ = bits;
							_tmp80__length1 = bits_length1;
							_tmp81_ = _tmp80_[0];
							_tmp82_ = string_get (_tmp81_, (glong) 2);
							_tmp75_ = _tmp82_ != '"';
						}
						_tmp83_ = _tmp75_;
						if (_tmp83_) {
							bits = (_vala_array_free (bits, bits_length1, (GDestroyNotify) g_free), NULL);
							break;
						}
						_tmp84_ = bits;
						_tmp84__length1 = bits_length1;
						_tmp85_ = _tmp84_[0];
						_tmp86_ = string_get (_tmp85_, (glong) 1);
						keystroke = (gint) ((gchar) _tmp86_);
					} else {
						gchar** _tmp87_;
						gint _tmp87__length1;
						const gchar* _tmp88_;
						gint _tmp89_ = 0;
						gint _tmp90_;
						_tmp87_ = bits;
						_tmp87__length1 = bits_length1;
						_tmp88_ = _tmp87_[0];
						_tmp89_ = atoi (_tmp88_);
						keystroke = _tmp89_;
						_tmp90_ = keystroke;
						if (_tmp90_ == 0) {
							bits = (_vala_array_free (bits, bits_length1, (GDestroyNotify) g_free), NULL);
							break;
						}
					}
				}
				_tmp91_ = world;
				_tmp92_ = keystroke;
				_tmp93_ = bits;
				_tmp93__length1 = bits_length1;
				_tmp94_ = _tmp93_[1];
				_tmp95_ = bits;
				_tmp95__length1 = bits_length1;
				_tmp96_ = _tmp95_[2];
				_tmp97_ = method_new (_tmp92_, _tmp94_, _tmp96_);
				_tmp91_->keys_array = g_list_append (_tmp91_->keys_array, _tmp97_);
				good = TRUE;
				bits = (_vala_array_free (bits, bits_length1, (GDestroyNotify) g_free), NULL);
				break;
			}
			_tmp98_ = good;
			if (!_tmp98_) {
				world_wide* _tmp99_;
				dbg* _tmp100_;
				gint _tmp101_;
				gchar* _tmp102_ = NULL;
				gchar* _tmp103_;
				gchar* _tmp104_;
				gchar* _tmp105_;
				world_wide* _tmp106_;
				dbg* _tmp107_;
				gint _tmp108_;
				gchar* _tmp109_ = NULL;
				gchar* _tmp110_;
				gchar* _tmp111_;
				gchar* _tmp112_;
				const gchar* _tmp113_;
				gchar* _tmp114_;
				gchar* _tmp115_;
				_tmp99_ = world;
				_tmp100_ = _tmp99_->debug;
				_tmp101_ = count;
				_tmp102_ = g_strdup_printf ("%i", _tmp101_);
				_tmp103_ = _tmp102_;
				_tmp104_ = g_strconcat ("bad cfg at line ", _tmp103_, NULL);
				_tmp105_ = _tmp104_;
				dbg_add (_tmp100_, _tmp105_);
				_g_free0 (_tmp105_);
				_g_free0 (_tmp103_);
				_tmp106_ = world;
				_tmp107_ = _tmp106_->debug;
				_tmp108_ = count;
				_tmp109_ = g_strdup_printf ("%i", _tmp108_);
				_tmp110_ = _tmp109_;
				_tmp111_ = g_strconcat (_tmp110_, ": ", NULL);
				_tmp112_ = _tmp111_;
				_tmp113_ = line;
				_tmp114_ = g_strconcat (_tmp112_, _tmp113_, NULL);
				_tmp115_ = _tmp114_;
				dbg_add (_tmp107_, _tmp115_);
				_g_free0 (_tmp115_);
				_g_free0 (_tmp112_);
				_g_free0 (_tmp110_);
				break;
			}
		}
		_g_object_unref0 (in_stream);
		_g_object_unref0 (file);
		_g_free0 (line);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* err = NULL;
		world_wide* _tmp116_;
		dbg* _tmp117_;
		const gchar* _tmp118_;
		gchar* _tmp119_;
		gchar* _tmp120_;
		GError* _tmp121_;
		const gchar* _tmp122_;
		gchar* _tmp123_;
		gchar* _tmp124_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp116_ = world;
		_tmp117_ = _tmp116_->debug;
		_tmp118_ = cfg_file;
		_tmp119_ = g_strconcat (_tmp118_, ": ", NULL);
		_tmp120_ = _tmp119_;
		_tmp121_ = err;
		_tmp122_ = _tmp121_->message;
		_tmp123_ = g_strconcat (_tmp120_, _tmp122_, NULL);
		_tmp124_ = _tmp123_;
		dbg_add (_tmp117_, _tmp124_);
		_g_free0 (_tmp124_);
		_g_free0 (_tmp120_);
		_g_error_free0 (err);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_free0 (cfg_file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (cfg_file);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



