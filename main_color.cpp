/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main_color.cpp
#####################################*/

#include <iostream>
#include "Image.h"

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  Image output;
    
  //Reading a color image
  input.Load("lena.ppm");

  output.Build(input.width, input.height, input.bpp);
       
  // doppio for per scorrere l'immagine
  // da mettere in ordine come preferisci... e' una bozza...
  for(unsigned int j=0; j<input.height; ++j)
    for(unsigned int i=0; i<input.width; ++i)
    {
      unsigned int index = i + j*input.width; // pixel "logico"
      unsigned int index_rgb = index*3; // pixel "fisico"
    
      unsigned char r,g,b;
      r = input.buffer[index_rgb + 0];
      g = input.buffer[index_rgb + 1];
      b = input.buffer[index_rgb + 2];
      
      //copio il buffer dell'immagine niente di particolare, non ottimizzato,
      //solo didattico
      output.buffer[index_rgb + 0] = r;
      output.buffer[index_rgb + 1] = g;
      output.buffer[index_rgb + 2] = b;
    }

  //Writing an image
  output.Save("test.ppm");
  
  return 0;
}
