#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ball.h"

#include "View.h"

#include <imgui.h>
#include <imgui-SFML.h>

class App
{
 public:
  /**
   * @brief 
   */
  App();
  /////////////////////////////////////////////
  
  /////////////////////////////////////////////
  /// <summary>
  /// Destruct.
  /// </summary>
  ~App();
  /////////////////////////////////////////////
  
  /////////////////////////////////////////////
  /// <summary>
  /// Start the input, update and render.
  /// </summary>
  void mainloop();
  /////////////////////////////////////////////

 
  
  /////////////////////////////////////////////
  sf::RenderWindow* m_pWindow;
  /////////////////////////////////////////////
  
 
 public:

  /////////////////////////////////////////////
  /// <summary>
  /// Record customer entries.
  /// </summary>
  void
  input();
  /////////////////////////////////////////////
  
  /////////////////////////////////////////////
  /// <summary>
  /// Updates application states.
  /// </summary>
  void
  update();
  /////////////////////////////////////////////
  
  /////////////////////////////////////////////
  /// <summary>
  /// Draw all the objects that are in the
  /// position.
  /// </summary>
  void
  render();

  Player m_Player1;
  Player m_Player2;
  Ball m_ball;

  View* m_view;
 private:
   ImFont* customFont;
   uint32* player1Score;
   uint32* player2Score;
};
