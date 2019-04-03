#include <iostream>
#include<time.h>
#include<windows.h>
#include<algorithm>
using namespace std;

class Quicksort{
public:
  template<typename T>
   double sortuj(T tablicaDoPosortowania[],int rozmiar, double procent,int odwrotny){
     if(odwrotny==1){ //Gdy parametr odwroty będzie = 1 to tablica zostanie posegregowana malejąco
       start=clock();
       odwrotnyquickSort(tablicaDoPosortowania,0,(rozmiar*procent)-1);
       stop=clock();
       czas=(double)(stop-start)/CLOCKS_PER_SEC;
     }else{
       start=clock();
       quickSort(tablicaDoPosortowania,0,(rozmiar*procent)-1);
       stop=clock();
       czas=(double)(stop-start)/CLOCKS_PER_SEC;
     }
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
  void quickSort(T tablica[], int indexLewy, int indexPrawy){
    if(indexLewy<indexPrawy){

      int s=PodzielTabliceRosnaco(tablica, indexLewy, indexPrawy); //s=j i=j+1 --> i=++s
      if(indexLewy<s) quickSort(tablica,indexLewy,s);
      if (indexPrawy>++s) quickSort(tablica,s,indexPrawy);

    }
}

  template<typename T>
int PodzielTabliceRosnaco(T tablica[], int l, int p){
  T wartosc_pivota=tablica[(l+p)/2];
  int i=l;
  int j=p;

  //Dopóki i nie minie się z j
  for(;i<=j;){
    while(tablica[i]<wartosc_pivota)
    i++;
    while(tablica[j]>wartosc_pivota)
    j--;
    if(i<=j){
      //Jeśli na lewo od pivota znajdziesz element wiekszy od pivota
      //a na prawo od pivota mniejszy zamien je miejscami;
      swap(tablica[i],tablica[j]);
      // Jeżeli są sobie równe to zwiększamy tylko jeden, żeby zawsze
      // po minięciu się znaczników i=j+1 .
      if(i==j){
        i++;
      }else{
      i++;
      j--;
    }
    }
  }
  return j;
  }
  template<typename T>
void odwrotnyquickSort(T tablica[], int indexLewy, int indexPrawy){
    if(indexLewy<indexPrawy){

      int s=PodzielTabliceMalejaco(tablica, indexLewy, indexPrawy);
      if(indexLewy<s) odwrotnyquickSort(tablica,indexLewy,s);
      if (indexPrawy>++s) odwrotnyquickSort(tablica,s,indexPrawy);
        }
}

  template<typename T>
int PodzielTabliceMalejaco(T tablica[], int l, int p){
  T wartosc_pivota=tablica[(l+p)/2];
  int i=l;
  int j=p;

  //Dopóki i nie minie się z j
  for(;i<=j;){
    while(tablica[i]>wartosc_pivota)
    i++;
    while(tablica[j]<wartosc_pivota)
    j--;
    if(i<=j){
      //Jeśli na lewo od pivota znajdziesz element mniejszy od pivota
      //a na prawo od pivota wiekszy zamien je miejscami;
      swap(tablica[i],tablica[j]);
      // Jeżeli są sobie równe to zwiększamy tylko jeden, żeby zawsze
      // po minięciu się znaczników i=j+1 .
      if(i==j){
        i++;
      }else{
        i++;
        j--;
      }
    }
  }

  return j;
  }
};
