/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  Iteratori STL
  stl_iterator.cpp
#####################################*/

#include <vector>
#include <iostream>

int main () {

  std::vector<int> v1(3, 5);
  for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
    std::cout << *it << std::endl;
  }

  system("PAUSE"); 
  return 0;
   
}
