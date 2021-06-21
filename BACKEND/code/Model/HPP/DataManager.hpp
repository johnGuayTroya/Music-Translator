

#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <Model/HPP/Editor.hpp>

namespace model
{
   struct DataManager
   {
      model::Editor editor;

   public:

      /**Creamos una instancia de esta clase */
      static DataManager &instance()
      {
         static DataManager dataM;
         return dataM;
      }

   private:
      DataManager() = default;
      DataManager(const DataManager&) = default;

   };
}
