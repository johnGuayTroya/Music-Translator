/**
*
*  @description Esta clase define los datos que el editor va a tratar 
*  @author JAGT
*
*/
#pragma once
#include<string>

namespace model
{

   struct Data
   {
      
      //cada secuencia va a almacenar datos de tiempo
      //la secuencia va a empezar por uno
       int minute; 
       float seconds; 
      //datos de entrada de texto establecemos un limite de 32 caracteres
      char txtInput[32]="";

   };
}
