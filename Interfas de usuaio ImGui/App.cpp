#include "App.h"

#include <imgui.h>
#include <imgui-SFML.h>
#include <iostream>

// Variables de puntaje

// Variables de fuente personalizada
ImFont* customFont = nullptr;

///////////////Colors////////////

sf::Color cGreyProgram(0, 0, 0, 255);

////////////////////////////////

App::App()
{
  m_pWindow = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(1920, 1080)), "Ball Game");

  ImGui::SFML::Init(*m_pWindow);

  // Cargar fuente personalizada
  ImGuiIO& io = ImGui::GetIO();
  customFont = io.Fonts->AddFontFromFileTTF("C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Interfas de usuaio ImGui/Evil.otf", 24.0f); // Ruta a tu archivo .otf o .ttf

  if (!customFont) {
    std::cerr << "Error: No se pudo cargar la fuente personalizada." << std::endl;
  }
  else {
    // Generar el atlas de fuentes
    unsigned char* pixels;
    int width, height;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

    // Crear la textura de la fuente para ImGui-SFML
    sf::Texture fontTexture(sf::Vector2u(width, height));
    fontTexture.update(pixels);

    // Asignar la textura al backend de ImGui
    ImGui::SFML::UpdateFontTexture();
  }

  // Otros inicializadores del juego
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

  std::vector<uint32*> scores;

  m_view = new View();
  ViewModel* viewModel = new ViewModel();
  player1Score = new uint32(0);
  player2Score = new uint32(0);
  viewModel->scores.push_back(player1Score);
  viewModel->scores.push_back(player2Score);
  m_view->viewModel = viewModel;

  mainloop();
}

App::~App()
{
  ImGui::SFML::Shutdown();
  delete m_view;
}

void App::mainloop()
{
  sf::Clock deltaClock;
  while (m_pWindow->isOpen()) {
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
      m_Player2.direction = sf::Vector2f(0.0f, 0.0f);
    }
  }
}


void App::update()
{
  // Movimiento de la pelota y detección de colisiones
  m_ball.m_player.setPosition(sf::Vector2f(m_ball.m_player.getPosition().x + m_ball.direction.x,
    m_ball.m_player.getPosition().y + m_ball.direction.y));

  if (m_ball.m_player.getPosition().y > 1055 || m_ball.m_player.getPosition().y < 25) {
    m_ball.direction = sf::Vector2f(m_ball.direction.x, m_ball.direction.y * -1.0f);
  }

  if (m_ball.m_player.getPosition().x > 1895 || m_ball.m_player.getPosition().x < 25) {
    if (m_ball.m_player.getPosition().x > 1895)
    {
      (*player1Score)++;
    }
    else
    {
      (*player2Score)++;
    }
    m_ball.m_player.setPosition(sf::Vector2f(960.0f, 540.0f));
  }

  m_Player1.m_player.setPosition(sf::Vector2f(m_Player1.m_player.getPosition().x + m_Player1.direction.x,
    m_Player1.m_player.getPosition().y + m_Player1.direction.y));

  m_Player2.m_player.setPosition(sf::Vector2f(m_Player2.m_player.getPosition().x + m_Player2.direction.x,
    m_Player2.m_player.getPosition().y + m_Player2.direction.y));

  // Detección de colisiones entre la pelota y los jugadores (lógica)
  if (m_ball.m_player.getPosition().y > m_Player2.m_player.getPosition().y &&
    m_ball.m_player.getPosition().y < (m_Player2.m_player.getPosition().y + 200)) {
    if (m_ball.m_player.getPosition().x > m_Player2.m_player.getPosition().x &&
      m_ball.m_player.getPosition().x < (m_Player2.m_player.getPosition().x + 30)) {
      m_ball.direction = sf::Vector2f(m_ball.direction.x * -1.0f, m_ball.direction.y * -1.0f);
    }
  }

  if (m_ball.m_player.getPosition().y > m_Player1.m_player.getPosition().y &&
    m_ball.m_player.getPosition().y < (m_Player1.m_player.getPosition().y + 200)) {
    if (m_ball.m_player.getPosition().x > m_Player1.m_player.getPosition().x &&
      m_ball.m_player.getPosition().x < (m_Player1.m_player.getPosition().x + 30)) {
      m_ball.direction = sf::Vector2f(m_ball.direction.x * -1.0f, m_ball.direction.y * -1.0f);
    }
  }
}

void App::render()
{
  m_pWindow->clear(cGreyProgram);
  m_pWindow->draw(m_ball.m_player);
  m_pWindow->draw(m_Player1.m_player);
  m_pWindow->draw(m_Player2.m_player);
  m_view->draw();
  // Usar la fuente personalizada en ImGui
  if (customFont) {
    ImGui::PushFont(customFont);
  }

  if (customFont) {
    ImGui::PopFont();
  }

  ImGui::SFML::Render(*m_pWindow);

  m_pWindow->display();
}
