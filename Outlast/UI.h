#pragma once

#include <vector>

#include "Button.h"
#include "Panel.h"

class UIClass
{
 public:
   UIClass(sf::RenderWindow& window,
           std::string Path)
   {
     m_window = &window;
     m_textureButton = new sf::Texture(Path.c_str(), false, sf::IntRect());
     m_bottom.setPosition(sf::Vector2f(0, 0));
     m_bottom.setSize(sf::Vector2f(1920, 1080));
     m_bottom.setTexture(m_textureButton);
   }

  void drawUI()
  {
    m_window->draw(m_bottom);
  }

  Panel m_panel;
  Panel m_panelSettings;
  Panel m_panelSettingsClose;
  std::vector<Button> m_buttons;
  std::vector<Button> m_SliderBars;
  std::vector<Button> m_Settings;
  std::vector<Button> m_SettingsClose;
  sf::Texture* m_textureButton;

  sf::RectangleShape m_bottom;

  sf::RenderWindow* m_window;
};