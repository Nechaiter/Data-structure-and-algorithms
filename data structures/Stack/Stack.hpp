

#ifndef Stack_H
#define Stack_H


#include <stdexcept>
#include <iostream>

using namespace std;

// Se hace uso de templates para no tener restriccion de typos de datos al implementar las listas
template<typename T>
class Stack{
    public:
        Stack(){

        }
        Stack(T firstElement){
            push(firstElement);
        }




    private:
  

        T list = {};

    
};

#endif

