#include <iostream>
#include<cstdlib>
#include<ctime>
#include "bubblesort.hh"
using namespace std;
int main(){
    Bubblesort B;

  srand( time( NULL ) ); //generowanie tablicy zapełnionej liczbami pseudolosowymi
int N=100;
int array[N];
for(int k=0;k<N-1;++k){
  array[k]=rand() % 101;
}

B.wyswietl(array,N);
B.sort(array,N);
return 0;
}
