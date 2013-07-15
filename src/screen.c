/* screen.c generated by valac 0.16.1, the Vala compiler
 * generated from screen.vala, do not modify */

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
#include <curses.h>
#include <gobject/gvaluecollector.h>


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

#define WORLD_WIDE_TYPE_PLAYING_TYPE (world_wide_playing_type_get_type ())
typedef struct _consolePrivate consolePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _externalPrivate externalPrivate;
typedef struct _ParamSpecscreen ParamSpecscreen;

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

struct _console {
	GTypeInstance parent_instance;
	volatile int ref_count;
	consolePrivate * priv;
	gint raw_lines;
	gint raw_columns;
};

struct _consoleClass {
	GTypeClass parent_class;
	void (*finalize) (console *self);
};

struct _external {
	screen parent_instance;
	externalPrivate * priv;
	gchar* target;
};

struct _externalClass {
	screenClass parent_class;
};

struct _ParamSpecscreen {
	GParamSpec parent_instance;
};


static gpointer screen_parent_class = NULL;

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
enum  {
	SCREEN_DUMMY_PROPERTY
};
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
GType world_wide_playing_type_get_type (void) G_GNUC_CONST;
gboolean screen_has_title (screen* self);
static gboolean screen_real_has_title (screen* self);
gchar* screen_get_title (screen* self);
static gchar* screen_real_get_title (screen* self);
void screen_advance_song (screen* self);
static void screen_real_advance_song (screen* self);
void dbg_alert (dbg* self, const gchar* text);
gint screen_get_size (screen* self);
static gint screen_real_get_size (screen* self);
gchar* screen_calc_target (screen* self, guint num);
static gchar* screen_real_calc_target (screen* self, guint num);
gchar* screen_get_line (screen* self, guint num);
static gchar* screen_real_get_line (screen* self, guint num);
world_widescreen_type screen_get_screen_type (screen* self);
static world_widescreen_type screen_real_get_screen_type (screen* self);
void screen_reset_stop (screen* self);
static void screen_real_reset_stop (screen* self);
static gint screen_window_rows (screen* self);
void screen_draw (screen* self);
static void screen_real_draw (screen* self);
void screen_zoom_to_last_line (screen* self);
void console_calculate_dimensions (console* self);
void console_print_title (console* self, const gchar* text);
void console_print_at (console* self, gint x, gint y, const gchar* text);
void console_print_inverse_at (console* self, gint x, gint y, const gchar* text);
void console_refresh (console* self);
void screen_key_press (screen* self, gint key_num);
static void screen_real_key_press (screen* self, gint key_num);
#define CONSOLE_key_up ((gint) KEY_UP)
#define CONSOLE_key_down ((gint) KEY_DOWN)
#define CONSOLE_key_home ((gint) KEY_HOME)
#define CONSOLE_key_end ((gint) KEY_END)
#define CONSOLE_key_ppage ((gint) KEY_PPAGE)
#define CONSOLE_key_npage ((gint) KEY_NPAGE)
void screen_zoom_to (screen* self, gint index);
gchar* screen_list_prefix (screen* self);
screen* screen_construct (GType object_type);
static void screen_finalize (screen* obj);


static gboolean screen_real_has_title (screen* self) {
	gboolean result = FALSE;
	result = TRUE;
	return result;
}


gboolean screen_has_title (screen* self) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SCREEN_GET_CLASS (self)->has_title (self);
}


