# Emscripten CPP Examples
Examples showing how you can use C++, CMake and Emscripten to make both web and native applications.

## Dependencies

- [CMake](https://cmake.org/)
- [Emscripten SDK (emsdk)](https://emscripten.org/)

## Building/Compiling

The following build instructions are tailored towards Linux systems.

Note: Make sure you have installed the Emscripten SDK and you have your terminal environment setup for using the SDK commands.

```
# Create build scripts with CMake
emcmake cmake .

# Compile the code to Web Assembly (WASM)
emmake make
```

All the WASM binaries should be located in the bin folder. Now to run these WASM binaries, you will need to host the HTML files on a development server and contact the server through your web browser. I recommend using the [Live Server](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer) plugin for VSCode, although anything that can host your HTML should work.

## References

- [Compiling C++ to a WASM](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)
- [Template HTML file](https://github.com/emscripten-core/emscripten/blob/main/src/shell_minimal.html)
