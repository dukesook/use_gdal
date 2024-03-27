# Adding GDAL to your program

### Add as Submodule

- mkdir submodules
- git submodules add https://github.com/OSGeo/gdal.git

### Build GDAL submodule

- cd submodules/gdal/
- mkdir build && cd build
- cmake ..
- cmake --build . -- -j24

### Write CMakeLists.txt

- set(CMAKE_CXX_STANDARD 17)
- Include target directories
  - gdal/gcore/
  - gdal/port/
  - gdal/ogr/h
  - gdal/build/gcore/
  - gdal/build/port/
- Link Library
  - gdal/build/libgdal.so

### main.cpp

- #include <gdal.h>
- #include <gdal_priv.h>
