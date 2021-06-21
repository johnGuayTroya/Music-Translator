
#include<UnityExporter/HPP/ExportToUnity.hpp>

using namespace controller;
using namespace std;

extern "C"
{
   //todos estos métodos han de tener código defensivo a modo de if
   //devolviendo false en el caso de que algo vaya mal
  
   void * DataControllerConstructor()
   {
      auto DataC = new DataController();
      if (DataC != nullptr) { return DataC; }
      return nullptr;
   }

   bool SaveData(void *instance)
   {
      if(instance)
      {
         auto createFile = reinterpret_cast<DataController*>(instance);
         return createFile->SaveData();
      }
      return false;
   }

   bool AddSecuence
   (
     void* instance,
     const int secuence,
     const int min,
     const float s,
     char textInput[32]
   )
   {
     if(instance)
     {
        auto DataM = reinterpret_cast<DataController*>(instance);
        return DataM->AddSecuence(secuence, min, s, textInput);
     }
     return false;
   }

   bool SaveSerializeData(void* instance)
   {
      if(instance)
      {
         auto save = reinterpret_cast<DataController*>(instance);
         return save->SaveSerializeData();
      }
      return false;
   }

   bool DeserializeData(void* instance)
   {
      if(instance)
      {
        auto des= reinterpret_cast<DataController*>(instance);
        return des->Deserialize();
      }
      return false;
   }

   bool Reset(void* instance)
   {
      if(instance)
      {
         auto reset = reinterpret_cast<DataController*>(instance);
         return reset->Reset(); 
      }
      return false;
   }

}