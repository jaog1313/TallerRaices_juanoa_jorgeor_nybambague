#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

using std::function;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;

class newtonraphson {
public:
  newtonraphson(
             function<double(double)> p_func,
             function<double(double)> p_dfunc, 
             string p_str
             ):func(p_func),d_func(p_dfunc), str_func(p_str) {
  }
  
  double f(double x) {
    return func(x);
  }
  
  double df(double x) {
    return d_func(x);
  }
  
  string str() {
    return str_func;
  }
  
  
  void tabla(double x0, double paso, int n) {
    
    cout
      <<setw(10)
      <<"x"
      <<setw(10)
      <<"f(x)"
      <<endl;
    
    double x =  x0;
    
    while(n > 0) {
      
      cout
        <<setw(10)
        <<x
        <<setw(10)
        <<f(x)
        <<endl;
      x += paso;
      n--;
    }
  }
  
  
  bool raiz(double p0,
            double tolerancia,
            int max_iter, 
            double &valor_raiz) {
    
    int i = 1;
    double p, e;
    if(fabs(f(p0)) < tolerancia){
      valor_raiz = p0;
      return true;
    }
    while(i <= max_iter) {
      p = p0 - (f(p0) / df(p0));
      e = fabs((p - p0) / p);
      
      if( e < tolerancia) {
        valor_raiz = p;
        return true;
      }
      i++;
      p0 = p;
    }
    return false;
  }
            
private:
      function<double(double)> func;
      function<double(double)> d_func;
      string str_func;
};

#endif
