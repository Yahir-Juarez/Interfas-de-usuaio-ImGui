#include "App.h"

#include <imgui.h>
#include <imgui-SFML.h>

// Variables de puntaje
int player1Score = 0;
int player2Score = 0;

///////////////Colors////////////

sf::Color cGreyProgram(0, 0, 0, 255);

////////////////////////////////

App::App()
{
  m_pWindow = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(1920, 1080)), "Ball Game");
  
  ImGui::SFML::Init(*m_pWindow);

  m_Player1.m_player.setSize(sf::Vector2f(50.0f, 200.0f));
  m_Player1.m_player.setPosition(sf::Vector2f(50.0f, 50.0f));
  m_Player1.m_player.setFillColor(sf::Color::White);

  m_Player2.m_player.setSize(sf::Vector2f(50.0f, 200.0f));
  m_Player2.m_player.setPosition(sf::Vector2f(1840.0f, 830.0f));
  m_Player2.m_player.setFillColor(sf::Color::White);

  m_ball.m_player.setSize(sf::Vector2f(25.0f, 25.0f));
  m_ball.m_player.setPosition(sf::Vector2f(960.0f, 540.0f));
  m_ball.m_player.setFillColor(sf::Color::White);

  m_ball.direction = sf::Vector2f(1.0f, 1.0f);

  mainloop();
}

App::~App()
{
  ImGui::SFML::Shutdown();
}

void
App::mainloop()
{
  sf::Clock deltaClock;
  while (m_pWindow->isOpen())
  {
    input();
    update();

    ImGui::SFML::Update(*m_pWindow, deltaClock.restart());

    render();
  }
}

void
App::input()
{
  std::optional<sf::Event> event;
  while (event = m_pWindow->pollEvent()) {
    // Detección del clic del ratón
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
      m_Player1.direction = sf::Vector2f(0.0f, -1.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
      m_Player1.direction = sf::Vector2f(0.0f, 1.0f);
    }
    else
    {
      m_Player1.direction = sf::Vector2f(0.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
      m_Player2.direction = sf::Vector2f(0.0f, -1.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
      m_Player2.direction = sf::Vector2f(0.0f, 1.0f);
    }
    else
    {
      m_Player1.direction = sf::Vector2f(0.0f, 0.0f);
    }
  }
}


void
App::update()
{
  m_ball.m_player.setPosition(sf::Vector2f(m_ball.m_player.getPosition().x + m_ball.direction.x,
    m_ball.m_player.getPosition().y + m_ball.direction.y));
  if (m_ball.m_player.getPosition().y > 1055 || m_ball.m_player.getPosition().y < 25)
  {
    m_ball.direction = sf::Vector2f(m_ball.direction.x, m_ball.direction.y * -1.0f);
  }
  if (m_ball.m_player.getPosition().x > 1895 || m_ball.m_player.getPosition().x < 25)
  {
    m_ball.m_player.setPosition(sf::Vector2f(960.0f, 540.0f));
  }
  m_Player1.m_player.setPosition(sf::Vector2f(m_Player1.m_player.getPosition().x + m_Player1.direction.x,
    m_Player1.m_player.getPosition().y + m_Player1.direction.y));
  m_Player2.m_player.setPosition(sf::Vector2f(m_Player2.m_player.getPosition().x + m_Player2.direction.x,
    m_Player2.m_player.getPosition().y + m_Player2.direction.y));
}

void
App::render()
{
  m_pWindow->clear(cGreyProgram);
  m_pWindow->draw(m_ball.m_player);
  m_pWindow->draw(m_Player1.m_player);
  m_pWindow->draw(m_Player2.m_player);

  ImGui::Begin("Score");
  ImGui::Text("Player 1: %d", player1Score);
  ImGui::Text("Player 2: %d", player2Score);
  ImGui::End();

  // Renderizar ImGui en la ventana
  ImGui::SFML::Render(*m_pWindow);

  m_pWindow->display();
}