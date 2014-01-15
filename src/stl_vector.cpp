/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  Contenitori STL
  stl_vector.cpp
#####################################*/

#include <vector>
#include <iostream>

int main () {

  // create a vector of random integers

  std::vector<int> v;
  for( int i = 0; i < 10; ++i ) {
    int num = (int) rand() % 10;
    v.push_back( num );
  }
  // print elements
  std::cout << "vector elements: ";
  for( int i = 0; i < v.size(); ++i ) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  system("PAUSE"); 
  return 0;
   
}
