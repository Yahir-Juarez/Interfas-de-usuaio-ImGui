#include "ViewModel.h"

uint32& ViewModel::GetPlayerOneScore()
{
  return *scores[0];
}

uint32& ViewModel::GetPlayerTwoScore()
{
  return *scores[1];
}
