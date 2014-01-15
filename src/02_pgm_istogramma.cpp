/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <iostream>
#include <vector>
#include "Image.h"

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  std::vector<int> istogramma(256);
//  Image output;

  //Reading a greyscale image
  input.Load("./img/input_image.pgm");
  
  // allocate the output_image
  //output.Build(input.width, input.height, input.bpp);
  //copia dell'immagine, copiando i buffer
  for (int j=0; j<input.height; ++j)
   for (int i=0; i<input.width; ++i){
     istogramma[input.buffer[i + j * input.width]]++;
   }
     //output.buffer[i + j * output.width] = input.buffer[i + j * input.width];

  std::cout << "Istogramma: \n";

  for(int i=0; i<istogramma.size(); i++){
    std::cout << "colore[" << i << "] = " << istogramma[i] << "\n";
  }

  //Writing an image
  //output.Save("./img/test.pgm");
  
  return 0;
}
