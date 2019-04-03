#include<iostream>
#include<fstream>
#include<time.h>
clock_t start,stop;
double czas;
#include"quicksort.hh"
#include"mergesort.hh"
#include "introsort.hh"

class Test{

public:

template<typename T>
void testuj(){
  Quicksort Q;
  Mergesort M;
  Introsort I;

  //##############################################################################
  //TWORZENIE DWUWYMIAROWEJ TABLICY DYNAMICZNEJ
  srand( time( NULL ) ); //inicjowanie generatora
  int N=1000000;
  int ilosc_wierszy=100;

  T **array1;
  array1 = new T *[ilosc_wierszy]; //przydzielenie pamięci na w wierszy

  for(int i=0;i<ilosc_wierszy;i++){
    array1[i] = new T[N];         //przydzielenie pamieci na N kolumn
  }
  //############################################################################
  int cases[5]={10000,50000,100000,500000,1000000}; //Kolejne rozmiary tablic
  double procenty[8]={0,0.25,0.50,0.75,0.95,0.99,0.997,1};// Kolejne wartosci procentowe wstępnego sortowania
  double P;
  int O;
  double sredni_czas=0;
  std::fstream plik;

  //********************QUICKSORT***********************************
  plik.open( "Quicksort.txt", std::ios::in | std::ios::out );

  if( plik.good() == true ){
    for(int i=0;i<8;i++){
      P=procenty[i];
      O=P;       //Dla O=1 tablica będzie wstępnie posortowana malejąco.
      plik<< '\n'<<"Tablica wstępnie posortowana w "<< P*100<<" %";
      for(int i=0;i<5;i++){
        N=cases[i];        //
        plik<< '\n'<<"Czas sortowania szybkiego dla tablicy zawierającej "<< N <<" elementów:"<<'\n';
        for(int i=0;i<ilosc_wierszy;i++){
          for(int k=0;k<N;k++){ //wypełnianie tablicy liczbami pseudolosowymi
            array1[i][k]=rand() % 1000001;
          }
          Q.sortuj(array1[i],N,P,O);// Wstępne sortowanie z wykorzystaniem quicksorta
                                  // N-rozmiar tablicy,
                                  //P*100 = procent w jakim tablica ma byc posortowana
                                  //O- gdy ==1 tablica bedzie posortowana malejąco
          sredni_czas=sredni_czas+(Q.sortuj(array1[i],N,1,0)); //Sortowanie właściwe
        }
        plik<<sredni_czas/ilosc_wierszy<<'\n';  //Zapis sredniego czasu sortowania do pliku
        sredni_czas=0;
      }
    }
  } else std::cout << "Brak pliku" << std::endl;
  plik.close();

//******************INTROSORT************************
  plik.open( "Introsort.txt", std::ios::in | std::ios::out );

  if( plik.good() == true ){
    for(int i=0;i<8;i++){
      P=procenty[i];          //Dla P=1 będzie przypadek, gdy tablica jest posortowana malejąco
      O=P;
      plik<< '\n'<<"Tablica wstępnie posortowana w "<< P*100<<" %";
      for(int i=0;i<5;i++){
        N=cases[i];        //
        plik<< '\n'<<"Czas sortowania introspektywnego dla tablicy zawierającej "<< N <<" elementów:"<<'\n';
        for(int i=0;i<ilosc_wierszy;i++){
          for(int k=0;k<N;k++){ //wypełnianie tablicy liczbami pseudolosowymi
            array1[i][k]=rand() %1000001;
          }
          Q.sortuj(array1[i],N,P,O);
          sredni_czas=sredni_czas+(I.sortuj(array1[i],N));
        }
        plik<<sredni_czas/ilosc_wierszy<<'\n';
        sredni_czas=0;
      }
    }
  } else std::cout << "Brak pliku" << std::endl;
  plik.close();

  //***************************MERGESORT*************************************
  plik.open( "Mergesort.txt", std::ios::in | std::ios::out );

  if( plik.good() == true ){
    for(int i=0;i<8;i++){
      P=procenty[i];          //Dla P=1 będzie przypadek, gdy tablica jest posortowana malejąco
      O=P;
      plik<< '\n'<<"Tablica wstępnie posortowana w "<< P*100<<" %";
      for(int i=0;i<5;i++){
        N=cases[i];        //
        plik<< '\n'<<"Czas sortowania przez scalanie dla tablicy zawierającej "<< N <<" elementów:"<<'\n';
        for(int i=0;i<ilosc_wierszy;i++){
          for(int k=0;k<N;k++){ //wypełnianie tablicy liczbami pseudolosowymi
            array1[i][k]=rand() % 1000001;
          }
          Q.sortuj(array1[i],N,P,O);
          sredni_czas=sredni_czas+(M.sortuj(array1[i],N));
        }
        plik<<sredni_czas/ilosc_wierszy<<'\n';
        sredni_czas=0;
      }
    }
  } else std::cout << "Brak pliku" << std::endl;
  plik.close();
  //##############################################################################
  // ZWALNIANIE PAMIĘCI
  //##############################################################################
  for(int i=0;i<ilosc_wierszy;i++)
  delete [] array1[i];

  delete [] *array1;
}
};
