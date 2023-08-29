#include "viewer_window.h"
#include "core/settings.h"

ViewerWindow::ViewerWindow(Viewer& app, int width,int height):
    Window{
        app,
        width,
        height,
        "oneTri",
        framebuffer_size_callback,
        cursor_position_callback,
        mouse_button_callback,
        key_callback,
        scroll_callback
    }
{

}


void ViewerWindow::update(core::App& app)
{
    Viewer& viewer = static_cast<Viewer&>(app);
    handleInput(mRawWindow, viewer);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{

    Viewer* viewer = static_cast<Viewer*>(glfwGetWindowUserPointer(window));

    viewer->setMousePos(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

    Viewer* viewer = static_cast<Viewer*>(glfwGetWindowUserPointer(window));

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Viewer* viewer = static_cast<Viewer*>(glfwGetWindowUserPointer(window));


    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        viewer->refreshShader();
    }

}

void scroll_callback(GLFWwindow* window, double dx, double dy) {
    Viewer* viewer = static_cast<Viewer*>(glfwGetWindowUserPointer(window));

}


void handleInput(GLFWwindow* window, Viewer& app) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        app.destroy();
    }
}
