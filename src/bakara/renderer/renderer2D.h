#pragma once

#include "bakara/renderer/shader.h"
#include "bakara/renderer/texture.h"
#include "bakara/renderer/vertex_array.h"
#include "cameras/ortho_camera.h"

namespace Bk 
{
    class Renderer2D 
    {
        public:
            static void Init();
            static void Shutdown();

            static void BeginScene(const OrthoCamera& camera);
            static void EndScene();

            static void DrawQuad(const Vec2& position, const Vec2& size, const Color& color);
            static void DrawQuad(const Vec3& position, const Vec2& size, const Color& color);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture);
            static void DrawQuad(const Vec3& position, const Vec2& size, const Ref<Texture2D>& texture);
        private:
            struct Storage
            {
                Mat4 viewProjection;
                Ref<VertexArray> squareVA;
                ShaderLibrary shaderLib;
            };   

            static Storage* data;         
    };
}