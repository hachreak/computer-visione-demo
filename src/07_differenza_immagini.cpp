/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp

#####################################*/

#include <algorithm>
#include <vector>
#include <iostream>
#include "Image.h"

#define SOGLIA 70

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input1, input2;
  Image output;

  //Reading a greyscale image
  input2.Load("./img/background_image.pgm");
  input1.Load("./img/input_image.pgm");
  
  // allocate the output_image
  output.Build(input1.width, input1.height, input1.bpp);

  //copia dell'immagine, copiando i buffer
  for (int j=1; j<input1.height; ++j){
    for (int i=1; i<input1.width; ++i){
      int index = i + j * input1.width;

      if(input1.buffer[index] > input2.buffer[index])
        output.buffer[index] = 0;
      else
        output.buffer[index] = input2.buffer[index] - input1.buffer[index];

//      abs(input1.buffer[i] - input2.buffer[i]) > 30 ? output.buffer[i] = input1.buffer[i] : output.buffer[i] = 0;

#ifdef BINARIZATION
      if(output.buffer[index] > SOGLIA)
        output.buffer[index] = 255;
      else
        output.buffer[index] = 0;
#endif
    }
  }

  //Writing an image
  output.Save("./img/07_differenza_immagini.pgm");

  return 0;
}
