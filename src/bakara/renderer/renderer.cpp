#include "renderer.h"
#include "bakara/renderer/cameras/ortho_camera.h"
#include "bakara/renderer/render_command.h"
#include "bakara/renderer/renderer2D.h"
namespace Bk 
{
    Renderer::API Renderer::s_RenderAPI = Renderer::API::Opengl;
    Renderer::Storage* Renderer::data = new Renderer::Storage();

    void Renderer::Init()
    {
        RenderCommand::Init();
        Renderer2D::Init();
    }

    void Renderer::ResizeFrame(u32 width, u32 height)
    {
        RenderCommand::SetViewport(width, height);
    }

    void Renderer::BeginScene(const OrthoCamera& camera)
    {
        data->viewProjection = camera.GetViewProjection();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(Ref<VertexArray> va, Ref<Shader> shader, Mat4 transform)
    {
        va->Bind();
        shader->Bind();
        shader->Set("u_ViewProjection", data->viewProjection);
        shader->Set("u_Transform", transform);
        RenderCommand::DrawIndexed(va);
    } 
}