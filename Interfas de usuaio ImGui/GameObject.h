#pragma once

#include "SFML/Graphics.hpp"

class GameObject
{
 public:
  sf::Vector2f position;
  void Start();
  void Update(const float& deltaMS);
  float speed;
  sf::Vector2f direction;
  sf::RectangleShape m_player;
};