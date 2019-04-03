#include <iostream>
#include<time.h>
#include<windows.h>
#include<algorithm>
#include<cmath>
using namespace std;

class Introsort{
public:
    template<typename T>
double sortuj(T tablicaDoPosortowania[],int rozmiar){
  start=clock();
  int glebokoscPodzialu=(int)(2*log2(rozmiar)); //Maksymalna głębokość wywołań rekurencyjnych

  introsort(tablicaDoPosortowania,0,rozmiar-1,glebokoscPodzialu);

  stop=clock();
  czas=(double)(stop-start)/CLOCKS_PER_SEC;
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
void introsort(T tablica[], int indexLewy,int indexPrawy, int maxGlebokosc){
  if(indexLewy<indexPrawy){
    if(indexPrawy-indexLewy<10){                   // Tablice o rozmiarze<10 sortujemy przez wstawianie
      insertionsort(tablica,indexLewy,indexPrawy);
      return;
    }
    if(maxGlebokosc<=0){     //Gdy zostanie przekoczona maksymalna liczba wywołań rekurencyjnych sortujemy przez kopcowanie
      Heapsort(tablica,indexPrawy-indexLewy,indexLewy,indexPrawy);
      return;
    }else{
      int s=PodzielTabliceRosnaco(tablica, indexLewy, indexPrawy);
      if(indexLewy<s) introsort(tablica,indexLewy,s,--maxGlebokosc);
      if(indexPrawy>++s) introsort(tablica,s,indexPrawy,--maxGlebokosc);
        }
  }
}
  template<typename T>
void Heapsort(T tablica[],int rozmiar,int lewy,int prawy){

  for(int i=(prawy/2)-1;i>=lewy;i--){
    SprawdzCzyKopiecJestMax(tablica,i,prawy);
  }

  for(int i=prawy-1;i>lewy;i--){
    swap(tablica[lewy],tablica[i]);
    prawy--;                                //Odcinamy już posortowane elementy.
    SprawdzCzyKopiecJestMax(tablica,lewy,prawy); //dlatego że zabuzyliśmy kopiec
  }
}
  template<typename T>
void SprawdzCzyKopiecJestMax(T tablica[], int indexOjca, int indexOstatniego){

  int indexLewy=(indexOjca*2) +1;
  int indexPrawy=(indexOjca*2) +2;
  int indexMax=indexOjca;

  if(indexLewy<indexOstatniego && tablica[indexLewy]>tablica[indexMax]){
   indexMax=indexLewy;
  }
  if(indexPrawy<indexOstatniego && tablica[indexPrawy]>tablica[indexMax]){
   indexMax=indexPrawy;
  }
  if(indexMax!=indexOjca){
   swap(tablica[indexMax],tablica[indexOjca]);
   SprawdzCzyKopiecJestMax(tablica,indexMax,indexOstatniego);
  }

}


  template<typename T>
void insertionsort( T tab[],int l, int p){

  for(int i=l+1;i<=p;i++){
    T k=tab[i];
  int j=i-1;
  while(j>=l && tab[j]>k ){
    tab[j+1]=tab[j];
    j--;
  }
  tab[j+1]=k;
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


};
