#include<iostream>
#include "biseccion.h"
#include "reglafalsa.h"
#include "newtonraphson.h"
#include "secante.h"

//Caso 1: x^2 - cos(x)
void raices_caso_1();

int main (int argc, char *argv[]) {
  
  //Caso 1: x^2 - cos(x)
	raices_caso_1();
  
	return 0;
}


void raices_caso_1() {
  double a = 0.0;
  double b = 2.5;
  double raiz = 0.0;
  int max_iter = 100;
  double tolerancia = 0.00001;
  /* x^2 - cos(x) */
  //biseccion
  biseccion b1(
               [](double x)->double {
                 return ((x * x) - cos(x));
               },
                 "x^2 - cos(x)"
                 );
  
  if (b1.raiz(a, b, max_iter, tolerancia, raiz)) {
    
  }
  //Regla falsa
  reglafalsa r1(
                [](double x)->double {
                  return ((x * x) - cos(x));
                },
                  "x^2 - cos(x)"
                  );
  
  double xi = 0.0;
  double xs = 2.0;
  if (r1.raiz(xi, xs, max_iter, tolerancia, raiz)) {
    
  }
  double p0 = 1.0;
  newtonraphson n1(
                   [](double x)->double {
                     return ((x * x) - cos(x));
                   },
                     [](double x)->double {
                       return ((2 * x) + sin(x));
                     },
                       "x^2 - cos(x)"
                       );
  
  if (n1.raiz(p0, max_iter, tolerancia, raiz)) {
    
  }
  
  //Secante
  secante s1(
             [](double x)->double {
               return ((x * x) - cos(x));
             },
               "x^2 - cos(x)"
               );
  
  double x0 = 0.0;
  double x1 = 2.0;
  if (s1.raiz(x0, x1, max_iter, tolerancia, raiz)) {
    
  }
}
