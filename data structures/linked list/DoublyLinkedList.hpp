

#ifndef Doubly_Linked_List_H
#define Doubly_Linked_List_H


#include <stdexcept>
#include <iostream>
using namespace std;

// Se hace uso de templates para no tener restriccion de typos de datos al implementar las listas
template<typename T>
class DLL{
  

    private:

        class node{
            friend class DLL;
            T data;
            node* next;
            node* prev;

            public:
                node(T data,node* prev,node* next){
                    this->data=data;
                    this->next=next;
                    this->prev=prev;
                };
        };
        int size = {0};
        node* head = nullptr;
        node* tail = nullptr;

    public:
        // Remueve los nodos desde la cabeza hasta el final en O(n)
        void clear(){
            node* current_node = head;
            while (current_node!=nullptr){ 
                node* next = current_node->next;
                current_node->prev= current_node->next = nullptr;
                current_node->data= NULL;
                current_node= next;
            }
            head = tail = current_node = nullptr;
            size=0;
        }

        int getSize(){
            return size;
        }

        bool IsEmpty(){
            return getSize() == 0;
        }

        void add(T new_data){
            addLast(new_data);
        }

        void addLast(T new_data){
            if (IsEmpty()){
                head = tail = new node(new_data,nullptr,nullptr); 
            }
            else{
                tail->next = new node(new_data,tail,nullptr);
                tail = tail->next;
            }
            size++;
        }

        void addFirst(T new_data){
            if (IsEmpty()){
                head = tail = new node(new_data,nullptr,nullptr); 
            }
            else{
                head->prev = new node(new_data,nullptr,head); 
                head = head->prev;
            }
            size++;
        }

        void addAt(int index, T new_data){
            if (index < 0 || index > size) {
                throw out_of_range("Index out of bounds");
            }
            if (index == 0) {
                addFirst(data);
                return;
            }

            if (index == size) {
                addLast(data);
                return;
            }

            int best_side;
            if (index > size/2){

            }

            




        }


    
};

#endif