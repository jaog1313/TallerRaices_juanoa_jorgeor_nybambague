#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

#include "biseccion.h"
#include "reglafalsa.h"
#include "newtonraphson.h"
#include "secante.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::function;


void raices_caso_1();
void raices_caso_2();

int main (int argc, char *argv[]) {
  
  //Caso 1: x^2 - cos(x)
	raices_caso_1();
  
  //Caso 2: f(x) = x^3 + 4x^2 - 10
  raices_caso_2();
  
	return 0;
}


//Caso 1:
void raices_caso_1() {
  double a = 0.0;
  double b = 2.5;
  double xr = 0.0;
  double xa = 2.0;
  double x0 = 0.0;
  double x1 = 2.0;
  double p0;
  double raiz = 0.0;
  int max_iter = 100;
  int intervalos = 100;
  int iteracciones = 100;
  double tolerancia = 100;
  
  //biseccion
  biseccion bl(
               [](double x)->double {
                 return ((x * x) - cos(x));
               },
               "f(x) = x^2 - cos(x)"
              );
  
  cout << "CALCULO DE LAS RAICES DE UNA FUNCION CASO 1\n";
  
  cout
    << "\nMetodo de biseccion:  "
    << bl.str()
    << endl;
  
  cout << "Ingrese los valores a y b del intervalo para evaluar la funcion: ";
  
  cin >> a >> b;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  bl.tabla(a, b, intervalos);
  
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
  
 
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  
  bool resultadobs = bl.raiz(
                          a,
                          b,
                          max_iter,
                          tolerancia,
                          raiz);	
  
  if(resultadobs == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
  }

  
  //Regla falsa
  reglafalsa rf(
                [](double x)->double {
                  return ((x * x) - cos(x));
                },
                "f(x) = x^2 - cos(x)"
                );
  
  cout
    << "\nMetodo de regla falsa:  "
    << rf.str()
    << endl;
  
  cout << "Ingrese los valores xr y xa del intervalo para evaluar la funcion: ";
  
  cin >> xr >> xa;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  rf.tabla(xr, xa, intervalos);
  
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  
  bool resultadorf = rf.raiz (
                           xr,
                           xa,
                          max_iter,
                          tolerancia,
                           raiz);	
  
  if(resultadorf == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados: " << endl;
  }
  
  
  //Newton-Raphson 
  newtonraphson nl(
                   [](double x)->double {
                     return ((x * x) - cos(x));
                   },
                    [](double x)->double {
                      return ((2 * x) + sin(x));
                    },
                    "f(x) = x^2 - cos(x)"
                  );
  
  cout
  << "\nMetodo de Newton-Raphson: "  
  << nl.str() 
  << endl;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  nl.tabla(a, b, intervalos);
     
  cout <<"Ingrese el valor inicial de x: ";
  cin >> p0;
  
 
  cout <<"Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  cout <<"Ingrese la cantidad de iteraciones: ";
  cin >> iteracciones;
  
  if(nl.raiz(p0, tolerancia, iteracciones, raiz)) {
    cout << "Raiz encontrada: " << raiz << endl;
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " <<endl;
  };
  
  
  //Secante
  secante sc(
             [](double x)->double {
               return ((x * x) - cos(x));
             },
             "x^2 - cos(x)"
            );
  
  cout
    << "\nMetodo de la secante:  "
    << sc.str()
    << endl;
  
  cout << "Ingrese los valores x0 y x1 del intervalo para evaluar la funcion: ";
  
  cin >> x0 >> x1;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  rf.tabla(x0, x1, intervalos);
  
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  
  bool resultadosc = sc.raiz (
                              x0,
                              x1,
                              max_iter,
                              tolerancia,
                              raiz);	
  
  if(resultadosc == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
  }
}


//Caso 2:
void raices_caso_2 (){
  double a = 0.0;
  double b = 2.5;
  double xi = 0.0;
  double xs = 2.0;
  double x0 = 0.0;
  double x1 = 2.0;
  double p0;
  double raiz = 0.0;
  int max_iter = 100;
  int intervalos = 100;
  int iteracciones = 100;
  double tolerancia = 100;
  
  //biseccion
  biseccion bl(
               [](double x) -> double {
                 return pow(x,3) + (4*(pow(x, 2))) - 10;
               },
              "f(x) = x^3 + 4x^2- 10"
              );
  
  cout << "\nCALCULO DE LAS RAICES DE UNA FUNCION CASO 2  \n";
  
  cout
    << "\nMetodo de biseccion: "
    << bl.str()
    << endl;
  
  cout << "Ingrese los valores a y b del intervalo para evaluar la funcion: ";
  
  cin >> a >> b;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  bl.tabla(a, b, intervalos);
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
    
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  bool resultadobl = bl.raiz(
                           a,
                           b,
                           max_iter,
                          tolerancia,
                           raiz);	
  
  if(resultadobl == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
  }
  
  
  //Regla falsa
  reglafalsa rf(
                [](double x) -> double {
                  return pow(x,3) + (4*(pow(x, 2))) - 10;
                },
                "f(x) = x^3 + 4x^2- 10"
               );
  
  cout
    << "\nMetodo de regla falsa:  "
    << rf.str()
    << endl;
  
  cout << "Ingrese los valores xi y xs del intervalo para evaluar la funcion: ";
  
  cin >> xi >> xs;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  rf.tabla(xi, xs, intervalos);
  
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  
  bool resultadorf = rf.raiz (
                              xi,
                              xs,
                              max_iter,
                              tolerancia,
                              raiz);	
  
  if(resultadorf == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
  }
  
    
  //netown Raphson
  newtonraphson nl(
                  [](double x) -> double {
                    return pow(x,3) + (4*(pow(x, 2))) - 10;
                  },
                  [](double x) -> double {
                    return 3 * x * 2 + 8 * x;
                  },
                  "f(x) = x^3 + 4x^2- 10"
                  );
  
 
  cout
    << "\nMetodo de Newton-Raphson: "
    << nl.str() 
    << endl;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  nl.tabla(a, b, intervalos);
  
  cout <<"Ingrese el valor inicial de x: ";
  cin >> p0;
  
  cout <<"Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  cout <<"Ingrese la cantidad de iteraciones: ";
  cin >> iteracciones;
  
  if(nl.raiz(p0, tolerancia, iteracciones, raiz)) {
    cout << "Raiz encontrada: " << raiz << endl;
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados" <<endl;
  };
  
  
  //Secante
  secante sc(
             [](double x) -> double {
               return pow(x,3) + (4*(pow(x, 2))) - 10;
             },
             "f(x) = x^3 + 4x^2- 10"
            );
  
  cout
    << "\nMetodo de la secante:  "
    << sc.str()
    << endl;
  
  cout << "Ingrese los valores x0 y x1 del intervalo para evaluar la funcion: ";
  
  cin >> x0 >> x1;
  
  cout << "Ingrese el numero de sub intervalos para imprimir la tabla: ";
  
  cin >> intervalos;
  
  rf.tabla(x0, x1, intervalos);
  
  
  cout << "Ingrese la tolerancia: ";
  cin >> tolerancia;
  
  
  cout << "Ingrese el numero maximo de iteracciones: ";
  cin >> max_iter;
  
  
  bool resultadosc = sc.raiz (
                              x0,
                              x1,
                              max_iter,
                              tolerancia,
                              raiz);	
  
  if(resultadosc == true) {
    cout << "Raiz encontrada: " << raiz << endl; 
  }else {
    cout << "No se pudo encontrar la raiz con los parametros dados " << endl;
  }
}
  

