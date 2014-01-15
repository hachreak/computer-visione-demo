/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp

DA FARE

#####################################*/

#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Image.h"

#define APERTURA 1

/*int compute_median_value(Image *input, std::vector<int> *kernelv, std::vector<int> *kernelv, Image *output, index_y, int index_x){
  std::vector<int> neighborhood(0);

  int val1 = 0, val2 = 0;
  // load neighborhood
  for (int j = (index_x - APERTURA); j < (index_x + APERTURA + 1); ++j){
    for (int i = (index_y - APERTURA); i < (index_y + APERTURA + 1); ++i){
      int index = i + j * (*input).width;
      //neighborhood.push_back((*input).buffer[index]);
      val1 += 
    }
  }

  // sort neighborhood vector
  sort( neighborhood.begin(), neighborhood.end() );

  // return median value
  return neighborhood[(MATRIX_SIZE / 2) + 1];
}*/

int apply_sobel(Image *input, int kernelv[][3], int kernelo[][3], int index_y, int index_x){
  int index_x0 = index_x - APERTURA;
  int index_y0 = index_y - APERTURA;

  int kv_out = 0, ko_out = 0;
  for (int j = (index_x - APERTURA); j < (index_x + APERTURA + 1); ++j){
    for (int i = (index_y - APERTURA); i < (index_y + APERTURA + 1); ++i){
      int kx = j - index_x0;
      int ky = i - index_y0;
      int index = i + j * (*input).width;

      kv_out += kernelv[kx][ky] * (*input).buffer[index];
    }
  }

  return sqrt(kv_out * kv_out + ko_out * ko_out);
}

int main(int argc, char* argv[]) {

  int kernelv[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
  };

  int kernelo[3][3] = {
    {-1, -2, -1},
    { 0,  0,  0},
    { 1,  2,  1}
  };

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
   //   int med   = apply_kernel(&input, &kernelv, &kernelo, &output, i, j);
      
      output.buffer[index] = apply_sobel(&input, kernelv, kernelo, i, j);
    }
  }

  //Writing an image
  output.Save("./img/06_sobel.pgm");

  return 0;
}
