#pragma once
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <vector>
#include <iostream>

namespace UI {
  enum E
  {
    NONE = 0,
    MENU_INICIO,
    ENTRAR_A_LA_INSTALACION_MURKOFF,
    VOLVER_A_JUGAR_LA_INTRODUCCION,
    SETTINGS,
    GENERAL,
    LENGUAJE,
    CONTROLS,
    GRAPHICS,
    AUDIO,
    CONEXION,
    CREDITS,
    EXIT_TO_MENU,
    EXIT_GAME,
    EXIT_TO_CONTROL,
    EXIT_TO_GRAPHICS,
    CLASICO,
    MODERNO,
    OPCIONES_AVANZADAS,
    TACTICO,
    BRIGHT
  };
}

class Button {
public:
  Button(const std::vector<std::string> text,
         const sf::Vector2f& position,
         const sf::Vector2f& size,
         const ImVec4 Color,
         int id,
         UI::E typeUI = UI::NONE)
    : buttonText(text), buttonPosition(position), buttonSize(size), buttonBgColor(Color), m_id(id), m_typeUI(typeUI)
  {
    initializeFonts();
  }

  Button(const std::vector<std::string> text,
         float progress,
         const sf::Vector2f& position,
         const sf::Vector2f& size,
         const ImVec4 Color,
         int id)
    : buttonText(text), progress(progress), buttonPosition(position), buttonSize(size), buttonBgColor(Color), m_id(id) {}

  UI::E draw();

  void
  drawProgressBar();

  float
  getProgress() const { return progress; }

  void
  setProgress(float newProgress) { progress = newProgress; }

  void
  initializeFonts();


private:
  std::vector<std::string> buttonText;
  sf::Vector2f buttonPosition;
  sf::Vector2f buttonSize;
  ImVec4 buttonBgColor;

  float progress;
  int m_indice = 0;
  int m_id;
  UI::E m_typeUI = UI::NONE;
};


//class ProgressBar {
//public:
//  ProgressBar(const std::string& text, float progress, const sf::Vector2f& position, const sf::Vector2f& size)
//    : barText(text), progress(progress), barPosition(position), barSize(size) {}
//
//  // Dibuja la barra de progreso
//  void drawProgressBar() const {
//    ImGui::SetCursorPos(ImVec2(barPosition.x, barPosition.y)); // Posición de la barra
//    ImGui::ProgressBar(progress, ImVec2(barSize.x, barSize.y), barText.c_str());
//  }
//
//  // Permite actualizar el progreso
//  void setProgress(float newProgress) { progress = newProgress; }
//
//private:
//  std::string barText;
//  float progress;
//  sf::Vector2f barPosition;
//  sf::Vector2f barSize;
//};