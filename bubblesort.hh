#include <iostream>
#include<algorithm>
using namespace std;

class Bubblesort{
public:
   void sort(int arrayToSort[],int rozmiar){
    int it=0;
      while(it<rozmiar-1){
        for(int j =0;j<rozmiar-1;j++){
          if(arrayToSort[j]>arrayToSort[j+1]){
            swap(arrayToSort[j],arrayToSort[j+1]);     //swap if L<P
          }
        }
        it++;
    }
    for(int k=0; k<rozmiar-1; ++k){
      cout<< arrayToSort[k] <<" ";
    }
  }

  void wyswietl(int tab[],int size){
    int M=size;
    for(int k=0; k<size-1; ++k){
      cout<< tab[k] <<" "<<endl;
    }
    cout<<'\n'<<endl;
  }

};
