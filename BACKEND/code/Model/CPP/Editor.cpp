

#include<Model/HPP/Editor.hpp>

namespace model
{
   std::map<unsigned int, model::Data> & Editor::GetSecuences() { return secuences; }

   bool Editor::Reset() { secuences.clear(); return true; }

   bool Editor::AddSecuence(const int secuence, const int min, const float s, char textInput[32])
   {
      //la secuencia va a empezar por uno
      Data CacheData;
      CacheData.minute = min;
      CacheData.seconds = s;
      //copiamos el valor de los argumentos  a nuestros char
      memcpy(CacheData.txtInput, textInput, strlen(textInput) + 1);

      secuences[secuence]= CacheData;

      return true;
   }

}

