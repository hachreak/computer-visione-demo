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

#define APERTURA 2
#define SIDE_SIZE (1 + 2*APERTURA)
#define MATRIX_SIZE SIDE_SIZE*SIDE_SIZE

int compute_median_value(Image *input, int index_y, int index_x){
  std::vector<int> neighborhood(0);

  // load neighborhood
  for (int j = (index_x - APERTURA); j < (index_x + APERTURA + 1); ++j){
    for (int i = (index_y - APERTURA); i < (index_y + APERTURA + 1); ++i){
      int index = i + j * (*input).width;
      neighborhood.push_back((*input).buffer[index]);
    }
  }

  // sort neighborhood vector
  sort( neighborhood.begin(), neighborhood.end() );

  // return median value
  return neighborhood[(MATRIX_SIZE / 2) + 1];
}

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  Image output;

  //Reading a greyscale image
  input.Load("./img/input_image.pgm");
  
  // allocate the output_image
  output.Build(input.width, input.height, input.bpp);

  //copia dell'immagine, copiando i buffer
  for (int j=1; j<(input.height - APERTURA); ++j){
    for (int i=1; i<(input.width - APERTURA); ++i){
      int index = i + j * input.width;
      int med   = compute_median_value(&input, i, j);
      
      output.buffer[index] = med;
    }
  }

  //Writing an image
  output.Save("./img/05_filtro_mediano.pgm");

  return 0;
}
