/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <iostream>
#include "Image.h"

#define LUMINOSITA 150

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
     int index = i + j * output.width;

     if(input.buffer[index] < LUMINOSITA){
       output.buffer[index] = 0;
     }else{
       output.buffer[index] = input.buffer[index] - LUMINOSITA;
     }
     //output.buffer[i + j * output.width] = input.buffer[i + j * input.width];
   }

  //Writing an image
  output.Save("./img/04_abbassamento_luminosita.pgm");
  
  return 0;
}
