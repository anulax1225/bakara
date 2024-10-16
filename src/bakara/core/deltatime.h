#pragma once

namespace Bk
{
    class DeltaTime
    {
        public:
            DeltaTime(float time = 0.0f) : time(time)
            {}
            operator float() { return time; }
            float GetSeconds() { return time; }
            float GetMilliseconds() { return time *1000.0f; }

        private:
            float time;
    };    
}