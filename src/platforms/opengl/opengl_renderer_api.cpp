#include "opengl_renderer_api.h"
#include <glad/glad.h>

namespace Bk 
{
    void OpenglRendererAPI::Init()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
    }

    void OpenglRendererAPI::Clear(float red, float green, float blue, float alpha)
    {
        glClearColor(red, green, blue, alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenglRendererAPI::SetViewport(u32 width, u32 height)
    {
        glViewport(0, 0, width, height);
    }

    void OpenglRendererAPI::DrawIndexed(Ref<VertexArray> va)
    {
        glDrawElements(GL_TRIANGLES, va->GetIndexbuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}