cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(modify_light)

find_package(ignition-cmake2 REQUIRED)
find_package(ignition-plugin1 REQUIRED COMPONENTS register)
set(IGN_PLUGIN_VER ${ignition-plugin1_VERSION_MAJOR})

find_package(ignition-gazebo6 REQUIRED)

add_library(ModifyLight SHARED src/modify_light_plugin.cpp)
target_include_directories(ModifyLight PUBLIC include)
set_property(TARGET ModifyLight PROPERTY CXX_STANDARD 17)
target_link_libraries(ModifyLight
  PRIVATE ignition-plugin${IGN_PLUGIN_VER}::ignition-plugin${IGN_PLUGIN_VER}
  PRIVATE ignition-gazebo6::ignition-gazebo6)
