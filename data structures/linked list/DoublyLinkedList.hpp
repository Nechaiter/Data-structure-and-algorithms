

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


        T remove(node* node){
            if (node->prev == nullptr) return removeFirst();
            if (node->next == nullptr) return removeLast();

            node->prev->next=node->next;
            node->next->prev=node->prev;

            T temp = node->data;
            delete node;
            --size;
            return temp;
        }



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
                addFirst(new_data);
                return;
            }

            if (index == size) {
                addLast(new_data);
                return;
            };

            bool best_side = false;
            if (index > size/2){
                best_side = true;
            };
            int start, end, step;
            node* current;

            if(best_side){
                start = size - 1;
                end = index;
                current = tail;
                for (int i=start;i>=end;i--){
                    current=tail->prev;
                };
            }else{
                start = 0;
                end = index;
                current = head;
                for (int i=start;i<=end;i++){
                    current=head->next;
                };
            };
            
            node* new_node = new node(new_data,current->prev,current);
            current->prev->next=new_node;
            current->prev=new_node;
            size++;
        };

        // Mostrar la lista de manera visual
        void display() {
            if (IsEmpty()) {
                cout << "Lista vacía" << endl;
                return;
            }
            
            node* current = head;
            cout << "[";
            while (current != nullptr) {
                cout << current->data;
                if (current->next != nullptr) {
                    cout << " <-> ";
                }
                current = current->next;
            }
            cout << "]" << endl;
        }
        T peekFist(){
            if(IsEmpty()){
                throw logic_error("Empty List");
            }
            return head->data;
        }
        T peekLast(){
            if(IsEmpty()){
                throw logic_error("Empty List");
            }
            return tail->data;
        }

        T removeFirst(){
            if(IsEmpty()){
                throw logic_error("Empty List");
                head = nullptr;
                tail = nullptr;
            };
            T data = head->data;
            if (size<2){
                delete head;    
                head = nullptr;
                --size;
            }
            else{
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                --size;
            }
            if(IsEmpty()){
                tail=nullptr;
            }
            return data;
        }

        T removeLast(){
            if(IsEmpty()){
                throw logic_error("Empty List");
                head = nullptr;
                tail = nullptr;
            };
            T data = tail->data;
            if (size<2){
                delete tail;
                --size;
            }
            else{
                node* prev=tail->prev;
                delete tail;
                tail=prev;
                tail->next=nullptr;
                prev = nullptr;
                --size;
            }
            if(IsEmpty()){
                tail=nullptr;
                head=nullptr;
            }
            return data;
        }

        T removeAt(int index){
            if (index < 0 || index >= size) {
                throw out_of_range("Index out of bounds");
            }

            int i;
            node* current;

            if (index< size/2){
                for(i=0, current=head; i<index; i++){
                    current=current->next;
                }
            }else{
                for(i= size-1, current = tail;i>index; i--){
                    current=current->prev;
                }
            }

            return remove(current);
        }

        bool remove(T value){
            node* current = head;

            for (current;current!=nullptr;current=current->next){
                if(current->data==value){
                    remove(current);
                    return true;
                }
            }
            return false;
        }

        int indexOf(T value){
            int index = 0;
            node* current=head;


            for (current;current!=nullptr;current=current->next, index++){
                if(current->data==value){
                    return index;
                }
            }
            return -1;

        }
};

#endif

