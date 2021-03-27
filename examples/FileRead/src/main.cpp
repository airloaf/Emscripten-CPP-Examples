#include <fstream>
#include <iostream>
#include <string>

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

#ifdef EMSCRIPTEN
extern "C"
{
EMSCRIPTEN_KEEPALIVE
#endif
    void readFile(std::string filePath)
    {
        std::fstream file(filePath);

        if (!file.good())
        {
            std::cout << "Could not open file: " << filePath << std::endl;
            file.close();
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

        file.close();
    }
#ifdef EMSCRIPTEN
}
#endif

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        readFile(std::string(argv[1]));
    }

    return 0;
}