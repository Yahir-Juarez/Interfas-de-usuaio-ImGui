#pragma once

#include <vector>

#include "PlatformTypes.h"

using namespace beEngineSDK;

class ViewModel
{
 public:
  std::vector<uint32*> scores;
  void Notify();
  uint32& GetPlayerOneScore();
  uint32& GetPlayerTwoScore();
};