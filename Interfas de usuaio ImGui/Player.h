#pragma once
#include "PlatformTypes.h"
#include "GameObject.h"

using namespace beEngineSDK;

class Player : public GameObject
{
 public:
  uint32 score;
  void Up();
  void Down();
};