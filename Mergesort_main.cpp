#include <iostream>
#include<cstdlib>
#include<time.h>
#include "mergesort.hh"
using namespace std;
int main(){
  Mergesort M;
  srand( time( NULL ) ); //inicjowanie generatora
  int N=100000000;
  int *array;
  array=new int[N];
  for(int k=0;k<N-1;++k){ //generowanie tablicy zapełnionej liczbami pseudolosowymi
    array[k]=rand() % 1000001;
  }

// M.wyswietl(array,N);
 M.sort(array,N);
 // M.wyswietl(array,N);
delete array;
return 0;
}