static gchar* screen_real_get_title (screen* self) {
	gchar* result = NULL;
	gchar* _tmp0_;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


gchar* screen_get_title (screen* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return SCREEN_GET_CLASS (self)->get_title (self);
}


static void screen_real_advance_song (screen* self) {
	world_wide* _tmp0_;
	dbg* _tmp1_;
	_tmp0_ = self->world;
	_tmp1_ = _tmp0_->debug;
	dbg_alert (_tmp1_, "No advance method here");
}


void screen_advance_song (screen* self) {
	g_return_if_fail (self != NULL);
	SCREEN_GET_CLASS (self)->advance_song (self);
}


static gint screen_real_get_size (screen* self) {
	g_critical ("Type `%s' does not implement abstract method `screen_get_size'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0;
}


gint screen_get_size (screen* self) {
	g_return_val_if_fail (self != NULL, 0);
	return SCREEN_GET_CLASS (self)->get_size (self);
}


static gchar* screen_real_calc_target (screen* self, guint num) {
	gchar* result = NULL;
	gchar* _tmp0_;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


gchar* screen_calc_target (screen* self, guint num) {
	g_return_val_if_fail (self != NULL, NULL);
	return SCREEN_GET_CLASS (self)->calc_target (self, num);
}


static gchar* screen_real_get_line (screen* self, guint num) {
	g_critical ("Type `%s' does not implement abstract method `screen_get_line'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar* screen_get_line (screen* self, guint num) {
	g_return_val_if_fail (self != NULL, NULL);
	return SCREEN_GET_CLASS (self)->get_line (self, num);
}


static world_widescreen_type screen_real_get_screen_type (screen* self) {
	g_critical ("Type `%s' does not implement abstract method `screen_get_screen_type'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0;
}


world_widescreen_type screen_get_screen_type (screen* self) {
	g_return_val_if_fail (self != NULL, 0);
	return SCREEN_GET_CLASS (self)->get_screen_type (self);
}


static void screen_real_reset_stop (screen* self) {
}


void screen_reset_stop (screen* self) {
	g_return_if_fail (self != NULL);
	SCREEN_GET_CLASS (self)->reset_stop (self);
}


static gint screen_window_rows (screen* self) {
	gint result = 0;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = screen_has_title (self);
	if (_tmp0_) {
		world_wide* _tmp1_;
		console* _tmp2_;
		gint _tmp3_;
		_tmp1_ = self->world;
		_tmp2_ = _tmp1_->con;
		_tmp3_ = _tmp2_->raw_lines;
		result = _tmp3_ - 4;
		return result;
	} else {
		world_wide* _tmp4_;
		console* _tmp5_;
		gint _tmp6_;
		_tmp4_ = self->world;
		_tmp5_ = _tmp4_->con;
		_tmp6_ = _tmp5_->raw_lines;
		result = _tmp6_;
		return result;
	}
}


static void screen_real_draw (screen* self) {
	gchar* line = NULL;
	gint row = 0;
	gint row_total = 0;
	gint row_screen = 0;
	gint index = 0;
	gint size = 0;
	world_wide* _tmp0_;
	world_widescreen_type _tmp1_ = 0;
	gint _tmp2_ = 0;
	gboolean _tmp3_ = FALSE;
	gint _tmp4_;
	gboolean _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	gint _tmp9_;
	world_wide* _tmp10_;
	console* _tmp11_;
	gint _tmp12_ = 0;
	gboolean _tmp13_ = FALSE;
	gint _tmp51_;
	gint _tmp52_;
	gchar* _tmp53_ = NULL;
	gchar* target;
	const gchar* _tmp54_;
	world_wide* _tmp59_;
	console* _tmp60_;
	_tmp0_ = self->world;
	_tmp1_ = screen_get_screen_type (self);
	_tmp0_->screen_current = _tmp1_;
	_tmp2_ = screen_get_size (self);
	size = _tmp2_;
	_tmp4_ = self->row_pos;
	if (_tmp4_ < 0) {
		gint _tmp5_;
		_tmp5_ = size;
		_tmp3_ = _tmp5_ > 0;
	} else {
		_tmp3_ = FALSE;
	}
	_tmp6_ = _tmp3_;
	if (_tmp6_) {
		self->row_pos = 0;
	}
	_tmp7_ = self->screen_pos;
	_tmp8_ = self->row_pos;
	_tmp9_ = size;
	if ((_tmp7_ + _tmp8_) >= _tmp9_) {
		screen_zoom_to_last_line (self);
	}
	_tmp10_ = self->world;
	_tmp11_ = _tmp10_->con;
	console_calculate_dimensions (_tmp11_);
	_tmp12_ = screen_window_rows (self);
	row_total = _tmp12_;
	_tmp13_ = screen_has_title (self);
	if (_tmp13_) {
		world_wide* _tmp14_;
		console* _tmp15_;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		world_wide* _tmp18_;
		console* _tmp19_;
		world_wide* _tmp20_;
		console* _tmp21_;
		world_wide* _tmp22_;
		console* _tmp23_;
		gint _tmp24_;
		_tmp14_ = self->world;
		_tmp15_ = _tmp14_->con;
		_tmp16_ = screen_get_title (self);
		_tmp17_ = _tmp16_;
		console_print_title (_tmp15_, _tmp17_);
		_g_free0 (_tmp17_);
		row_screen = 2;
		_tmp18_ = self->world;
		_tmp19_ = _tmp18_->con;
		console_print_at (_tmp19_, 0, 1, "");
		_tmp20_ = self->world;
		_tmp21_ = _tmp20_->con;
		_tmp22_ = self->world;
		_tmp23_ = _tmp22_->con;
		_tmp24_ = _tmp23_->raw_lines;
		console_print_at (_tmp21_, 0, _tmp24_ - 2, "");
	} else {
		row_screen = 0;
	}
	{
		gboolean _tmp25_;
		row = 0;
		_tmp25_ = TRUE;
		while (TRUE) {
			gboolean _tmp26_;
			gint _tmp28_;
			gint _tmp29_;
			gint _tmp30_;
			gint _tmp31_;
			gint _tmp32_;
			gint _tmp33_;
			gint _tmp40_;
			gint _tmp41_;
			gint _tmp50_;
			_tmp26_ = _tmp25_;
			if (!_tmp26_) {
				gint _tmp27_;
				_tmp27_ = row;
				row = _tmp27_ + 1;
			}
			_tmp25_ = FALSE;
			_tmp28_ = row;
			_tmp29_ = row_total;
			if (!(_tmp28_ < _tmp29_)) {
				break;
			}
			_tmp30_ = self->screen_pos;
			_tmp31_ = row;
			index = _tmp30_ + _tmp31_;
			_tmp32_ = index;
			_tmp33_ = size;
			if (_tmp32_ < _tmp33_) {
				gint _tmp34_;
				gchar* _tmp35_ = NULL;
				_tmp34_ = index;
				_tmp35_ = screen_get_line (self, (guint) _tmp34_);
				_g_free0 (line);
				line = _tmp35_;
			} else {
				const gchar* _tmp36_ = NULL;
				gint _tmp37_;
				const gchar* _tmp38_;
				gchar* _tmp39_;
				_tmp37_ = row;
				if (_tmp37_ == 0) {
					_tmp36_ = "  (empty)";
				} else {
					_tmp36_ = "";
				}
				_tmp38_ = _tmp36_;
				_tmp39_ = g_strdup (_tmp38_);
				_g_free0 (line);
				line = _tmp39_;
			}
			_tmp40_ = row;
			_tmp41_ = self->row_pos;
			if (_tmp40_ == _tmp41_) {
				world_wide* _tmp42_;
				console* _tmp43_;
				gint _tmp44_;
				const gchar* _tmp45_;
				_tmp42_ = self->world;
				_tmp43_ = _tmp42_->con;
				_tmp44_ = row_screen;
				_tmp45_ = line;
				console_print_inverse_at (_tmp43_, 0, _tmp44_, _tmp45_);
			} else {
				world_wide* _tmp46_;
				console* _tmp47_;
				gint _tmp48_;
				const gchar* _tmp49_;
				_tmp46_ = self->world;
				_tmp47_ = _tmp46_->con;
				_tmp48_ = row_screen;
				_tmp49_ = line;
				console_print_at (_tmp47_, 0, _tmp48_, _tmp49_);
			}
			_tmp50_ = row_screen;
			row_screen = _tmp50_ + 1;
		}
	}
	_tmp51_ = self->screen_pos;
	_tmp52_ = self->row_pos;
	_tmp53_ = screen_calc_target (self, (guint) (_tmp51_ + _tmp52_));
	target = _tmp53_;
	_tmp54_ = target;
	if (g_strcmp0 (_tmp54_, "") != 0) {
		world_wide* _tmp55_;
		external* _tmp56_;
		const gchar* _tmp57_;
		gchar* _tmp58_;
		_tmp55_ = self->world;
		_tmp56_ = _tmp55_->ext_screen;
		_tmp57_ = target;
		_tmp58_ = g_strdup (_tmp57_);
		_g_free0 (_tmp56_->target);
		_tmp56_->target = _tmp58_;
	}
	_tmp59_ = self->world;
	_tmp60_ = _tmp59_->con;
	console_refresh (_tmp60_);
	_g_free0 (target);
	_g_free0 (line);
}


void screen_draw (screen* self) {
	g_return_if_fail (self != NULL);
	SCREEN_GET_CLASS (self)->draw (self);
}


static void screen_real_key_press (screen* self, gint key_num) {
	world_wide* _tmp0_;
	console* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	guint index;
	gint _tmp4_ = 0;
	gint size;
	gint _tmp5_ = 0;
	gint rows;
	gint _tmp6_;
	_tmp0_ = self->world;
	_tmp1_ = _tmp0_->con;
	console_calculate_dimensions (_tmp1_);
	_tmp2_ = self->screen_pos;
	_tmp3_ = self->row_pos;
	index = (guint) (_tmp2_ + _tmp3_);
	_tmp4_ = screen_get_size (self);
	size = _tmp4_;
	_tmp5_ = screen_window_rows (self);
	rows = _tmp5_;
	self->key_handled = -1;
	_tmp6_ = key_num;
	switch (_tmp6_) {
		world_wide* _tmp7_;
		console* _tmp8_;
		world_wide* _tmp13_;
		console* _tmp14_;
		world_wide* _tmp21_;
		console* _tmp22_;
		world_wide* _tmp23_;
		console* _tmp24_;
		world_wide* _tmp25_;
		console* _tmp26_;
		world_wide* _tmp30_;
		console* _tmp31_;
		_tmp7_ = self->world;
		_tmp8_ = _tmp7_->con;
		case CONSOLE_key_up:
		{
			gint _tmp9_;
			_tmp9_ = self->row_pos;
			if (_tmp9_ > 0) {
				gint _tmp10_;
				_tmp10_ = self->row_pos;
				self->row_pos = _tmp10_ - 1;
			} else {
				gint _tmp11_;
				_tmp11_ = self->screen_pos;
				if (_tmp11_ > 0) {
					gint _tmp12_;
					_tmp12_ = self->screen_pos;
					self->screen_pos = _tmp12_ - 1;
				}
			}
			screen_draw (self);
			break;
		}
		_tmp13_ = self->world;
		_tmp14_ = _tmp13_->con;
		case CONSOLE_key_down:
		{
			guint _tmp15_;
			gint _tmp16_;
			gint _tmp17_;
			gint _tmp18_;
			_tmp15_ = index;
			_tmp16_ = size;
			if ((_tmp15_ + 1) >= ((guint) _tmp16_)) {
				break;
			}
			_tmp17_ = self->row_pos;
			_tmp18_ = rows;
			if (_tmp17_ < (_tmp18_ - 1)) {
				gint _tmp19_;
				_tmp19_ = self->row_pos;
				self->row_pos = _tmp19_ + 1;
			} else {
				gint _tmp20_;
				_tmp20_ = self->screen_pos;
				self->screen_pos = _tmp20_ + 1;
			}
			screen_draw (self);
			break;
		}
		_tmp21_ = self->world;
		_tmp22_ = _tmp21_->con;
		case CONSOLE_key_home:
		{
			self->screen_pos = 0;
			self->row_pos = 0;
			screen_draw (self);
			break;
		}
		_tmp23_ = self->world;
		_tmp24_ = _tmp23_->con;
		case CONSOLE_key_end:
		{
			screen_zoom_to_last_line (self);
			screen_draw (self);
			break;
		}
		_tmp25_ = self->world;
		_tmp26_ = _tmp25_->con;
		case CONSOLE_key_ppage:
		{
			gint _tmp27_;
			gint _tmp28_;
			gint _tmp29_;
			_tmp27_ = self->screen_pos;
			_tmp28_ = rows;
			self->screen_pos = _tmp27_ - _tmp28_;
			_tmp29_ = self->screen_pos;
			if (_tmp29_ < 0) {
				self->screen_pos = 0;
				self->row_pos = 0;
			}
			screen_draw (self);
			break;
		}
		_tmp30_ = self->world;
		_tmp31_ = _tmp30_->con;
		case CONSOLE_key_npage:
		{
			gint _tmp32_;
			gint _tmp33_;
			gint _tmp34_;
			gint _tmp35_;
			gint _tmp36_;
			_tmp32_ = self->screen_pos;
			_tmp33_ = rows;
			self->screen_pos = _tmp32_ + _tmp33_;
			_tmp34_ = self->screen_pos;
			_tmp35_ = rows;
			_tmp36_ = size;
			if ((_tmp34_ + _tmp35_) > _tmp36_) {
				screen_zoom_to_last_line (self);
			}
			screen_draw (self);
			break;
		}
		default:
		{
			gint _tmp37_;
			_tmp37_ = key_num;
			self->key_handled = _tmp37_;
			break;
		}
	}
}


void screen_key_press (screen* self, gint key_num) {
	g_return_if_fail (self != NULL);
	SCREEN_GET_CLASS (self)->key_press (self, key_num);
}


void screen_zoom_to_last_line (screen* self) {
	world_wide* _tmp0_;
	console* _tmp1_;
	gint _tmp2_ = 0;
	gint size;
	gint _tmp3_ = 0;
	gint rows;
	gint _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	gint _tmp9_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->world;
	_tmp1_ = _tmp0_->con;
	console_calculate_dimensions (_tmp1_);
	_tmp2_ = screen_get_size (self);
	size = _tmp2_;
	_tmp3_ = screen_window_rows (self);
	rows = _tmp3_;
	_tmp4_ = size;
	_tmp5_ = rows;
	self->screen_pos = _tmp4_ - _tmp5_;
	_tmp6_ = self->screen_pos;
	if (_tmp6_ < 0) {
		self->screen_pos = 0;
	}
	_tmp7_ = rows;
	self->row_pos = _tmp7_ - 1;
	_tmp8_ = self->row_pos;
	_tmp9_ = size;
	if (_tmp8_ >= _tmp9_) {
		gint _tmp10_;
		_tmp10_ = size;
		self->row_pos = _tmp10_ - 1;
	}
}


void screen_zoom_to (screen* self, gint index) {
	world_wide* _tmp0_;
	console* _tmp1_;
	gint _tmp2_ = 0;
	gint rows;
	gint last_pos = 0;
	gint _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	gint _tmp15_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->world;
	_tmp1_ = _tmp0_->con;
	console_calculate_dimensions (_tmp1_);
	_tmp2_ = screen_window_rows (self);
	rows = _tmp2_;
	_tmp3_ = index;
	_tmp4_ = rows;
	self->screen_pos = _tmp3_ - (_tmp4_ / 2);
	_tmp5_ = self->screen_pos;
	if (_tmp5_ < 0) {
		gint _tmp6_;
		self->screen_pos = 0;
		_tmp6_ = index;
		self->row_pos = _tmp6_;
	} else {
		gint _tmp7_ = 0;
		gint _tmp8_;
		gint _tmp9_;
		gint _tmp10_;
		gint _tmp11_;
		gint _tmp13_;
		gint _tmp14_;
		_tmp7_ = screen_get_size (self);
		_tmp8_ = rows;
		last_pos = _tmp7_ - _tmp8_;
		_tmp9_ = last_pos;
		if (_tmp9_ < 0) {
			last_pos = 0;
		}
		_tmp10_ = self->screen_pos;
		_tmp11_ = last_pos;
		if (_tmp10_ > _tmp11_) {
			gint _tmp12_;
			_tmp12_ = last_pos;
			self->screen_pos = _tmp12_;
		}
		_tmp13_ = index;
		_tmp14_ = self->screen_pos;
		self->row_pos = _tmp13_ - _tmp14_;
	}
	_tmp15_ = self->row_pos;
	if (_tmp15_ < 0) {
		self->row_pos = 0;
	}
}


gchar* screen_list_prefix (screen* self) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	world_wide* _tmp1_;
	gboolean _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = self->world;
	_tmp2_ = _tmp1_->play_advance;
	if (_tmp2_) {
		_tmp0_ = "> ";
	} else {
		_tmp0_ = "- ";
	}
	_tmp3_ = _tmp0_;
	_tmp4_ = g_strdup (_tmp3_);
	result = _tmp4_;
	return result;
}


screen* screen_construct (GType object_type) {
	screen* self = NULL;
	self = (screen*) g_type_create_instance (object_type);
	return self;
}


static void value_screen_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_screen_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		screen_unref (value->data[0].v_pointer);
	}
}


static void value_screen_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = screen_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_screen_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_screen_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		screen* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = screen_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_screen_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	screen** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = screen_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_screen (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecscreen* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_SCREEN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_screen (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_SCREEN), NULL);
	return value->data[0].v_pointer;
}


void value_set_screen (GValue* value, gpointer v_object) {
	screen* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_SCREEN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_SCREEN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		screen_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		screen_unref (old);
	}
}


