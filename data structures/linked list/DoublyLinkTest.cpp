#include "DoublyLinkedList.hpp"
#include <iostream>

int main() {
    DLL<int> lista;
    
    // Test básicos de estado
    std::cout << "Empty: " << lista.IsEmpty() << std::endl;
    std::cout << "Size: " << lista.getSize() << std::endl;
    
    // Test de inserción
    lista.add(10);
    lista.addFirst(5);
    lista.addLast(15);
    lista.addAt(1, 7);
    lista.display();
    
    // Test de peek
    std::cout << "First: " << lista.peekFist() << std::endl;
    std::cout << "Last: " << lista.peekLast() << std::endl;
    
    // Test de búsqueda
    std::cout << "Index of 7: " << lista.indexOf(7) << std::endl;
    std::cout << "Index of 99: " << lista.indexOf(99) << std::endl;
    
    // Test de remoción
    std::cout << "Removed first: " << lista.removeFirst() << std::endl;
    std::cout << "Removed last: " << lista.removeLast() << std::endl;
    std::cout << "Removed at index 0: " << lista.removeAt(0) << std::endl;
    lista.display();
    
    // Test de remoción por valor
    lista.add(20);
    lista.add(25);
    std::cout << "Remove 20: " << lista.remove(20) << std::endl;
    std::cout << "Remove 99: " << lista.remove(99) << std::endl;
    lista.display();
    
    // Test clear
    lista.clear();
    std::cout << "After clear - Empty: " << lista.IsEmpty() << std::endl;
}