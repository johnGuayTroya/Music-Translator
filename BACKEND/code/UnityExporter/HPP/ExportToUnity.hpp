/**
*
* @description En esta clase defnimos las funciones a exportar a Unity
* @author JAGT
* 
*/

#pragma once
#include<Controller/HPP/DataController.hpp>
#define EXPORTED_FUNCTION __declspec(dllexport)

extern "C"
{
   // void * es un puntero a algún tipo de dato

   /**Creamos el DataController para exportarlo y usarlo en Unity */
   EXPORTED_FUNCTION void * DataControllerConstructor();

   //El resto de funciones que definimos a continuación las  vamos a exportar a Unity

   EXPORTED_FUNCTION bool SaveData(void* instance);  

   EXPORTED_FUNCTION bool AddSecuence
   (
      void* instance,
      const int secuence,
      const int min,
      const float s,
      char textInput[32]
   );

   EXPORTED_FUNCTION bool SaveSerializeData(void* instance);

   EXPORTED_FUNCTION bool DeserializeData(void* instance);

   EXPORTED_FUNCTION bool Reset(void* instance);

   

}