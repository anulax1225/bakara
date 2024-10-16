#include "render_command.h"
#include "bakara/renderer/renderer_api.h"
#include "platforms/opengl/opengl_renderer_api.h"

namespace Bk 
{
    RendererAPI* RenderCommand::rendererAPI = new OpenglRendererAPI();
}