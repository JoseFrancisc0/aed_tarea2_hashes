#ifndef SEMANA_2_LINKED_LIST_H
#define SEMANA_2_LINKED_LIST_H

#include <cassert>

/*

    Linked List Node:
    - later_node() es solo un metodo auxiliar para mover el nodo hasta cierta posicion.
      Un for-loop / while-loop (si va hasta el final) puede reemplazarlo en los metodos
      que los necesiten.

    Linked List:
    - El iterador no se utiliza en los metodos, pues usan el get_at().
    - get_at() usa el later_node(), sobrecargar el operador[], hace lo mismo.
    - build(), se implementara al final

*/

template<typename T>
class LinkedList{
    private:
        struct Nodo{
            T data;
            Nodo* next;

            Nodo(T _data): data(_data), next(nullptr){};    // __init__()
        };

        Nodo* head;
        int size;

    public:
        LinkedList(): head(nullptr), size(0){};             // __init__()

        int get_size(){                                     // __len__()
            return size;
        }

        class iterator{                                     // __iter__()
            private:
                Nodo* current;
            public:
                iterator(Nodo* start): current(start){};

                T operator*(){
                    return current->data;
                }

                iterator& operator++(){
                    current = current->next;
                    return *this;
                }

                bool operator!=(const iterator& other){
                    return current != other.current;
                }
        };
        iterator begin(){
            return iterator(head);
        }                         
        iterator end(){
            return iterator(nullptr);
        }          

        void set_at(T _data, int pos){                               // set_at()
            Nodo* temp = head;                              // Node.later_node()
            for(int i=0; i<=pos; i++)
                temp = temp->next;
            
            temp->data = _data;
        }

        T operator[](int pos){                              // get_at()
            Nodo* temp = head;                              // Node.later_node()
            for(int i=0; i<=pos; i++)
                temp = temp->next;
            
            return temp->data;
        }

        void push_front(T _data){                           // insert_first()
            Nodo* temp = new Nodo(_data);
            temp->next = head;
            head = temp;
            size++;
        }

        T pop_front(){                                      // delete_first()
            T popped = head->data;
            head = head->next;
            size--;
            return popped;
        }

        void push_back(T _data){                            // insert_last()
            Nodo* nodo = new Nodo(_data);

            Nodo* temp = head;                              // Node.later_node()
            while(temp->next)
                temp = temp->next;
            
            temp->next = nodo;
            nodo->next = nullptr;
            size++;
        }

        T pop_back(){                                       // delete_last()
            Nodo* temp = head;                              // Node.later_node()
            while(temp->next->next)
                temp = temp->next;

            T popped = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            size--;
            return popped;
        }        

        void insert(T _data, int pos){                      // insert_at()
            if(i == 0)
                push_front(_data);
            else if(i == size)
                push_back(_data);
            else{
                Nodo* nodo = new Nodo(_data);

                Nodo* temp = head;                          // Node.later_node()
                for(int i=0; i<pos-1; i++)
                    temp = temp->next;

                nodo->next = temp->next;
                temp->next = nodo;
                size++;
            }
        }

        T erase(int pos){                                   // delete_at()
            if(i == 0)
                pop_front();
            else if(i == size-1)
                pop_back();
            else{
                Nodo* temp = head;                          // Node.later_node()
                for(int i=0; i<pos; i++)
                    temp = temp->next;
                
                T popped = temp->next->data;
                temp->next = temp->next->next;
                delete temp;
                size--;

                return popped;
            }
        }

        ~LinkedList(){
            while(head)
                pop_front();
        }
};

#endif //SEMANA_2_LINKED_LIST_H
