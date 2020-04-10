#include <iostream>
#include <dlfcn.h>

typedef const char* function_func();

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Provide a dylib name on the command line." << std::endl;
        return -1;\
    }
    std::cout << "Attempting to load shared module " << argv[1] << std::endl;
    auto handle = dlopen(argv[1], RTLD_LAZY);

    if (!handle) {
        std::cout << "Could not find shared module: " << dlerror() << std::endl;
        return -1;
    }

    std::cout << "Loaded shared module." << std::endl;

    const char* function_name = "function";

    function_func* function = reinterpret_cast<function_func*>(dlsym(handle, function_name));

    if (!function) {
        std::cout << "Could not find symbol '" << function_name << "': " << dlerror() << std::endl;
    }

    std::cout << function() << std::endl;
    dlclose(handle);
    return 0;
}
