#pragma once

#include "ViewModel.h"

class View
{
 public:

   View()
   {
     initializeFonts();
   }

  void draw();
  ViewModel* viewModel;

private:
  void initializeFonts();
};