rm -rf build
cmake CMakeLists.txt -B build
make -C build
install_name_tool -add_rpath @executable_path/. build/hello