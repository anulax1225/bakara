#pragma once

/*! \file bakara.h
Precompiled headers for external pragrams.
*/

/*! \namespace Bk
Global namespace doc
*/
namespace Bk {}

/*! \namespace Bk::Plaform
Plaform namespace doc
*/
namespace Bk::Plaform {}

namespace Baka = Bk;

#include <bakara/math/types.h>

#include <bakara/io/io_codes.h>
#include <bakara/io/keyboard.h>
#include <bakara/io/mouse.h>
#include <bakara/events/events.h>
#include <bakara/core/application.h>
#include <bakara/core/layer.h>

#include <bakara/renderer/cameras/ortho_camera.h>

#include <bakara/renderer/render_command.h>
#include <bakara/renderer/renderer.h>

#include <bakara/renderer/buffer.h>
#include <bakara/renderer/buffer_layout.h>
#include <bakara/renderer/shader.h>
#include <bakara/renderer/vertex_array.h>