#include "GameObject.h"
#include "V3.h"

#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

int main()
{
    /*V3 v = NewV3(0.0F, 0.0F, 0.0F);
    GameObject o = NewGObject("e", NewV3(0.0F, 0.0F, 0.0F), NewV3(2.0F, 2.0F, 2.0F), NewV3(0.0F, 0.0F, 0.0F));
    GameObject b = NewGObject("t", NewV3(2.0F, 0.0F, 0.0F), NewV3(1.0F, 1.0F, 1.0F), NewV3(0.0F, 0.0F, 0.0F));
    if (IsColliding(o, b))
    {
        printf("collided\n");
    }
    else
    {
        printf("did not collide\n");
    }*/
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    return 0;
}