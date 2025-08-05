#include "DinamicArray.hpp"

// Pruebas con ia

int main(){
    cout << "=== TESTING DYNAMIC ARRAY CLASS ===" << endl;
    
    try {
        // Test 1: Crear array y verificar estado inicial
        cout << "\n1. Testing InitArray and basic functionality:" << endl;
        DA arr;
        arr.InitArray(5);
        cout << "Array initialized with capacity 5" << endl;
        cout << "Size: " << arr.getSize() << endl;
        cout << "Is empty? " << (arr.isEmpty() ? "Yes" : "No") << endl;
        
        // Test 2: Agregar elementos
        cout << "\n2. Testing add method:" << endl;
        arr.add(10);
        arr.add(20);
        arr.add(30);
        arr.add(40);
        arr.add(50);
        cout << "Added elements: 10, 20, 30, 40, 50" << endl;
        cout << "Current size: " << arr.getSize() << endl;
        cout << "Is empty? " << (arr.isEmpty() ? "Yes" : "No") << endl;
        
        // Test 3: Agregar más elementos para probar redimensionamiento
        cout << "\n3. Testing array resizing:" << endl;
        arr.add(60);
        arr.add(70);
        cout << "Added more elements: 60, 70 (should trigger resize)" << endl;
        cout << "Current size: " << arr.getSize() << endl;
        
        // Test 4: Mostrar elementos usando operator[]
        cout << "\n4. Testing array contents with direct access []:" << endl;
        cout << "Array elements: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";  // ✅ Acceso directo con []
        }
        cout << endl;
        
        // Test 5: Modificar elementos directamente
        cout << "\n5. Testing direct element modification:" << endl;
        cout << "Original element at index 0: " << arr[0] << endl;
        arr[0] = 999;  // ✅ Modificación directa
        cout << "Modified element at index 0: " << arr[0] << endl;
        arr[0] = 10;   // Restaurar valor original
        
        // Test 6: Probar remove
        cout << "\n6. Testing remove methods:" << endl;
        cout << "Array before removing 30: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        bool removed = arr.remove(30);
        cout << "Element 30 removed: " << (removed ? "Yes" : "No") << endl;
        cout << "Array after removal: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "New size: " << arr.getSize() << endl;
        
        // Test 7: Probar removeAt
        cout << "\n7. Testing removeAt:" << endl;
        cout << "Array before removeAt(0): ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        arr.removeAt(0);
        cout << "Array after removeAt(0): ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "New size: " << arr.getSize() << endl;
        
        // Test 8: Probar reverse
        cout << "\n8. Testing reverse:" << endl;
        cout << "Array before reverse: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        arr.reverse();
        cout << "Array after reverse: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // Test 9: Probar sort
        cout << "\n9. Testing sort:" << endl;
        cout << "Array before sort: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        arr.sort();
        cout << "Array after sort: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // Test 10: Probar binary search (requiere array ordenado)
        cout << "\n10. Testing binary search:" << endl;
        int searchResult = arr.binarySeach(50);
        cout << "Searching for element 50..." << endl;
        if (searchResult != -1) {
            cout << "Element found at index: " << searchResult;
            cout << " (value: " << arr[searchResult] << ")" << endl;  // ✅ Verificar con []
        } else {
            cout << "Element not found" << endl;
        }
        
        // Test 11: Buscar elemento que no existe
        searchResult = arr.binarySeach(999);
        cout << "Searching for element 999..." << endl;
        if (searchResult != -1) {
            cout << "Element found at index: " << searchResult << endl;
        } else {
            cout << "Element not found" << endl;
        }
        
        // Test 12: Probar acceso fuera de límites
        cout << "\n11. Testing bounds checking:" << endl;
        cout << "Testing valid access arr[0]: " << arr[0] << endl;
        
        try {
            cout << "Testing invalid access arr[999]..." << endl;
            int invalidAccess = arr[999];  // ✅ Debería lanzar excepción
            cout << "Unexpected: got value " << invalidAccess << endl;
        } catch (const invalid_argument& e) {
            cout << "Caught expected exception: " << e.what() << endl;
        }
        
        // Test 13: Probar InitArray con valor negativo
        cout << "\n12. Testing InitArray with negative value:" << endl;
        try {
            DA badArr;
            badArr.InitArray(-5);
        } catch (const invalid_argument& e) {
            cout << "Caught expected exception: " << e.what() << endl;
        }
        
        // Test 14: Demostrar sintaxis similar a std::vector
        cout << "\n13. Vector-like syntax demonstration:" << endl;
        DA vectorLike;
        vectorLike.InitArray(3);
        
        // Llenar como si fuera vector
        vectorLike.add(100);
        vectorLike.add(200);
        vectorLike.add(300);
        
        cout << "Filling array like std::vector:" << endl;
        for (int i = 0; i < vectorLike.getSize(); i++) {
            cout << "vectorLike[" << i << "] = " << vectorLike[i] << endl;
        }
        
        // Modificar como vector
        for (int i = 0; i < vectorLike.getSize(); i++) {
            vectorLike[i] *= 2;  // Multiplicar por 2
        }
        
        cout << "After multiplying by 2:" << endl;
        for (int i = 0; i < vectorLike.getSize(); i++) {
            cout << "vectorLike[" << i << "] = " << vectorLike[i] << endl;
        }
        
        cout << "\n=== ALL TESTS COMPLETED ===" << endl;
        cout << "Final array size: " << arr.getSize() << endl;
        cout << "Final array contents: ";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    
    return 0;
}