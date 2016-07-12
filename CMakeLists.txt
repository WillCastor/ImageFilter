cmake_minimum_required(VERSION 3.0)

project(ImageFilter)

add_compile_options(-std=c++11)

include_directories(/usr/local/include/GraphicsMagick)
link_directories(/usr/local/lib)
link_libraries(GraphicsMagick++ GraphicsMagick tiff freetype jpeg png16 Xext SM ICE X11 lzma bz2 xml2 z m gomp pthread)

add_executable(main main.cpp ImageCore.cpp ImageCore.h)