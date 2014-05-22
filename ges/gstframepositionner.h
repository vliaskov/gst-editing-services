/* GStreamer
 * Copyright (C) 2013 Mathieu Duponchelle <mduponchelle1@gmail.com>
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

#ifndef _GST_FRAME_POSITIONNER_H_
#define _GST_FRAME_POSITIONNER_H_

#include <gst/base/gstbasetransform.h>
#include <ges/ges-track-element.h>
#include <ges/ges-track.h>

G_BEGIN_DECLS

#define GST_TYPE_FRAME_POSITIONNER   (gst_frame_positionner_get_type())
#define GST_FRAME_POSITIONNER(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_FRAME_POSITIONNER,GstFramePositionner))
#define GST_FRAME_POSITIONNER_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_FRAME_POSITIONNER,GstFramePositionnerClass))
#define GST_IS_FRAME_POSITIONNER(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_FRAME_POSITIONNER))
#define GST_IS_FRAME_POSITIONNER_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_FRAME_POSITIONNER))

typedef struct _GstFramePositionner GstFramePositionner;
typedef struct _GstFramePositionnerClass GstFramePositionnerClass;
typedef struct _GstFramePositionnerMeta GstFramePositionnerMeta;

struct _GstFramePositionner
{
  GstBaseTransform base_framepositionner;

  GstElement *capsfilter;

  GstElement *videocrop;

  GESTrackElement *track_source;
  GESTrack *current_track;

  gdouble alpha;
  gint posx;
  gint posy;
  guint zorder;
  gint width;
  gint height;
  gint track_width;
  gint track_height;
  gint fps_n;
  gint fps_d;
  gint crop_bottom;
  gint crop_top;
  gint crop_right;
  gint crop_left;

  /*  This should never be made public, no padding needed */
};

struct _GstFramePositionnerClass
{
  GstBaseTransformClass base_framepositionner_class;
};

struct _GstFramePositionnerMeta {
  GstMeta meta;

  gdouble alpha;
  gint posx;
  gint posy;
  guint zorder;
};

void ges_frame_positionner_set_source_and_filter (GstFramePositionner *pos,
						  GESTrackElement *trksrc,
						  GstElement *capsfilter, GstElement *videocrop);
GType gst_frame_positionner_get_type (void);
GType
gst_frame_positionner_meta_api_get_type (void);

G_END_DECLS

#endif
