/*#####################################
  Corso di visione artificiale
  Elaborazione di immagini in C/C++
  Algoritmi STL
  sort.cpp
#####################################*/

#include <algorithm>
#include <vector>
#include <iostream>

int main () {

   std::vector<int> v;
   v.push_back( 23 );
   v.push_back( -1 );
   v.push_back( 9999 );
   v.push_back( 0 );
   v.push_back( 4 );
 
   std::cout << "Before sorting: ";
   for( unsigned int i = 0; i < v.size(); i++ ) {
     std::cout << v[i] << " ";
   }
   std::cout << std::endl;
 
   sort( v.begin(), v.end() );
 
   std::cout << "After sorting: ";
   for( unsigned int i = 0; i < v.size(); i++ ) {
     std::cout << v[i] << " ";
   }
   std::cout << std::endl;
   
   system("PAUSE"); 
   return 0;
   
}
