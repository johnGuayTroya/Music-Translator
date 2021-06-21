
/**
*
*
*
*  @description Esta clase se encarga tratar los m�todos de la clase Editor
*  y permite guardar los datos del mapa en formato .txt y serializados en .bin
*  tambi�n eincluye el m�todo de deserializaci�n
*  @author JAGT
*
*
*
*/
#pragma once
#include  <sstream>
#include  <iostream>
#include  <Model/HPP/DataManager.hpp>

namespace controller
{
   class DataController
   {
      model::Editor& editor;

   public:

      /**Creamos una instancia de nuestra clase editor*/
      DataController() :editor(model::DataManager::instance().editor) {}

   public:

      /**Obtenemos del mapa la informaci�n necesaria*/
      std::string GetMapInfo();

      /**Usamos el metodo de la clase editor para a�adir secuencias*/
      bool AddSecuence
      (
         const int secuence,
         const int min,
         const float s,
         char textInput[32]
      );
      /**Guardamos los datos extraidos del mapa en un .txt*/
      bool SaveData();
    
      /**Formateamos los datos del map y los a�adimos a un archivo .bin*/
      bool SaveSerializeData();

      /**m�todo que lee un archivo.bin y pasa sus datos a nuestro mapa*/
      bool Deserialize();

      /**Borramos la info del map usando el m�todo de la clase Editor*/
      bool Reset();
   };
}
