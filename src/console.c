/* console.c generated by valac 0.16.1, the Vala compiler
 * generated from console.vala, do not modify */

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
/* not using curses directive: I want my own refresh() function*/

#include <glib.h>
#include <glib-object.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define TYPE_CONSOLE (console_get_type ())
#define CONSOLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONSOLE, console))
#define CONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONSOLE, consoleClass))
#define IS_CONSOLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONSOLE))
#define IS_CONSOLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONSOLE))
#define CONSOLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONSOLE, consoleClass))

typedef struct _console console;
typedef struct _consoleClass consoleClass;
typedef struct _consolePrivate consolePrivate;
#define _delwin0(var) ((var == NULL) ? NULL : (var = (delwin (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _ParamSpecconsole ParamSpecconsole;

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

struct _consolePrivate {
	WINDOW* win;
};

struct _ParamSpecconsole {
	GParamSpec parent_instance;
};


static gpointer console_parent_class = NULL;

gpointer console_ref (gpointer instance);
void console_unref (gpointer instance);
GParamSpec* param_spec_console (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_console (GValue* value, gpointer v_object);
void value_take_console (GValue* value, gpointer v_object);
gpointer value_get_console (const GValue* value);
GType console_get_type (void) G_GNUC_CONST;
#define CONSOLE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_CONSOLE, consolePrivate))
enum  {
	CONSOLE_DUMMY_PROPERTY
};
#define CONSOLE_key_up ((gint) KEY_UP)
#define CONSOLE_key_down ((gint) KEY_DOWN)
#define CONSOLE_key_left ((gint) KEY_LEFT)
#define CONSOLE_key_right ((gint) KEY_RIGHT)
#define CONSOLE_key_home ((gint) KEY_HOME)
#define CONSOLE_key_end ((gint) KEY_END)
#define CONSOLE_key_ppage ((gint) KEY_PPAGE)
#define CONSOLE_key_npage ((gint) KEY_NPAGE)
#define CONSOLE_key_backspace ((gint) KEY_BACKSPACE)
#define CONSOLE_key_shift_tab 353
#define CONSOLE_key_f1 265
#define CONSOLE_key_k1 ((gint) '1')
console* console_new (void);
console* console_construct (GType object_type);
void console_end (console* self);
void console_cls (console* self);
void console_print_it (console* self, const gchar* text);
void console_print_title (console* self, const gchar* text);
void console_calculate_dimensions (console* self);
void console_print_status (console* self, const gchar* text);
void console_print_at (console* self, gint x, gint y, const gchar* text);
void console_print_inverse_at (console* self, gint x, gint y, const gchar* text);
void console_refresh (console* self);
gint console_get_key (console* self);
gint console_calculate_screen_size (console* self);
static void console_finalize (console* obj);


console* console_construct (GType object_type) {
	console* self = NULL;
	WINDOW* _tmp0_;
	WINDOW* _tmp1_;
	self = (console*) g_type_create_instance (object_type);
	initscr ();
	cbreak ();
	noecho ();
	curs_set (0);
	_tmp0_ = newwin (1, 1, 0, 0);
	_delwin0 (self->priv->win);
	self->priv->win = _tmp0_;
	_tmp1_ = self->priv->win;
	keypad (_tmp1_, TRUE);
	return self;
}


console* console_new (void) {
	return console_construct (TYPE_CONSOLE);
}


void console_end (console* self) {
	g_return_if_fail (self != NULL);
	console_cls (self);
	endwin ();
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


void console_print_it (console* self, const gchar* text) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* txt;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gint len;
	gint _tmp5_;
	gint _tmp6_;
	gint _tmp13_;
	gint _tmp14_;
	const gchar* _tmp18_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = text;
	_tmp1_ = g_strdup (_tmp0_);
	txt = _tmp1_;
	_tmp2_ = txt;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	len = (gint) _tmp4_;
	_tmp5_ = len;
	_tmp6_ = self->raw_columns;
	if (_tmp5_ < _tmp6_) {
		const gchar* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		gchar* _tmp12_;
		_tmp7_ = txt;
		_tmp8_ = self->raw_columns;
		_tmp9_ = len;
		_tmp10_ = g_strnfill ((gsize) (_tmp8_ - _tmp9_), ' ');
		_tmp11_ = _tmp10_;
		_tmp12_ = g_strconcat (_tmp7_, _tmp11_, NULL);
		_g_free0 (txt);
		txt = _tmp12_;
		_g_free0 (_tmp11_);
	}
	_tmp13_ = len;
	_tmp14_ = self->raw_columns;
	if (_tmp13_ > _tmp14_) {
		const gchar* _tmp15_;
		gint _tmp16_;
		gchar* _tmp17_ = NULL;
		_tmp15_ = txt;
		_tmp16_ = self->raw_columns;
		_tmp17_ = string_substring (_tmp15_, (glong) 0, (glong) _tmp16_);
		_g_free0 (txt);
		txt = _tmp17_;
	}
	_tmp18_ = txt;
	addstr (_tmp18_);
	_g_free0 (txt);
}


void console_print_title (console* self, const gchar* text) {
	const gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	console_calculate_dimensions (self);
	move (0, 0);
	_tmp0_ = text;
	console_print_it (self, _tmp0_);
	refresh ();
}


void console_print_status (console* self, const gchar* text) {
	gint _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	console_calculate_dimensions (self);
	_tmp0_ = self->raw_lines;
	move (_tmp0_ - 1, 0);
	_tmp1_ = text;
	console_print_it (self, _tmp1_);
	refresh ();
}


void console_print_at (console* self, gint x, gint y, const gchar* text) {
	gint _tmp0_;
	gint _tmp1_;
	const gchar* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = y;
	_tmp1_ = x;
	move (_tmp0_, _tmp1_);
	_tmp2_ = text;
	console_print_it (self, _tmp2_);
}


void console_print_inverse_at (console* self, gint x, gint y, const gchar* text) {
	gint _tmp0_;
	gint _tmp1_;
	const gchar* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = y;
	_tmp1_ = x;
	move (_tmp0_, _tmp1_);
	attron ((gulong) A_REVERSE);
	_tmp2_ = text;
	console_print_it (self, _tmp2_);
	attroff ((gulong) A_REVERSE);
}


void console_refresh (console* self) {
	g_return_if_fail (self != NULL);
	refresh ();
}


void console_cls (console* self) {
	g_return_if_fail (self != NULL);
	attroff ((gulong) A_REVERSE);
	clear ();
	refresh ();
	move (0, 0);
}


gint console_get_key (console* self) {
	gint result = 0;
	WINDOW* _tmp0_;
	gint _tmp1_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->win;
	_tmp1_ = wgetch (_tmp0_);
	result = _tmp1_;
	return result;
}


void console_calculate_dimensions (console* self) {
	g_return_if_fail (self != NULL);
	self->raw_lines = LINES;
	self->raw_columns = COLS;
}


gint console_calculate_screen_size (console* self) {
	gint result = 0;
	g_return_val_if_fail (self != NULL, 0);
	result = COLS + (LINES * 10000);
	return result;
}


static void value_console_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_console_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		console_unref (value->data[0].v_pointer);
	}
}


