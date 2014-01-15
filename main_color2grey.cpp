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

  output.Build(input.width, input.height, 8);
       
  // doppio for per scorrere l'immagine
  // da mettere in ordine come preferisci... e' una bozza...
  for(unsigned int j=0; j<input.height; ++j)
    for(unsigned int i=0; i<input.width; ++i)
    {
      unsigned int index = i + j*input.width; // pixel "logico", e "fisico" nell'immagine greyscale
      unsigned int index_rgb = index*3; // pixel "fisico" dell'immagine a colori
    
      unsigned int r,g,b;
      r = input.buffer[index_rgb + 0];
      g = input.buffer[index_rgb + 1];
      b = input.buffer[index_rgb + 2];

      // converto (r,g,b) in greyscale pesando 1/3,1/3,1/3 le 3 componenti
      output.buffer[index] = (r + g + b)/3;
    }

  //Writing an image
  output.Save("grey_image.pgm");
  
  return 0;
}
