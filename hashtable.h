#ifndef SEMANA_2_HASH_TABLE_H
#define SEMANA_2_HASH_TABLE_H
#include <cstdlib>
#include "linkedlist.h"
using namespace std;

/*
    La implementacion HashTable utiliza la funcion Set_from_Seq(Linked_List_Seq)
    dentro de su constructor.
    Dicha funcion sirve para instanciar una interfaz para la clase Linked_List,
    que hace comportar a una lista enlazada como un Set. Las dos veces que aparece
    estan en el constructor de la tabla y en el metodo resize.
    Como la implementacion de la clase Set va a usar un Hash Table (y no al reves
    como lo muestra el pdf), vamos a usar la lista enlazada directamente para implementar
    la tabla hash.
*/

template<typename T = int>
class HashTable{
    private:
        LinkedList<T>* A;
        int size = 0;
        int capacity;
        int fill_ratio;
        int p = 2147483647;
        int a = rand() % (p - 1) + 1;
        int upper_bound;
        int lower_bound;

        int hash(T key){
            int _hash = ((a*key) % p) % capacity;
            return _hash;
        }

        void compute_bounds(){
            upper_bound = A->get_size();
            lower_bound = A->get_size()*100*100 / (fill_ratio*fill_ratio);
        }

        void resize(int n){
            if(n <= lower_bound || n >= upper_bound){
                int f = fill_ratio/100;
                if(fill_ratio % 100 != 0)
                    f++;
                
                int m = max(n, 1) * f;
                LinkedList<T>* newA = new LinkedList<T>[m];
                for(int i=0; i<size; ++i){
                    LinkedList<T>& current = A[i];
                    auto it = current.begin();
                    while(it != current.end()){
                        T element = *it;
                        int _hash = hash(element);
                        newA[_hash].push_back(element);
                        ++it;
                    }
                }

                delete[] A;
                A = newA;
                capacity = m;

                compute_bounds();
            } 
        }
    
    public:

        class iterator{
            private:
                typename LinkedList<T>::iterator current;
            
            public:
                iterator(typename LinkedList<T>::iterator start) : current(start){};

                T operator*(){
                    return *current;
                }

                iterator& operator++(){
                    ++current;
                    return *this;
                }

                bool operator!=(const iterator& other){
                    return current != other.current;
                }
        };

        iterator begin(){
            return iterator(A[0].begin());
        }

        iterator end(){
            return iterator(A[capacity - 1].end());
        }

        HashTable(int _capacity = 1, int _fill_ratio = 200): capacity(_capacity), fill_ratio(_fill_ratio){
            A = new LinkedList<T>[capacity];
            compute_bounds();
        }

        int get_size(){
            return size;
        }

        void insert(const T& key){              // push_back() es void
            resize(size + 1); // Check
            int _hash = hash(key);
            A[_hash].push_back(key);            // Al no devolver, los checks se hacen dentro LinkedList::push_back()
            size++;
        }

        bool find(T key){
            int _hash = hash(key);
            return A[_hash].find(key);
        }

        bool remove(const T& key){
            int _hash = hash(key);
            bool deleted = A[_hash].erase_key(key);

            if(deleted){
                size--;
                resize(size);
            }

            return deleted;
        }

        T find_min(){
            T min_key = numeric_limits<T>::max();

            for(int i=0; i<capacity; ++i)
                for(const T& element : A[i])
                    if(element < min_key)
                        min_key = element;
            
            return min_key;
        }

        T find_max(){
            T max_key = 0;

            for(int i=0; i<capacity; ++i)
                for(const T& element : A[i])
                    if(element > max_key)
                        max_key = element;
            
            return max_key;
        }

        T find_next(T key){
            T next = numeric_limits<T>::max();

            for(int i=0; i<capacity; ++i)
                for(const T& element : A[i])
                    if(element > key && element < next)
                        next = element;
            
            return next;
        }

        T find_prev(T key){
            T prev = numeric_limits<T>::min();

            for(int i=0; i<capacity; ++i)
                for(const T& element : A[i])
                    if(element < key && element > prev)
                        prev = element;
            
            return prev;
        }

        ~HashTable(){
            delete[] A;
        }
};

#endif //SEMANA_2_HASH_TABLE_H