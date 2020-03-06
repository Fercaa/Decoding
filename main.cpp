#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void desencriptar(string codigo, char codsalida[],char arr[]){
  int x=0,lineas;
  for (int i;i<10;i++){
    codsalida[i]='A';
  }
  lineas=codigo.length();
  strcpy(arr,codigo.c_str());
  while (x<lineas){
    switch(arr[x]){
      case '2':
        codsalida[x]='0';
        break;

      case 'R':
        codsalida[x]='1';
        break;

      case 'T':
        codsalida[x]='2';
        break;

      case 'L':
        codsalida[x]='3';
        break;

      case '%':
        codsalida[x]='4';
        break;

      case '&':
        codsalida[x]='5';
        break;

      case '#':
        codsalida[x]='6';
        break;

      case 'D':
        codsalida[x]='7';
        break;

      case 'Y':
        codsalida[x]='8';
        break;

      case 'X':
        codsalida[x]='9';
        break;
    }
  x++;
  }
  for(int y; y<=9; y++){
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
  char arr[10];
  char arr2[10];
  char letra;
  cout<<"Teclea un nombre para el archivo de entrada"<<endl;
  getline(cin, nombreEnt);
  cout<<"Teclea un nombre para el archivo de salida"<<endl;
  getline(cin,nombreSal);

  nombreEnt+=".txt";
  nombreSal+=".txt";
  ofstream archEnt;
  archEnt.open(nombreEnt.c_str());
  archEnt<<"/ 2 R T L % & # D Y X ! F 4 3 "<<endl;
  //        / 0 1 2 3 4 5 6 7 8 9 + - * /
  archEnt<<"%#RT 4 T2Y"<<endl<<"T%Y# F &LR"<<endl<<"XDT%2 3 RT#"<<endl<<"TL%0 ! %DR"<<endl<<"T&L 3 R#Y"<<endl<<"T%TR 4 XR"<<endl<<"#2&L F &2R"<<endl<<"&$ 3 RL"<<endl<<"%#D 4 &L"<<endl<<"RD2X 3 L%"<<endl<<"YR ! RT"<<endl<<"%T ! DRT"<<endl<<"L# F T2"<<endl<<"#D 4 &R"<<endl<<"XD 3 RL";

  archEnt.close();

  ifstream archEntrada;
  archEntrada.open(nombreEnt.c_str());
  ofstream archSalida;
  archSalida.open(nombreSal.c_str());
  while(archEntrada>>cod1>>cod3>>cod2){
    i++;
    if(i>5){
      desencriptar(cod1,codsal,arr);
      desencriptar(cod2,codsal2,arr2);
      switch(cod3){
        case '!':
          intsal=atoi(codsal);
          intsal2=atoi(codsal2);
          resultado=intsal + intsal2;
          archSalida<<intsal<<" + "<<intsal2<<" = "<<resultado<<endl;
          break;

        case 'F':
          intsal=atoi(codsal);
          intsal2=atoi(codsal2);
          resultado=intsal - intsal2;            archSalida<<intsal<<" - "<<intsal2<<" = "<<resultado<<endl;
          break;

        case '4':
          intsal=atoi(codsal);
          intsal2=atoi(codsal2);
          resultado=intsal * intsal2;
          archSalida<<intsal<<" * "<<intsal2<<" = "<<resultado<<endl;
          break;

        case '3':
          intsal=atoi(codsal);
          intsal2=atoi(codsal2);
          resultado=intsal / intsal2;
          archSalida<<intsal<<" / "<<intsal2<<" = "<<resultado<<endl;
          break;
      }
      for(int y; y<9;y++){
        codsal[y]='A';
        codsal2[y]='A';
      }
    }
  }
  return 0;
}
