#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main2() {
  sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1280, 720)), "ImGui - SFML");
  window.setFramerateLimit(60);

  ImGui::SFML::Init(window);

  sf::Clock deltaClock;

  while (window.isOpen()) {
    while (const auto wndEvent = window.pollEvent())
    {
      ImGui::SFML::ProcessEvent(window, wndEvent.value());
      if (wndEvent->is<sf::Event::Closed>())
      {
        window.close();
        break;
      }
    }

    sf::Time deltaTime = deltaClock.restart();
    ImGui::SFML::Update(window, deltaTime);

    ImGui::Begin("Hello, ImGui!");
    ImGui::Text("Hello world!");
    ImGui::End();

    window.clear(sf::Color::Blue);

    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
