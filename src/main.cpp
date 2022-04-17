#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main() {
    glewExperimental = true;
    if (!glfwInit()){
        std::cerr << "Failed to init GLFW\n";
        return -1;
    }
 
    glfwWindowHint(GLFW_SAMPLES, 4); // Antialiasng
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use newe opengl

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Tutorial1", NULL, NULL);

    if ( window == NULL ){
        std::cerr << "Failed to open GLFW window";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK){
        std::cerr << "Failed to init GLEW\n";
        return -1;
    }

}