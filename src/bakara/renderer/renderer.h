#pragma once 

#include "bakara/math/types.h"
#include "bakara/renderer/cameras/ortho_camera.h"
#include "bakara/renderer/shader.h"
#include "bakara/renderer/vertex_array.h"
#include "bakatools/container/types.h"

namespace Bk 
{
    class Renderer
    {
        public:
            enum class API 
            {
                None = 0,
                Opengl = 1,
            };
        
            static API GetAPI() { return s_RenderAPI; }

            static void BeginScene(OrthographicCamera camera);
            static void EndScene();

            static void Submit(Ref<VertexArray> va, Ref<Shader> shader, Mat4 transform = Mat4(1.0f));    
        private:
            struct SceneData 
            {
                Mat4 VPMatrix;
            };
            static SceneData* sceneData;
            static API s_RenderAPI;
    };
}