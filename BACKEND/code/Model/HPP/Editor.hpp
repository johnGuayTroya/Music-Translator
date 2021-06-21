/**
*
*  @description Esta clase se encarga de tratar y  almacenar en un mapa los datos
*  del struct Data
*  @author JAGT
*
*/
#pragma once
#include <map>

#include <Model/HPP/EditorData.hpp>
namespace model
{
   class Editor
   {
      //almacenamos los datos de cada secuencia 
      //la clave la usaremos como secuencia
       std::map <unsigned int, model::Data> secuences;
   public:

      Editor() = default;

   public:

      std::map<unsigned int, model::Data> &GetSecuences(); 

      /**Eliminamos todos los datos del map */
      bool Reset();
      /**Cada secuencia va a almacenar datos de tiempo y su texto asociado. 
         Añadimos la secuencia con los datos de entrada a nuestro map */
      bool AddSecuence(const int secuence, const int min, const float s, char textInput[32]);
     
      
   };

}

