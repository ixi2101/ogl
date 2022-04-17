cmake_minimum_required(VERSION 3.20)
project(GLTest)




set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(OpenGL_GL_PREFERENCE, "GLVND")
#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(extern/glfw)
include_directories(extern/glfw/include/GLFW/
                    extern/glew/include/)

set(OPENGL_LIBRARY ${OPENGL_LIBRARY}
        -lGL -lGLU -lXrandr -lXext -lX11 -lrt
        ${GLFW_LIBRARIES})

#GLEW
#add_subdirectory(extern/glew)
find_package(GLEW)
include_directories($(GLEW_INCLUDE_DIRS))


add_executable(GLTest src/main.cpp)
target_link_libraries(GLTest glfw OpenGL GLEW)