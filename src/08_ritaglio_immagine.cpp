/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <iostream>
#include "Image.h"

#define EDGE_LT_X 50  // Left Top
#define EDGE_LT_Y 100  // Left Top
#define EDGE_RB_X 300 // Right Bottom
#define EDGE_RB_Y 400 // Right Bottom

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
     if(j > EDGE_LT_Y && j < EDGE_RB_Y && i > EDGE_LT_X && i < EDGE_RB_X){
       int index_input  = i + j * output.width;
       int index_output = (i - EDGE_LT_X) + (j - EDGE_LT_Y) * output.width;

       output.buffer[index_output] = input.buffer[index_input];
     }
   }

  //Writing an image
  output.Save("./img/08_ritaglio_immagine.pgm");
  
  return 0;
}
