#ifndef SEMANA_2_LINKED_LIST_H
#define SEMANA_2_LINKED_LIST_H

#include <cassert>

template<typename T>
class LinkedList{
    private:
        struct Nodo{
            T data;
            Nodo* next;

            Nodo(T _data): data(_data), next(nullptr){};
            Nodo* later_node(int i){
                if(i == 0)
                    return this;
                assert(next); // assert self.next
                return next->later_node(i-1);
            }
        };

        Nodo* head;
        int _size;

    public:
        LinkedList(): head(nullptr), _size(0){};            // __init__(self)

        int size(){                                         // __len__(self)
            return _size;
        }

        class iterator{                                     // __iter__(self)
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

        void push_front(T _data){                           // insert_first()
            // TODO
        }

        T pop_front(){                                      // delete_first()
            // TODO
        }

        void insert(T _data, int pos){                      // insert_at
            // TODO
        }

        T erase(int pos){                                   // delete_at
            // TODO
        }

        void push_back(T _data){                            // insert_last()
            // TODO
        }

        T pop_back(){                                       // delete_last()
            // TODO
        }

        ~LinkedList(){};
};

#endif //SEMANA_2_LINKED_LIST_H