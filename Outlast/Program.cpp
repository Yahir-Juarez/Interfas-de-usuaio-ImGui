#include "SFML/Graphics.hpp"
#include "Button.h"
#include <imgui-SFML.h>
#include "Panel.h"
#include <iostream>
#include <vector>

#include "AppUI.h"


int main() {

  App app;

  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(800, 600)), "SFML + ImGui Button");

  // Inicializa SFML y configura ImGui (asegúrate de inicializar ImGui adecuadamente aquí)

  while (window->isOpen()) {





    window->display();
  }

  ImGui::SFML::Shutdown();
  return 0;
}
