#ifndef REGLAFALSA_H
#define REGLAFALSA_H
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std:: function;

class reglafalsa {
public:
  reglafalsa(
            function<double(double)> p_func,
            string p_str
            ):func(p_func),str_func(p_str) {
  }

  int iteraciones=0;
  
  double f(double x){
    return func(x);
  }
    
  string str(){
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
    
    int contador=1;
    if (f(a) * f(b) > 0.0 ) {
      return false;
    }
    double xr, xa = a;
    
    while(contador < max_iter){
      xr = b - f(b) * ((a - b) / (f(a) - f(b)));
      double er = (xr -a) / xr;
      if (fabs(er) <= tolerancia) {
        iteraciones = contador;
        valor_raiz = xr;
        return true;
      } 
      else {  
        if (f(xr) * f(a) < 0) {  
          b = xr;
          //xr = a - f(a) * ((b - a) / (f(b) - f(a)));
        } else {
          a = xr;
          //xr = b - f(b) * ( (a - b) / ( f(a) - f(b)) );
        }
      }
      contador++;
      
    }
    return false;
  }
  
private:
              function<double(double)> func;
              string str_func;
};

#endif
