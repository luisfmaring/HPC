#include "gdsIntegral.h"

int
  main (void)
  {
    gsl_integration_workspace * w 
    = gsl_integration_workspace_alloc (1000);  //se asigna un espacion en memoria  para manter 1000 intervalos de double presicion
    
    double result, error;                     // variables para asignar el error y el resultado
    
    Params args = {0.3, 2/3.0, 2.0, 1/1.3, 1/30.0}; //crea args a partir del struct Parmas y asigna unos valores
    
    gsl_function F;                         //crea un variable tipo gsl_function: Define una función general con parámetros.
    F.function = &f;                        //asigna la funcion f a F
    F.params = &args;                       //asigna los parametros args a F
    
    gsl_integration_qags (&F, 0, 5, 0, 1e-7, 1000,
                          w, &result, &error);       //La funcion de gsl que va realizar el trabajo de intregracion
    
    printf ("result          = % .18f\n", result);
    printf ("estimated error = % .18f\n", error);
    printf ("intervals       = %zu\n", w->size);
    
    gsl_integration_workspace_free (w);    //libera la memoria asignado para manter 1000 intervalos de double presicion
    
    return 0;
  }

//g++ funcs.cpp -c -o funcs.o
//g++ funcs.o integral.cpp -lgsl -o integral
//./integral