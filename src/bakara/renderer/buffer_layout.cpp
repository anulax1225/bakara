#include "buffer_layout.h"

namespace Bk 
{
    u32 ShaderType::Size()
    {
        switch (type) 
        {
            case None:   return 0;
            case Bool:   return 1;
            case Int:    return 4;
            case Int2:   return 4 * 2;
            case Int3:   return 4 * 3;
            case Int4:   return 4 * 4;
            case Float:  return 4;
            case Float2: return 4 * 2;
            case Float3: return 4 * 3;
            case Float4: return 4 * 4;
            case Mat3:   return 4 * 3 * 3;
            case Mat4:   return 4 * 4 * 4;
        }
    }

    u32 ShaderType::Count()
    {
        switch (type) 
        {
            case None:   return 0;
            case Bool:   return 1;
            case Int:    return 1;
            case Int2:   return 2;
            case Int3:   return 3;
            case Int4:   return 4;
            case Float:  return 1;
            case Float2: return 2;
            case Float3: return 3;
            case Float4: return 4;
            case Mat3:   return 3 * 3;
            case Mat4:   return 4 * 4;
        }
    }

    void BufferLayout::CalculteOffsetAndStride()
    {
        u32 offset = 0;
        stride = 0;
        for(auto& element : elements)
        {
            element.offset = offset;
            offset += element.type.Size();
            stride += element.type.Size();

        }

    }
}