#include "Button.h"

UI::E Button::draw() {
  ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));
  ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 5));

  ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
  ImGui::SetWindowFontScale(2);

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

  ImGui::PopStyleColor();
  ImGui::PopFont();
  ImGui::PopStyleVar();

  if (isClicked)
  {
    std::cout << "Click \n";
    return m_typeUI;
  }
  return UI::NONE;
}

void Button::drawProgressBar() {
  //ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));

  //ImGui::Text("%s", std::to_string(progress).c_str());

  ImGui::SetCursorPos(ImVec2(buttonPosition.x, buttonPosition.y));

  ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.8f, 0.8f, 0.8f, 0.8f)); // Color de la "agarradera"
  ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(ImVec4(0.8f, 0.8f, 0.8f, 0.8f))); // Color cuando está activo
  ImGui::PushStyleColor(ImGuiCol_FrameBg, buttonBgColor);             // Color de fondo de la barra
  ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0.8f));


  ImGui::SetNextItemWidth(buttonSize.x);

  std::string sliderLabel = buttonText[m_indice] + "##" + std::to_string(m_id);

  ImGui::SliderFloat(sliderLabel.c_str(), &progress, 0.0f, 1.0f, "%.1f");

  ImGui::PopStyleColor(4);

}

void Button::initializeFonts() {
  static bool fontsInitialized = false;
  if (!fontsInitialized) {
    ImGuiIO& io = ImGui::GetIO();

    ImFont* myFont = io.Fonts->AddFontFromFileTTF(
      "C:/Users/super/OneDrive/Escritorio/Septimo/Interfas de usuaio ImGui/Outlast/OutlastFont.otf",
      18.0f);
    if (!myFont) {
      return;
    }
    ImGui::SFML::UpdateFontTexture(); 
    fontsInitialized = true;
  }
}
