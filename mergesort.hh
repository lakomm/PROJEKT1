#include <iostream>
#include<time.h>
#include<algorithm>
#include<cstdlib>
#include<windows.h>
using namespace std;


class Mergesort{
public:
    template<typename T>
   double sortuj(T tablicaDoPosortowania[],int rozmiar){
     start=clock();

     T *dodTablica;
     dodTablica=new T[rozmiar];

     mergeSort(tablicaDoPosortowania, 0, rozmiar-1, dodTablica);

    stop=clock();
    czas=(double)(stop-start)/CLOCKS_PER_SEC;
    delete dodTablica;
    return czas;
  }
  template<typename T>
  void wyswietl(T tab[],int size){
    for(int k=0; k<size; k++){
      cout<< tab[k] <<" ";
    }
    cout<<'\n'<<endl;
  }

private:

  template<typename T>
  void mergeSort(T tablicaDoPosortowania[], int indexLewy, int indexPrawy,T dTablica[]){

      if(indexLewy < indexPrawy){
        int srodek=(indexLewy+indexPrawy)/2; //Dzielenie na dwa problemy
        mergeSort(tablicaDoPosortowania, indexLewy, srodek, dTablica);//wywołanie sortowania dla lewego podproblemu
        mergeSort(tablicaDoPosortowania, srodek+1, indexPrawy, dTablica);//wywołanie sortowania dla prawego podproblemu
        merge(tablicaDoPosortowania,indexLewy ,srodek, indexPrawy, dTablica);//Scalanie o
      }

  }
  template<typename T>
  void merge(T TablicaDoPosortowania[],int indexLewy ,int srodek,int indexPrawy, T dodatkowaTablica[]){
    for(int i = indexLewy; i <= indexPrawy; i++){    //przepisanie tablicy
      dodatkowaTablica[i]=TablicaDoPosortowania[i];
    }

    int wsk1 = indexLewy;
    int wsk2 = srodek+1;
    int obecny = indexLewy;
    while(wsk1 <= srodek && wsk2 <= indexPrawy){
      if(dodatkowaTablica[wsk1] <= dodatkowaTablica[wsk2]){
        TablicaDoPosortowania[obecny] = dodatkowaTablica[wsk1];
        wsk1++;
      }else{
        TablicaDoPosortowania[obecny] = dodatkowaTablica[wsk2];
        wsk2++;
      }
      obecny++;
    }
    while(wsk1 <= srodek){      //Warunek, gdy wsk2 >indexPrawy
      TablicaDoPosortowania[obecny] = dodatkowaTablica[wsk1];
      wsk1++;
      obecny++;
    }
}
};
