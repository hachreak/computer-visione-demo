/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <iostream>
#include "Image.h"

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  Image output;

  //Reading a greyscale image
  input.Load("input_image.pgm");
  
  // allocate the output_image
  output.Build(input.width, input.height, input.bpp);
       
  //copia dell'immagine, copiando i buffer
  for (int j=0; j<input.height; ++j)
   for (int i=0; i<input.width; ++i)
     output.buffer[i + j * output.width] = input.buffer[i + j * input.width];

  //Writing an image
  output.Save("test.pgm");
  
  return 0;
}
