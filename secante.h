#ifndef SECANTE_H
#define SECANTE_H

#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

class secante {
public:
  secante(
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
  
  void tabla(double x0, double x1, int intervalos ) {
    double paso = (x1-x0)/intervalos;
    cout << str() << endl;
    cout
      <<setw(10)
      <<"x"
      <<setw(10)
      <<"f(x)"
      << endl;
    while (x0 < x1 + paso) {
      cout
        <<setw(10)
        <<x0
        <<setw(10)
        <<f(x0)
        << endl;
      x0 += paso;	
    }
  }
  
  int iteraciones;
  bool raiz(double x0, 
            double x1, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    
    
    int iter = 1;
    
    while(iter<=max_iter){
      
      double x2 = x1 - ((f(x1)*(x0-x1))/(f(x0)-f(x1)));
      double erp = fabs(((x2-x1)/x2));
      
      
      
      if(erp<=tolerancia){
        
        iteraciones = iter;
        valor_raiz = x2;
        return true;
      }
      x0 = x1;
      x1 = x2;
      iter ++;
    }
    return false;
  }
  
private:
              function<double(double)> func;
              string str_func;
};


#endif
