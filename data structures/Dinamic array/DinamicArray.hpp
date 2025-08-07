
// Para declaraciones lo mejor es hacerlo con header (.hpp)
// Se pudo crear las estructuras con (struct) pero se uso un objeto para practica con OOP

// Ideas y refencias de los metodos sacados aqui >> https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/dynamicarray/IntArray.java


// El codigo probablemente tiene muchos leaks de memoria ya que aun me ando familiarizando con c++



#ifndef DINAMIC_ARRAY_H
#define DINAMIC_ARRAY_H


#include <stdexcept>
#include <iostream>
using namespace std;

// Se hace uso de templates para no tener restriccion de data types
template<typename T>
// ArrayDinamico para numeros enteros solamente 
class DA{
    
    // puntero del array para asignar memoria dinamicamente
    T *array = nullptr;
    // Cantidad de elementos del array que el usuario tiene
    int size = {0};
    // Espacio que el array esta usando real (cantidad de objetos dentro de el array)
    int space = {0};

    

    private:

        void copyArray(T * ArrayToCopy,int space = 0){
            
            if (space<=0){
                space = sizeof(ArrayToCopy)/sizeof(int);
            }
            delete[] array;
            array = new T[space]();
            for (int i= 0; i<size; i++){
                array[i]=ArrayToCopy[i];
            }
        }


    // Metodos para size, add, drop
    public:
        ~DA() {
            if (array != nullptr) {
                delete[] array;
            }
        }


        // sobre escribe operadores aritmeticos u otros para cambiarles la logica
        int& operator[](int index) {
            if (index<size){
                return array[index];
            }else{
                throw invalid_argument("The index should be inside bounds");
            }
        }



        int getSize(){
            return size;
        }

        // Metodo para asignar el espacio del array
        void InitArray(int space = -1){
            if (space<0){
                throw out_of_range("Invalid space assigned to the array, it should be a postive integer");
            }

            else{
                array = new T[space]();
                this->space = size = space;
            }

        }
        void InitArray(T StaticArray[]){
            if (StaticArray == nullptr){
                throw invalid_argument("The array should contain something");
            }
            copyArray(StaticArray);
        }

        bool isEmpty(){
            return size==0;
        }
        // int get(int index){
        //     return this->array[index];
        // }
        // void set(int index,int element){
        //     this->array[index]=element;
        // }


        // Insert at...
        // Si no hay espacio, duplicamos el espacio haciendo un nuevo array
        void add(T newElement){
            if (size+1>=space){

                if (space == 0){
                    space = 1;
                }
                else{
                    // https://github.com/python/cpython/blob/0a9b339363a59be1249189c767ed6f46fd71e1c7/Objects/listobject.c#L72
                    space=space*2;
                }

                copyArray(array);

            }
            array[size++]=newElement;
        }

        
        void removeAt(int index){
            // En vez de crear uno nuevo basado en lo anterior, movamos los elementos y dejamos el espacio al final
            if (index < 0 || index >= size) {
                throw out_of_range("Index out of bounds");
            }
            for (int i = index; i < size - 1; i++){
                array[i] = array[i + 1];
            }
            size--; 
        }
        bool remove(T element){           
            for (int i = 0; i < size; i++) {
                if (array[i] == element) {
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }

        // Invertimos los elementos dividiendo a la mitad y se cambian de posicion con su inverso, 0 = size-1, 1=size-2, etc
        void reverse(){
            for (int i = 0; i < size / 2; i++) {
                T tmp = array[i];
                array[i] = array[size - i - 1];
                array[size - i - 1] = tmp;
            }
        }

        int binarySeach(T element){
            int inicio = {0};
            int final = {size - 1};
            while (inicio <= final) {
                int mitad = (final + inicio) / 2;
                // Busqueda por derecha
                if (array[mitad] > element) {
                    final = mitad - 1;
                    continue;
                }
                // busqueda por la izquierda
                else if (array[mitad] < element) {
                    inicio = mitad + 1;
                    continue;
                }
                return mitad;
            }
            return -1;
        }

        // Hacer un Heapsort...
        void sort(){
            for (int i=0; i<size-1;i++){
                for (int j=0; j<size-i-1; j++){
                    if (array[j]>array[j+1]){
                        T temp=array[j+1];
                        array[j+1]=array[j];
                        array[j]=temp;
                    }
                }
            }    
        }


};

#endif