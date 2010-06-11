/* GStreamer Editing Services
 * Copyright (C) 2010 Brandon Lewis <brandon.lewis@collabora.co.uk>
 *               2010 Nokia Corporation
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

/**
 * SECTION:ges-track-source
 * @short_description: Base Class for single-media sources
 */

#include "ges-internal.h"
#include "ges-track-object.h"
#include "ges-track-video-background-source.h"

G_DEFINE_TYPE (GESTrackVideoBackgroundSource, ges_track_vbg_src,
    GES_TYPE_TRACK_BACKGROUND_SOURCE);

enum
{
  PROP_0,
};

static void ges_track_vbg_src_dispose (GObject * object);

static void ges_track_vbg_src_finalize (GObject * object);

static void ges_track_vbg_src_get_property (GObject * object, guint
    property_id, GValue * value, GParamSpec * pspec);

static void ges_track_vbg_src_set_property (GObject * object, guint
    property_id, const GValue * value, GParamSpec * pspec);

static GstElement *ges_track_vbg_src_create_element (GESTrackBackgroundSource
    * self);

static void
ges_track_vbg_src_class_init (GESTrackVideoBackgroundSourceClass * klass)
{
  GObjectClass *object_class;
  GESTrackBackgroundSourceClass *bg_class;

  object_class = G_OBJECT_CLASS (klass);
  bg_class = GES_TRACK_BACKGROUND_SOURCE_CLASS (klass);

  object_class->get_property = ges_track_vbg_src_get_property;
  object_class->set_property = ges_track_vbg_src_set_property;
  object_class->dispose = ges_track_vbg_src_dispose;
  object_class->finalize = ges_track_vbg_src_finalize;

  bg_class->create_element = ges_track_vbg_src_create_element;
}

static void
ges_track_vbg_src_init (GESTrackVideoBackgroundSource * self)
{
}

static void
ges_track_vbg_src_dispose (GObject * object)
{
  G_OBJECT_CLASS (ges_track_vbg_src_parent_class)->dispose (object);
}

static void
ges_track_vbg_src_finalize (GObject * object)
{
  G_OBJECT_CLASS (ges_track_vbg_src_parent_class)->finalize (object);
}

static void
ges_track_vbg_src_get_property (GObject * object,
    guint property_id, GValue * value, GParamSpec * pspec)
{
  switch (property_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
ges_track_vbg_src_set_property (GObject * object,
    guint property_id, const GValue * value, GParamSpec * pspec)
{
  switch (property_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static GstElement *
ges_track_vbg_src_create_element (GESTrackBackgroundSource * self)
{
  return gst_element_factory_make ("videotestsrc", NULL);
}

GESTrackVideoBackgroundSource *
ges_track_video_background_source_new (void)
{
  return g_object_new (GES_TYPE_TRACK_VIDEO_BACKGROUND_SOURCE, NULL);
}