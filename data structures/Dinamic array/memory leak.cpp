#include "DinamicArray.hpp"
#include <iostream>
using namespace std;

void testDestructorLeak() {
    cout << "=== TEST 1: Destructor Memory Leak ===" << endl;
    cout << "Creating and destroying DA objects..." << endl;
    
    // Crear y destruir múltiples objetos
    for (int i = 0; i < 100000; i++) {
        DA* arr = new DA();
        arr->InitArray(100);  // Asigna memoria
        delete arr;           // ❌ LEAK: no libera array interno
    }
    
    cout << "If no destructor: 1000 arrays of 100 ints = ~400KB leaked!" << endl;
    cout << "Check Task Manager - memory should increase significantly" << endl;
}

void testInitArrayLeak() {
    cout << "\n=== TEST 2: InitArray Memory Leak ===" << endl;
    
    DA arr;
    
    cout << "Calling InitArray multiple times..." << endl;
    for (int i = 0; i < 1000; i++) {
        arr.InitArray(1000);  // ❌ LEAK: no libera array anterior
        cout << "Iteration " << i << " - allocated 1000 ints" << endl;
    }
    
    cout << "Memory leaked: ~100 arrays * 1000 ints = ~400KB" << endl;
    // arr se destruye aquí, pero solo libera el último array
}

void testCopyArrayLeak() {
    cout << "\n=== TEST 3: copyArray Memory Leak ===" << endl;
    
    DA arr;
    arr.InitArray(10);
    
    cout << "Adding elements to trigger copyArray..." << endl;
    
    // Agregar elementos para forzar redimensionamiento
    for (int i = 0; i < 50; i++) {
        cout << "Adding element " << i << " (size: " << arr.getSize() << ")" << endl;
        arr.add(i);  // ❌ LEAK: copyArray no libera memoria anterior
    }
    
    cout << "Multiple arrays leaked during resizing!" << endl;
}

void testSizeofBug() {
    cout << "\n=== TEST 4: sizeof Bug Detection ===" << endl;
    
    int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Simular lo que hace tu copyArray
    cout << "Array has 10 elements (40 bytes)" << endl;
    cout << "sizeof(testArray pointer) = " << sizeof(int*) << " bytes" << endl;
    cout << "sizeof(testArray pointer)/sizeof(int) = " << sizeof(int*)/sizeof(int) << endl;
    cout << "Your copyArray thinks array has " << sizeof(int*)/sizeof(int) << " elements!" << endl;
    
    // Intentar crear con array estático
    try {
        DA arr;
        arr.InitArray(testArray);  // ❌ Usa sizeof incorrectamente
        cout << "Array size after InitArray: " << arr.getSize() << endl;
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void stressTest() {
    cout << "\n=== TEST 5: Stress Test ===" << endl;
    
    cout << "Creating large arrays to stress memory..." << endl;
    
    for (int test = 0; test < 10; test++) {
        cout << "Stress test iteration " << test << endl;
        
        DA arr;
        arr.InitArray(10000);  // Array grande
        
        // Llenar el array
        for (int i = 0; i < 5000; i++) {
            arr.add(i);
        }
        
        // Operaciones que podrían causar leaks
        arr.reverse();
        arr.sort();
        
        // Múltiples InitArray (debería liberar anterior)
        arr.InitArray(20000);
        arr.InitArray(30000);
        arr.InitArray(40000);
        
        cout << "Final size: " << arr.getSize() << endl;
    }
    
    cout << "If implementation is correct, memory usage should be stable" << endl;
}

#include "DinamicArray.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    cout << "MEMORY LEAK DETECTION TESTS" << endl;
    cout << "Monitor memory usage in Task Manager while running..." << endl;
    cout << "Press Enter to start each test..." << endl;
    cin.get();
    
    // Test 1: Destructor leak
    testDestructorLeak();
    cout << "\nCheck memory usage now. Press Enter to continue..." << endl;
    cin.get();
    
    // Test 2: InitArray leak  
    testInitArrayLeak();
    cout << "\nCheck memory usage now. Press Enter to continue..." << endl;
    cin.get();
    
    // Test 3: copyArray leak
    testCopyArrayLeak();
    cout << "\nCheck memory usage now. Press Enter to continue..." << endl;
    cin.get();
    
    // Test 4: sizeof bug
    testSizeofBug();
    cout << "\nPress Enter to continue..." << endl;
    cin.get();
    
    // Test 5: Stress test
    stressTest();
    cout << "\nFinal memory check. Press Enter to exit..." << endl;
    cin.get();
    
    return 0;
}