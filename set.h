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

        bool contains(T data){
            return table.find(data);
        }

        Set<T> Union(const Set& other){
            Set<T> newSet;

            for(const T& element : table)
                newSet.insert(element);
            
            for(const T& element : other.table)
                newSet.insert(element);
            
            return newSet;
        }

        Set Intersect(const Set& other){
            Set<T> newSet;

            for(const T& element : table)
                if(other.contains(element))
                    newSet.insert(element);
                
            return newSet;
        };

        Set Difference(const Set& other){
            Set<T> newSet;

            for(const T& element : table)
                if(!other.contains(element))
                    newSet.insert(element);
                
            return newSet;
        }

        ~Set(){};                           // Llama al destructor de Hashtable
};

#endif //SEMANA_2_SET_H