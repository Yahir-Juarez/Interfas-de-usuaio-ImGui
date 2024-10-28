#include "View.h"

#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>

void View::draw()
{
  // Activa la fuente personalizada, si está disponible
  if (ImGui::GetIO().Fonts->Fonts.Size > 0) {
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
  }

  // Establece la posición en pantalla para el texto (opcional)
  ImGui::SetCursorPos(ImVec2(50, 50));  // Coordenadas desde la esquina superior izquierda

  // Muestra el puntaje del jugador 1
  int playerOneScore = viewModel->GetPlayerOneScore();
  ImGui::Text("Puntaje del Jugador 1: %d", playerOneScore);

  // Muestra el puntaje del jugador 2
  int playerTwoScore = viewModel->GetPlayerTwoScore();
  ImGui::Text("Puntaje del Jugador 2: %d", playerTwoScore);

  // Restablece la fuente si fue cambiada
  if (ImGui::GetIO().Fonts->Fonts.Size > 0) {
    ImGui::PopFont();
  }
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
