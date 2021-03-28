#include <iostream>
#include "SimpleMath.h"

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

#ifdef EMSCRIPTEN
extern "C"
{
    EMSCRIPTEN_KEEPALIVE
#endif

    int fact(int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }

        return mul(n, fact(n - 1));
    }

#ifdef EMSCRIPTEN
}
#endif

int main(int argc, char *argv[])
{
    std::cout << "4! = " << fact(4);
    return 0;
}