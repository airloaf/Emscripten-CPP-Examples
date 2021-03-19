#include <iostream>

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

int main(int argc, char *argv[]) {
    std::cout << "Hello from main" << std::endl;
}

#ifdef EMSCRIPTEN
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int sub(int x, int y) {
        return x-y;
    }
}
#endif