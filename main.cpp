#include <iostream>
#include <dlfcn.h>

typedef void function_func();

int main(int argc, char** argv)
{
    std::cout << "Attempting to load shared module " << std::endl;
    auto handle = dlopen(argv[1], RTLD_LAZY);

    if (!handle) {
        std::cout << "Could not find shared module: " << dlerror() << std::endl;
        return -1;
    }

    std::cout << "Loaded shared module." << std::endl;

    const char* function_name = "run";

    function_func* function = reinterpret_cast<function_func*>(dlsym(handle, function_name));

    if (!function) {
        std::cout << "Could not find symbol '" << function_name << "': " << dlerror() << std::endl;
    }

    function();

    dlclose(handle);
    return 0;
}
