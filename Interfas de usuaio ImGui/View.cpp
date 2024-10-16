#include "View.h"

#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>

void View::draw()
{
  ImGui::Begin("");
  ImGui::Text(std::to_string(viewModel->GetPlayerOneScore()).c_str());
  ImGui::End();

  ImGui::Begin("");
  ImGui::Text(std::to_string(viewModel->GetPlayerTwoScore()).c_str());
  ImGui::End();
}
