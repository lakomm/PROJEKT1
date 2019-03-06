#include <iostream>
#include<cstdlib>
#include<time.h>
#include "bubblesort.hh"
using namespace std;
int main(){
  Bubblesort B;
  srand( time( NULL ) ); //inicjowanie generatora
  int N=10000;
  int *array;
  array=new int[N];
  for(int k=0;k<N-1;++k){ //generowanie tablicy zapełnionej liczbami pseudolosowymi
    array[k]=rand() % 1001;
  }

B.wyswietl(array,N);
 B.sort(array,N);
delete array;
return 0;
}
