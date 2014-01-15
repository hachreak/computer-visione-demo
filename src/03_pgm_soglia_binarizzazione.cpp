/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <iostream>
#include "Image.h"

#define SOGLIA 100

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  Image output;

  //Reading a greyscale image
  input.Load("./img/input_image.pgm");
  
  // allocate the output_image
  output.Build(input.width, input.height, input.bpp);
       
  //copia dell'immagine, copiando i buffer
  for (int j=0; j<input.height; ++j)
   for (int i=0; i<input.width; ++i){
     //output.buffer[i + j * output.width] = input.buffer[i + j * input.width];
     int index = i + j * input.width;

     if(input.buffer[index] > SOGLIA)
       output.buffer[index] = 255;
     else
       output.buffer[index] = 0;
   }

  //Writing an image
  output.Save("./img/03_output_soglia_binarizzazione.pgm");
  
  return 0;
}
