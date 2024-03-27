cmake_minimum_required(VERSION 3.12)

project(use_gdal)

set(CMAKE_CXX_STANDARD 17)

# Set the build type if it is not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Include the GDAL submodule
add_subdirectory(submodules/gdal)

# Define your executable
add_executable(${PROJECT_NAME} main.cpp)

# Assuming 'gdal.h' is located in 'submodules/gdal/gdal'
target_include_directories(${PROJECT_NAME} PRIVATE 
  submodules/gdal/gcore/
  submodules/gdal/port/ # finds cpl_port.h
  submodules/gdal/ogr/ # finds opr_api.h
  submodules/gdal/build/gcore/ # finds gdal_version.h
  submodules/gdal/build/port/) # finds cpl_config.h

# Link your executable to GDAL
# target_link_libraries(${PROJECT_NAME} ${GDAL_LIB_TARGET_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/submodules/gdal/build/libgdal.so)


