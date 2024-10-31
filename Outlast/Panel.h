#pragma once

#include "SFML/Graphics.hpp"
#include "Button.h"
#include <imgui-SFML.h>

#include <iostream>
#include <vector>

class Panel {
public:

  Panel() = default;
  Panel(const sf::Vector2f& size, float transparency, const std::string& title, const sf::Vector2f& position)
    : panelSize(size), panelTransparency(transparency), panelTitle(title), panelPosition(position) {}

  UI::E draw(std::vector<Button>& buttons, std::vector<Button>& sliders);

  UI::E drawSettings(std::vector<Button>& settings);

  UI::E drawSettingsClose(std::vector<Button>& settingsClose);

private:
  sf::Vector2f panelSize;
  float panelTransparency;
  std::string panelTitle;
  sf::Vector2f panelPosition; // Nueva variable para la posición
};