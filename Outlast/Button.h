#pragma once
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <vector>
namespace UI {
  enum E
  {
    MENU = 0,
    PLAY,
    TUTORIAL,
    SETTINGS,
    CREDITS,
    EXIT
  };
}

class Button {
public:
  Button(const std::vector<std::string> text, const sf::Vector2f& position, const sf::Vector2f& size, const ImVec4 Color, int id)
    : buttonText(text), buttonPosition(position), buttonSize(size), buttonBgColor(Color), m_id(id)
  {
    initializeFonts();
  }

  Button(const std::vector<std::string> text, float progress, const sf::Vector2f& position, const sf::Vector2f& size, const ImVec4 Color, int id)
    : buttonText(text), progress(progress), buttonPosition(position), buttonSize(size), buttonBgColor(Color), m_id(id) {}

  bool draw(){
    // Configura el estilo de ImGui y posición del botón
    ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 5)); // Padding para el diseño

    // Cambia la fuente del botón
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]); // Cambia a tu fuente deseada
    ImGui::SetWindowFontScale(2); // Establece el tamaño de la fuente

    // Ajusta el color de fondo del botón con transparencia
    ImGui::PushStyleColor(ImGuiCol_Button, buttonBgColor);

    std::string buttonLabel = buttonText[m_indice] + "##" + std::to_string(m_id);
    bool isClicked = ImGui::Button(buttonLabel.c_str(), ImVec2(buttonSize.x, buttonSize.y));

    if (isClicked)
    {
      m_indice++;
      if (m_indice >= buttonText.size())
      {
        m_indice = 0;
      }
    }

    // Restaura el estilo original de ImGui
    ImGui::PopStyleColor(); // Restaura el color del botón
    ImGui::PopFont();       // Restaura la fuente original
    ImGui::PopStyleVar();   // Restaura el estilo original de ImGui

    return isClicked;
  }

  void drawProgressBar(){
    //ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));

    //ImGui::Text("%s", std::to_string(progress).c_str());

    ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));

    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.8f, 0.8f, 0.8f, 0.8f)); // Color de la "agarradera"
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(ImVec4(0.8f, 0.8f, 0.8f, 0.8f))); // Color cuando está activo
    ImGui::PushStyleColor(ImGuiCol_FrameBg, buttonBgColor);             // Color de fondo de la barra
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.8f));


    ImGui::SetNextItemWidth(buttonSize.x);

    std::string sliderLabel = "Slider##" + m_id;

    ImGui::SliderFloat(sliderLabel.c_str(), &progress, 0.0f, 1.0f, "%.1f"); // Slider interactivo

    ImGui::PopStyleColor(4);

  }

  // Obtiene el progreso actual
  float getProgress() const { return progress; }

  // Permite actualizar el progreso
  void setProgress(float newProgress) { progress = newProgress; }

  void
  initializeFonts()
  {
    static bool fontsInitialized = false;  // Para cargar la fuente solo una vez
    if (!fontsInitialized) {
      ImGuiIO& io = ImGui::GetIO();

      // Carga la fuente desde un archivo .ttf, ajusta el tamaño de la fuente según sea necesario
      ImFont* myFont = io.Fonts->AddFontFromFileTTF("C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/OutlastFont.otf", 18.0f);
      if (!myFont) {
        return;
      }
      ImGui::SFML::UpdateFontTexture();  // Actualiza la textura de fuente
      fontsInitialized = true;
    }
  }


private:
  std::vector<std::string> buttonText;
  sf::Vector2f buttonPosition;
  sf::Vector2f buttonSize;
  ImVec4 buttonBgColor;

  float progress;
  int m_indice = 0;
  int m_id;
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