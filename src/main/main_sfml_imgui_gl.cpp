#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

//int main()
int main_sfml_imgui_gl()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // Make it the active window for OpenGL calls
    window.setActive();
    
    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Disable lighting and texturing
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, window.getSize().x, window.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    // Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
    GLfloat cube[] =
    {
        // positions    // colors (r, g, b, a)
        -50, -50, -50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50, -50,  50,  0, 0, 1, 1,
        -50,  50, -50,  0, 0, 1, 1,
        -50,  50,  50,  0, 0, 1, 1,

            50, -50, -50,  0, 1, 0, 1,
            50,  50, -50,  0, 1, 0, 1,
            50, -50,  50,  0, 1, 0, 1,
            50, -50,  50,  0, 1, 0, 1,
            50,  50, -50,  0, 1, 0, 1,
            50,  50,  50,  0, 1, 0, 1,

        -50, -50, -50,  1, 0, 0, 1,
            50, -50, -50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
        -50, -50,  50,  1, 0, 0, 1,
            50, -50, -50,  1, 0, 0, 1,
            50, -50,  50,  1, 0, 0, 1,

        -50,  50, -50,  0, 1, 1, 1,
            50,  50, -50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
        -50,  50,  50,  0, 1, 1, 1,
            50,  50, -50,  0, 1, 1, 1,
            50,  50,  50,  0, 1, 1, 1,

        -50, -50, -50,  1, 0, 1, 1,
            50, -50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
        -50,  50, -50,  1, 0, 1, 1,
            50, -50, -50,  1, 0, 1, 1,
            50,  50, -50,  1, 0, 1, 1,

        -50, -50,  50,  1, 1, 0, 1,
            50, -50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
        -50,  50,  50,  1, 1, 0, 1,
            50, -50,  50,  1, 1, 0, 1,
            50,  50,  50,  1, 1, 0, 1,
    };

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    

    //2d draw
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //https://github.com/Mischa-Alff/imgui-backends/blob/master/SFML/README.md
    //https://github.com/ocornut/imgui/issues/1064

    /*
    ImGui::Begin();
    ...
    ImGui::End();

    m_window->clear();
    m_window->draw(...);
    window->resetGLStates();
    ImGui::Render();
    m_window->display();
    */

    // Create a clock for measuring the time elapsed
    sf::Clock clock;
    sf::Clock deltaClock;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowTestWindow();
        
        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        //window.draw(shape);


        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         
        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    
    return 0;
}