void value_take_screen (GValue* value, gpointer v_object) {
	screen* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_SCREEN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_SCREEN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		screen_unref (old);
	}
}


static void screen_class_init (screenClass * klass) {
	screen_parent_class = g_type_class_peek_parent (klass);
	SCREEN_CLASS (klass)->finalize = screen_finalize;
	SCREEN_CLASS (klass)->has_title = screen_real_has_title;
	SCREEN_CLASS (klass)->get_title = screen_real_get_title;
	SCREEN_CLASS (klass)->advance_song = screen_real_advance_song;
	SCREEN_CLASS (klass)->get_size = screen_real_get_size;
	SCREEN_CLASS (klass)->calc_target = screen_real_calc_target;
	SCREEN_CLASS (klass)->get_line = screen_real_get_line;
	SCREEN_CLASS (klass)->get_screen_type = screen_real_get_screen_type;
	SCREEN_CLASS (klass)->reset_stop = screen_real_reset_stop;
	SCREEN_CLASS (klass)->draw = screen_real_draw;
	SCREEN_CLASS (klass)->key_press = screen_real_key_press;
}


static void screen_instance_init (screen * self) {
	self->screen_pos = 0;
	self->row_pos = 0;
	self->last_screen = WORLD_WIDE_SCREEN_TYPE_none;
	self->ref_count = 1;
}


static void screen_finalize (screen* obj) {
	screen * self;
	world_wide* _tmp0_;
	screen* _tmp1_;
	self = SCREEN (obj);
	_tmp0_ = self->world;
	_tmp1_ = _tmp0_->playing_screen;
	if (_tmp1_ == self) {
		world_wide* _tmp2_;
		_tmp2_ = self->world;
		_tmp2_->playing_screen = NULL;
	}
}


GType screen_get_type (void) {
	static volatile gsize screen_type_id__volatile = 0;
	if (g_once_init_enter (&screen_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_screen_init, value_screen_free_value, value_screen_copy_value, value_screen_peek_pointer, "p", value_screen_collect_value, "p", value_screen_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (screenClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) screen_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (screen), 0, (GInstanceInitFunc) screen_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType screen_type_id;
		screen_type_id = g_type_register_fundamental (g_type_fundamental_next (), "screen", &g_define_type_info, &g_define_type_fundamental_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&screen_type_id__volatile, screen_type_id);
	}
	return screen_type_id__volatile;
}


gpointer screen_ref (gpointer instance) {
	screen* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void screen_unref (gpointer instance) {
	screen* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SCREEN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


