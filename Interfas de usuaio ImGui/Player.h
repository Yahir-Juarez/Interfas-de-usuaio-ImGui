#pragma once
#include "bePlatformTypes.h"
#include "GameObject.h"

using namespace beEngineSDK;

class Player : public GameObject
{
 public:
  uint32 score;
  void Up();
  void Down();
};