static void value_console_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = console_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_console_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_console_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		console* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = console_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_console_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	console** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = console_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_console (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecconsole* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_CONSOLE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_console (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CONSOLE), NULL);
	return value->data[0].v_pointer;
}


void value_set_console (GValue* value, gpointer v_object) {
	console* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CONSOLE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_CONSOLE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		console_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		console_unref (old);
	}
}


void value_take_console (GValue* value, gpointer v_object) {
	console* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_CONSOLE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_CONSOLE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		console_unref (old);
	}
}


static void console_class_init (consoleClass * klass) {
	console_parent_class = g_type_class_peek_parent (klass);
	CONSOLE_CLASS (klass)->finalize = console_finalize;
	g_type_class_add_private (klass, sizeof (consolePrivate));
}


static void console_instance_init (console * self) {
	self->priv = CONSOLE_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void console_finalize (console* obj) {
	console * self;
	self = CONSOLE (obj);
	_delwin0 (self->priv->win);
}


GType console_get_type (void) {
	static volatile gsize console_type_id__volatile = 0;
	if (g_once_init_enter (&console_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_console_init, value_console_free_value, value_console_copy_value, value_console_peek_pointer, "p", value_console_collect_value, "p", value_console_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (consoleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) console_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (console), 0, (GInstanceInitFunc) console_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType console_type_id;
		console_type_id = g_type_register_fundamental (g_type_fundamental_next (), "console", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&console_type_id__volatile, console_type_id);
	}
	return console_type_id__volatile;
}


gpointer console_ref (gpointer instance) {
	console* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void console_unref (gpointer instance) {
	console* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		CONSOLE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


