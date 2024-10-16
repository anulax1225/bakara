#include "opengl_renderer_api.h"
#include <glad/glad.h>

namespace Bk 
{
    void OpenglRendererAPI::Clear(float red, float green, float blue, float alpha)
    {
        glClearColor(red, green, blue, alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenglRendererAPI::DrawIndexed(Ref<VertexArray> va)
    {
        glDrawElements(GL_TRIANGLES, va->GetIndexbuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}