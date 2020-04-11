#include <Python.h>
#include <iostream>

extern "C" void run()
{
    std::cout << "in run" << std::endl;
    Py_Initialize();
    std::cout << "initialized" << std::endl;
    PyRun_SimpleString(
        "from __future__ import print_function\n"
        "import sys\n"
        "print('Hello from Python {}'.format(sys.version_info[0]))\n"
    );
    std::cout << "run string" << std::endl;
    Py_Finalize();
    std::cout << "finalized" << std::endl;
}