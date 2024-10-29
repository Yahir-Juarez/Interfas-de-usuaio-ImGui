#include "View.h"

#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>

void View::draw()
{
  // Puntaje del Jugador 1
  ImGui::SetNextWindowPos(ImVec2(50, 20)); 
  ImGui::Begin("Puntaje del Jugador 1", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar);

  ImGui::Text("Puntaje: %d", viewModel->GetPlayerOneScore());

  ImGui::End();

  ImGui::SetNextWindowPos(ImVec2(1780, 20)); 
  ImGui::Begin("Puntaje del Jugador 2", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar);

  ImGui::Text("Puntaje: %d", viewModel->GetPlayerTwoScore());

  ImGui::End();
}

void
View::initializeFonts()
{
  static bool fontsInitialized = false;  // Para cargar la fuente solo una vez
  if (!fontsInitialized) {
    ImGuiIO& io = ImGui::GetIO();

    // Carga la fuente desde un archivo .ttf, ajusta el tamaño de la fuente según sea necesario
    ImFont* myFont = io.Fonts->AddFontFromFileTTF("C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Interfas de usuaio ImGui/Evil.otf", 18.0f);
    if (!myFont) {
      std::cerr << "Error: No se pudo cargar la fuente." << std::endl;
      return;
    }
    ImGui::SFML::UpdateFontTexture();  // Actualiza la textura de fuente
    fontsInitialized = true;
  }
}
