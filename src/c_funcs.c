/*
 *
 * check_tag exists:
 * program gives out lots of assertion warnings without this check
 *
 */

#include <glib.h>
#include <gst/gst.h>


gboolean check_tag_exists (const void* list, const gchar* tag)
{
  const GValue *value;

  if (!GST_IS_TAG_LIST (list))
    return FALSE;
  
  value = gst_tag_list_get_value_index ((const GstTagList*) list, tag, 0);

  if (value == NULL)
    return FALSE;

  return G_VALUE_HOLDS_STRING (value);
}


void taglist_foreach_job (const GstTagList *list, GstTagForeachFunc func, gpointer user_data)
{
  gst_tag_list_foreach (list, func, user_data);
}

