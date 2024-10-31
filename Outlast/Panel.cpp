#include "Panel.h"

UI::E Panel::draw(std::vector<Button>& buttons, std::vector<Button>& sliders){
  ImGui::SetNextWindowSize(ImVec2(panelSize.x, panelSize.y));
  ImGui::SetNextWindowPos(ImVec2(panelPosition.x, panelPosition.y));

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
    UI::E type = button.draw();
    if (type != UI::NONE)
    {
      ImGui::End(); // Cierra el panel
      ImGui::PopStyleColor(3); // Restaura el estilo original
      return type;
    }
  }


  //ImGui::EndChild(); // Finaliza la región de scroll

  ImGui::End(); // Cierra el panel
  ImGui::PopStyleColor(3); // Restaura el estilo original
}

UI::E Panel::drawSettings(std::vector<Button>& settings) {
  ImGui::SetNextWindowSize(ImVec2(panelSize.x, panelSize.y));
  ImGui::SetNextWindowPos(ImVec2(panelPosition.x, panelPosition.y)); // Usa la posición proporcionada
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
  ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
  ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));

  // Crea la ventana principal
  ImGui::Begin(panelTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

  for (auto& button : settings) {
    UI::E type = button.draw();
    if (type != UI::NONE)
    {
      ImGui::End();
      ImGui::PopStyleColor(3);
      return type;
    }
  }

  ImGui::End();
  ImGui::PopStyleColor(3);
}

UI::E Panel::drawSettingsClose(std::vector<Button>& settingsClose) {
  ImGui::SetNextWindowSize(ImVec2(panelSize.x, panelSize.y));
  ImGui::SetNextWindowPos(ImVec2(panelPosition.x, panelPosition.y)); // Usa la posición proporcionada
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
  ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));
  ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.0f, 0.0f, 0.0f, panelTransparency));

  ImGui::Begin(panelTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

  for (auto& button : settingsClose) {
    UI::E type = button.draw();
    if (type != UI::NONE)
    {
      ImGui::End();
      ImGui::PopStyleColor(3);
      return type;
    }
  }

  ImGui::End();
  ImGui::PopStyleColor(3);
}
