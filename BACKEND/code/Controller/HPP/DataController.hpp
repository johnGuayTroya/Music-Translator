
/**
*
*
*
*  @description Esta clase se encarga tratar los métodos de la clase Editor
*  y permite guardar los datos del mapa en formato .txt y serializados en .bin
*  también eincluye el método de deserialización
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

      /**Obtenemos del mapa la información necesaria*/
      std::string GetMapInfo();

      /**Usamos el metodo de la clase editor para añadir secuencias*/
      bool AddSecuence
      (
         const int secuence,
         const int min,
         const float s,
         char textInput[32]
      );
      /**Guardamos los datos extraidos del mapa en un .txt*/
      bool SaveData();
    
      /**Formateamos los datos del map y los añadimos a un archivo .bin*/
      bool SaveSerializeData();

      /**método que lee un archivo.bin y pasa sus datos a nuestro mapa*/
      bool Deserialize();

      /**Borramos la info del map usando el método de la clase Editor*/
      bool Reset();
   };
}
