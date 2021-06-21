
#include<Controller/HPP/DataController.hpp>
using namespace std;
namespace controller
{
   string DataController::GetMapInfo()
   {
      string info = "";
      auto iterator = editor.GetSecuences().begin();
      while (iterator != editor.GetSecuences().end())
      {
         //el formato que tendrán nuestro archivos de traducciones será

         string secuence = std::to_string(iterator->first) + "\n"; //secuencia
         string minute = std::to_string(iterator->second.minute) + ":"; //tiempo
         string s = std::to_string(iterator->second.seconds) + "\n";//tiempo
         string text(iterator->second.txtInput);//texto  

         info += secuence + minute + s + text;
         info += "\n"; //espacio
         ++iterator;
      }
      return info;
   }

   bool DataController::AddSecuence
   (
      const int secuence,
      const int min,
      const float s,
      char textInput[32]
   ) {return editor.AddSecuence(secuence, min, s, textInput);}
     

   bool DataController::SaveData()
   {

      std::ofstream file("./TraductionData.txt", std::ofstream::trunc | std::ofstream::out);
     
      if (file.good())
      {
         //limpiamos el archivo y luego escribimos en el 
         file.clear();

         file << GetMapInfo();
         file.close();
         return true;
      }
      
      return false;
      
   }

   bool DataController::SaveSerializeData()
   {
      std::ofstream file("./Serialize.bin", std::ofstream::trunc | std::ofstream::binary);

      auto iterator = editor.GetSecuences().begin();
      while (iterator != editor.GetSecuences().end())
      {
         file << ((char*)&iterator->first, sizeof(iterator->first)); //clave //secuencia
         file << ((char*)&iterator->second.minute, sizeof(iterator->second.minute)); //min
         file << ((char*)&iterator->second.seconds, sizeof(iterator->second.seconds)); //seg
         file << ((char*)&iterator->second.txtInput, sizeof(iterator->second.txtInput)); //txt
         ++iterator;
      }

      file.close();

      return true;
   }

   bool DataController::Deserialize()
   {
      //cacheVARs
      unsigned int secuence; int min; float seg;  char txt[32];
      
      std::ifstream file("./Serialize.bin",std::ifstream::binary);

      if(!file.good())
      {
         return false;
      }
      else
      {
         while(!file.eof())
         {
            file.read((char*)&secuence, sizeof(unsigned int));
            file.read((char*)&min, sizeof( int));
            file.read((char*)&seg, sizeof(float));
            file.read((char*)&txt, sizeof(char[32]));

            AddSecuence(secuence, min, seg, txt);
         
         }
         file.close();
         return true;
      }

   }

   bool DataController::Reset() { editor.Reset();}
}
