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

  void draw(std::vector<Button>& buttons, std::vector<Button>& sliders) {
    ImGui::SetNextWindowSize(ImVec2(panelSize.x, panelSize.y));
    ImGui::SetNextWindowPos(ImVec2(panelPosition.x, panelPosition.y)); // Usa la posición proporcionada
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));

    // Crea la ventana principal
    ImGui::Begin(panelTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    //ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
    //ImGui::Text("%s", panelTitle.c_str());
    //ImGui::PopFont();

    // Inicia una región con scroll
    //ImGui::BeginChild("ScrollingRegion", ImVec2(panelSize.x - 20, panelSize.y - 50), true, ImGuiWindowFlags_HorizontalScrollbar);

    // Dibuja cada slider

    for (auto& slider : sliders) {
      //ImGui::SetNextItemWidth(slider.getSize().x); // Establece el ancho del slider
      slider.drawProgressBar();
    }

    for (auto& button : buttons) {
      if (button.draw()) {
        std::cout << "Click \n";
      }
    }


    //ImGui::EndChild(); // Finaliza la región de scroll

    ImGui::End(); // Cierra el panel
    ImGui::PopStyleColor(3); // Restaura el estilo original
  }

  void drawSettings(std::vector<Button>& settings)
  {
    ImGui::SetNextWindowSize(ImVec2(panelSize.x, panelSize.y));
    ImGui::SetNextWindowPos(ImVec2(panelPosition.x, panelPosition.y)); // Usa la posición proporcionada
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));

    // Crea la ventana principal
    ImGui::Begin(panelTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    for (auto& button : settings) {
      if (button.draw()) {
        std::cout << "Click \n";
      }
    }

    ImGui::End(); // Cierra el panel
    ImGui::PopStyleColor(3); // Restaura el estilo original
  }

private:
  sf::Vector2f panelSize;
  float panelTransparency;
  std::string panelTitle;
  sf::Vector2f panelPosition; // Nueva variable para la posición
};