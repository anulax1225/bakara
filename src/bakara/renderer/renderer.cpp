#include "renderer.h"
#include "bakara/renderer/cameras/ortho_camera.h"
#include "bakara/renderer/render_command.h"
namespace Bk 
{
    Renderer::API Renderer::s_RenderAPI = Renderer::API::Opengl;
    Renderer::SceneData* Renderer::sceneData = new Renderer::SceneData();

    void Renderer::BeginScene(OrthographicCamera camera)
    {
        sceneData->VPMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(Ref<VertexArray> va, Ref<Shader> shader, Mat4 transform)
    {
        va->Bind();
        shader->Bind();
        shader->Set("viewProjection", sceneData->VPMatrix);
        shader->Set("transform", transform);
        RenderCommand::DrawIndexed(va);
    } 
}