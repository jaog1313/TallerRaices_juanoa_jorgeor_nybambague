#ifndef BISECCION_H
#define BISECCION_H

#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

using std::function;
using std::cout;
using std::endl;
using std::setw; 
using std::string;

class biseccion {
public:
  /**
  * @brief Crea una nueva instancia de biseccion.
  * @param p_func refrencia a la funcion
  * @param s_func representacion como cadena
  */
  biseccion(
            function<double(double)> p_func,
            string p_str
          ):func(p_func),str_func(p_str) {
  }
  
  double f(double x) {
    return func(x);
    
  }
  
  string str() {
    return str_func;
  }  
  
  
  void tabla(double a, double b, int intervalos ) {
    double paso = (b-a)/intervalos;
    cout << str() << endl;
    cout
      <<setw(10)
      <<"x"
      <<setw(10)
      <<"f(x)"
      << endl;
    while (a < b + paso) {
      cout
        <<setw(10)
        <<a
        <<setw(10)
        <<f(a)
        << endl;
      a += paso;	
    }
  }
  
    
  bool raiz(double a, 
            double b, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    if (f(a) * f(b) > 0.0 ) {
      return false;
    }
    
    int i = 1;
    double x_ant = (a + b)/2.0;
    
    //Encontramos la raiz en la primera aproximacion
    double fx = f(x_ant);
    if(fabs(fx) < tolerancia) {
      valor_raiz = x_ant;
      return true;
    }
    
    if(f(a) * f(x_ant) < 0) {
      //No hay cambio de signo 
      b = x_ant;
    }else {
      a = x_ant;
    }
    
    while (i <= max_iter) {
      double x_nueva = (a + b)/2.0;
      double er = fabs((x_nueva - x_ant)/x_nueva);
      if(fabs(f(x_nueva))< tolerancia || er < tolerancia) {
        valor_raiz = x_nueva;
        
        return true;
      }
      i++;
      if(f(a) * f(x_nueva) < 0.0) {
        b = x_nueva;
      }else {
        a = x_nueva;
      }
      x_ant = x_nueva;
    }
    return false;
  }
  
private:
  function<double(double)> func;
  string str_func;
  
  
};

#endif
