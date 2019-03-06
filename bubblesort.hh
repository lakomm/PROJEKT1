#include <iostream>
#include<algorithm>
#include<time.h>
#include<windows.h>
using namespace std;
clock_t start,stop;
double czas;


class Bubblesort{
public:
   void sort(int arrayToSort[],int rozmiar){
     start=clock();
    int it=0;
    bool swapped=true;
      while(it<rozmiar-1-it && swapped){
        swapped = false;
        for(int j =0;j<rozmiar-1;j++){
          if(arrayToSort[j]>arrayToSort[j+1]){
            swap(arrayToSort[j],arrayToSort[j+1]);     //swap if L<P
            swapped=true;
          }
        }
        it++;
    }
    stop=clock();
    czas=(double)(stop-start)/CLOCKS_PER_SEC;


    for(int k=0; k<rozmiar-1; ++k){
      cout<< arrayToSort[k] <<" ";
    }
    cout<<endl<<"Czas sortowania bąbelkowego: "<<czas<<" s"<<endl;
  }

  void wyswietl(int tab[],int size){
    int M=size;
    for(int k=0; k<size-1; ++k){
      cout<< tab[k] <<" "<<endl;
    }
    cout<<'\n'<<endl;
  }

};
