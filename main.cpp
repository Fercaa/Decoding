#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void desencriptar(string codigo, char codsalida[],char arr[],char cod[]){
  int x=0,lineas;
  for (int i=0;i<10;i++){
    codsalida[i]='A';
  }
  lineas=codigo.length();
  strcpy(arr,codigo.c_str());
  while (x<lineas){
    for(int r=0;r<11;r++){
      if(arr[x]==cod[r]){
        codsalida[x]=r+'0';
      }
    }
    x++;
  }
  for(int y=0; y<=9; y++){
    arr[y]='A';
  }
}

int main() {
  string nombreEnt;
  string nombreSal;
  string cod1, cod2;
  char codsal[10],codsal2[10];
  int lineas, x=0, intsal,intsal2, resultado, i=0;
  char cod3;
  char temp;
  char arr[10];
  char arr2[10];
  char letra;
  char codigo[14];
  cout<<"Teclea un nombre para el archivo de entrada"<<endl;
  getline(cin, nombreEnt);
  cout<<"Teclea un nombre para el archivo de salida"<<endl;
  getline(cin,nombreSal);

  nombreEnt+=".txt";
  nombreSal+=".txt";
  ifstream archEntrada;
  archEntrada.open(nombreEnt.c_str());
  ofstream archSalida;
  archSalida.open(nombreSal.c_str());

  while(archEntrada>> temp){
  if (i<=13){
    codigo[i]=temp;
  }
    while((i>12)&&(archEntrada>>cod1>>cod3>>cod2)){
        desencriptar(cod1,codsal,arr,codigo);
        desencriptar(cod2,codsal2,arr2,codigo);
        if (cod3==codigo[10]){
            intsal=atoi(codsal);
            intsal2=atoi(codsal2);
            resultado=intsal + intsal2;
            archSalida<<intsal<<" + "<<intsal2<<" = "<<resultado<<endl;
        }
         if (cod3==codigo[11]){
            intsal=atoi(codsal);
            intsal2=atoi(codsal2);
            resultado=intsal - intsal2;
            archSalida<<intsal<<" - "<<intsal2<<" = "<<resultado<<endl;
        }
         if (cod3==codigo[12]){
            intsal=atoi(codsal);
            intsal2=atoi(codsal2);
            resultado=intsal * intsal2;
            archSalida<<intsal<<" * "<<intsal2<<" = "<<resultado<<endl;
        }
        if (cod3==codigo[13]){
            intsal=atoi(codsal);
            intsal2=atoi(codsal2);
            resultado=intsal / intsal2;
            archSalida<<intsal<<" / "<<intsal2<<" = "<<resultado<<endl;
        }
        for(int y=0; y<9;y++){
          codsal[y]='A';
          codsal2[y]='A';
        }
    }
    i++;
  }
  archSalida.close();
  return 0;
}

