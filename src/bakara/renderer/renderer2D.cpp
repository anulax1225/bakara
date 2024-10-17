#include "renderer2D.h"
#include "bakara/renderer/buffer.h"
#include "bakara/renderer/buffer_layout.h"
#include "bakara/renderer/render_command.h"
#include "bakara/renderer/texture.h"

namespace Bk 
{
    Renderer2D::Storage* Renderer2D::data = new Renderer2D::Storage();

    void Renderer2D::Init()
    {
        data->shaderLib.Load("assets/shaders/flatColor.glsl");
        data->shaderLib.Load("assets/shaders/texture.glsl");
        data->squareVA = VertexArray::Create();

        float squareVertices[5 * 4]  = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f
        };
        Ref<VertexBuffer> squareVB = VertexBuffer::Create(squareVertices, sizeof(squareVertices));
        squareVB->SetLayout({
            { ShaderType::Float3, "a_Position" },
            { ShaderType::Float2, "a_TextCord" }
        });
        data->squareVA->AddVertexBuffer(squareVB);

        u32 squareIndices[6] = { 0, 1, 2, 0, 2, 3 };
        data->squareVA->SetIndexbuffer(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(u32))); 
    }

    void Renderer2D::Shutdown()
    {
        delete data;
    }

    void Renderer2D::BeginScene(const OrthoCamera &camera)
    {
        data->viewProjection = camera.GetViewProjection();   
    }

    void Renderer2D::EndScene()
    {

    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Color& color)
    {
        Renderer2D::DrawQuad(Vec3(position, 0), size, color);
    }

    void Renderer2D::DrawQuad(const Vec3& position, const Vec2& size, const Color& color)
    {
        Ref<Shader> shader = data->shaderLib["flatColor"];
        data->squareVA->Bind();
        shader->Bind();
        shader->Set("u_FlatColor", color);
        shader->Set("u_ViewProjection", data->viewProjection);
        shader->Set("u_Transform", Math::scale(Math::translate(Mat4(1.0f), position), Vec3(size, 0)));
        RenderCommand::DrawIndexed(data->squareVA);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture)
    {
        Renderer2D::DrawQuad(Vec3(position, 0), size, texture);
    }

    void Renderer2D::DrawQuad(const Vec3& position, const Vec2& size, const Ref<Texture2D>& texture)
    {
        Ref<Shader> shader = data->shaderLib["texture"];
        data->squareVA->Bind();
        texture->Bind();
        shader->Bind();
        shader->Set("u_Texture", 0);
        shader->Set("u_ViewProjection", data->viewProjection);
        shader->Set("u_Transform", Math::scale(Math::translate(Mat4(1.0f), position), Vec3(size, 0)));
        RenderCommand::DrawIndexed(data->squareVA);
    }
}