#pragma once

#include <vector>

#include "Player.h"

class Model
{
  std::vector<Player> players;
  void Notify();
};