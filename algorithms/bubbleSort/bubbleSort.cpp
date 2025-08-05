#include <iostream>
#include <vector>
using namespace std;


// Menor a mayor
void bubble_sort(vector<int>& numeros){

    for (int i=0; i<numeros.size()-1;i++){
        for (int j=0; j<numeros.size()-i-1; j++){
            if (numeros[j]>numeros[j+1]){
                int temp=numeros[j+1];
                numeros[j+1]=numeros[j];
                numeros[j]=temp;
            }
        }
    }    
}


int main(){

    vector<int> numeros = {-2,3,4,-1,5,-12,6,1,3};

    bubble_sort(numeros);

    for (int i=0 ; i< numeros.size(); i++)
    {
        cout << numeros[i] << ",";
    }

    return 0;

}
