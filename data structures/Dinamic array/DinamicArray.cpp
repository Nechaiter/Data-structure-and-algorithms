
// Para declaraciones lo mejor es hacerlo con header (.hpp)
// Se pudo crear las estructuras con (struct) pero se uso un objeto para practica con OOP

// Ideas y refencias de los metodos sacados aqui >> https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/dynamicarray/IntArray.java

#include <stdexcept>
#include <iostream>
using namespace std;

// ArrayDinamico para numeros enteros solamente 
class DA{
    
    // puntero del array para asignar memoria dinamicamente
    int *array;

    // Cantidad de elementos del array que el usuario tiene
    int size = {0};

    // Espacio que el array esta usando real (cantidad de objetos dentro de el array)
    int space = {0};

    

    private:

        void copyArray(int * ArrayToCopy,int space = 0){
            
            if (space<=0){
                space = sizeof(ArrayToCopy)/sizeof(int);
            }
            array = new int[space]();
            for (int i= 0; i<size; i++){
                array[i]=ArrayToCopy[i];
            }
        }


    // Metodos para size, add, drop
    public:

        int getSize(){
            return size;
        }

        // Metodo para asignar el espacio del array
        void InitArray(int space = -1){
            if (space<0){
                throw out_of_range("Invalid space assigned to the array, it should be a postive integer");
            }

            else{
                array = new int[space]();
                this->space = size = space;
            }

        }
        void InitArray(int StaticArray[]){
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
        void add(int newElement){
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

        // COMO REDUCIR EL el tiempo de O(n) a O(1) para el ultimo elemento?
        void removeAt(int index){
            

            // En vez de crear uno nuevo basado en lo anterior, movamos los elemetos y dejamos el espacio al final

            if (index < 0 || index >= size) {
                throw out_of_range("Index out of bounds");
            }
            for (int i = index; i < size - 1; i++){
                array[i] = array[i + 1];
            }
            
            size--; 

        }



    // 
    

};


int main(){
    


	return 0;
}

