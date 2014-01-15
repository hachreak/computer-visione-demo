/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  main function
  main.cpp
#####################################*/

#include <vector>
#include <iostream>
#include "Image.h"

typedef struct{
  int x;
  int y;
} coord;

int get_marker(std::vector<coord> *v, int y, int x){
  return -1;
}

void labelize(Image *input, std::vector< std::vector<coord> > *v){
  for (int j=0; j<(*input).height; ++j)
    for (int i=0; i<(*input).width; ++i){
      int index = i + j * (*input).width;
      // check only white pixel
      if((*input).buffer[index] == 255){
        // set a new point
        coord c;
        c.y = j;
        c.x = i;

        std::vector<coord> vector;
        int ret = get_marker(&vector, j, i);
        // check if already marked
        if(ret == -1){
          // no contained in a marker, add a new vector of points (marker)
          std::vector<coord> marker;
          // add thi point
          marker.push_back(c);
          // insert new marker in vector
          (*v).push_back(marker);
        }else{
          // add point in a marker
          vector.push_back(c);
        }
      }
    }

}

int main(int argc, char* argv[]) {

  //Declare Images buffer
  Image input;
  Image output;

  //Reading a greyscale image
  //input.Load("img/input_image.pgm");
  input.Load("img/03_output_soglia_binarizzazione.pgm");
  
  std::vector< std::vector<coord> > v;

  labelize(&input, &v);

  // allocate the output_image
  //output.Build(input.width, input.height, input.bpp);
       
  //copia dell'immagine, copiando i buffer
//  for (int j=0; j<input.height; ++j)
//   for (int i=0; i<input.width; ++i)
//     output.buffer[i + j * output.width] = input.buffer[i + j * input.width];

  //Writing an image
  output.Save("img/test.pgm");
  
  return 0;
}
