//#include <SFML/Graphics.hpp>
//#include <imgui.h>
//#include <imgui-SFML.h>
//#include <iostream>

#include "App.h"

int main() {
  App app;

  return 0;

  //sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML + ImGui");
  //window.setFramerateLimit(60);

  //ImGui::SFML::Init(window);

  //sf::Clock deltaClock;  // Declara deltaClock aquí, antes del bucle

  //while (window.isOpen()) {

  //  ImGui::SFML::Update(window, deltaClock.restart());

  //  // Dibuja un botón simple sin panel
  //  ImGui::SetNextWindowPos(ImVec2(200, 200), ImGuiCond_Always); // Posición del botón
  //  ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_Always);    // Sin tamaño de ventana adicional
  //  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);      // Sin borde
  //  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0)); // Sin padding

  //  // Crea una ventana transparente y sin título para el botón
  //  ImGui::Begin("##InvisibleWindow", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
  //  if (ImGui::Button("Boton Simple")) {
  //    // Acción del botón
  //    printf("¡Boton presionado!\n");
  //  }
  //  ImGui::End();

  //  ImGui::PopStyleVar(2); // Restaurar estilos

  //  window.clear();
  //  ImGui::SFML::Render(window);
  //  window.display();
  //}


  //ImGui::SFML::Shutdown();




  //// Crea la ventana de SFML
  //sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML + ImGui");
  //window.setFramerateLimit(60);

  //// Inicializa ImGui-SFML
  //ImGui::SFML::Init(window);

  //// Cargar una fuente personalizada
  //ImGuiIO& io = ImGui::GetIO();
  //ImFont* myFont = io.Fonts->AddFontFromFileTTF("C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Interfas de usuaio ImGui/Evil.otf", 24.0f); // Ruta a tu archivo .otf o .ttf
  //if (!myFont) {
  //  std::cerr << "Error: No se pudo cargar la fuente." << std::endl;
  //  return -1;
  //}
  //else {
  //  // Generar el atlas de fuentes
  //  unsigned char* pixels;
  //  int width, height;
  //  io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

  //  // Crear la textura de la fuente para SFML
  //  sf::Texture fontTexture(sf::Vector2u(width, height));
  //  fontTexture.update(pixels);

  //  // Asignar la textura al backend de ImGui
  //  ImGui::SFML::UpdateFontTexture();
  //}

  //sf::Clock deltaClock;

  //// Bucle principal
  //while (window.isOpen()) {

  //  // Iniciar frame de ImGui
  //  ImGui::SFML::Update(window, deltaClock.restart());

  //  // Aquí puedes dibujar la interfaz ImGui
  //  ImGui::Begin("Ventana ImGui");

  //  // Aplica la fuente personalizada
  //  ImGui::PushFont(myFont);
  //  ImGui::Text("Texto con fuente personalizada (OTF)");
  //  ImGui::PopFont();

  //  ImGui::End();

  //  // Limpiar la ventana de SFML
  //  window.clear();

  //  // Renderiza ImGui sobre la ventana de SFML
  //  ImGui::SFML::Render(window);

  //  // Mostrar el frame en la ventana de SFML
  //  window.display();
  //}

  //// Cerrar ImGui-SFML antes de salir
  //ImGui::SFML::Shutdown();

  //return 0;
}
