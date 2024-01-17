#pragma once

#include "mathpch.h"

namespace Bk::Math {
    class vec2 {
        public:
            float x;
            float y;

            vec2() {
                this->x = 0;
                this->y = 0;
            }
            vec2(float x, float y) {
                this->x = x;
                this->y = y;
            }
            vec2(glm::vec2 vec) {
                this->x = vec.x;
                this->y = vec.y;
            }

            glm::vec2 get_glm() {
                return glm::vec2(this->x, this->y);
            }
    };
}