#ifndef SEMANA_2_SET_H
#define SEMANA_2_SET_H

#include "hashtable.h"
using namespace std;

template<typename T>
class Set{
    private:
        HashTable<T> table;
        int size = 0;
    public:
        Set(){};                            // Llama al constructor de HashTable

        void insert(T data){
            table.insert(data);
            size = table.get_size();
        }

        bool remove(T data){
            bool removed = table.remove(data);
            if(removed)
                size = table.get_size();
            
            return removed;
        };

        bool contains(T data);
        Set Union(const Set& other);
        Set Intersect(const Set& other);
        Set Difference(const Set& other);
        ~Set(){};                           // Llama al destructor de Hashtable
};

#endif //SEMANA_2_SET_H