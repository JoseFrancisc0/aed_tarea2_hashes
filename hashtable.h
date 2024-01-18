#ifndef SEMANA_2_HASH_TABLE_H
#define SEMANA_2_HASH_TABLE_H
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
#include "linkedlist.h"

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

template<typename T>
class Hash_Table_Set{
public:
    Hash_Table_Set(int r = 200) : r(r), p(2147483647), a(rand() % (p - 1) + 1) {
        chain_set = new LinkedList<T>();
        A = new LinkedList<T>();
        _compute_bounds();
        _resize(0);
    }
    ~Hash_Table_Set() {
        delete chain_set;
        delete A;
    }
    int size() const {
        return size;
    }

    void build(const std::vector<T>& X) {
        for (const auto& x : X) {
            insert(x);
        }
    }

    void insert(const T& x) {   // ????? esta bien
        _resize(size_ + 1);
        int h = _hash(x.key, A->size());
        bool added = A->insert(x);
        if (added) {
            size_++;
        }
    }
private:
    LinkedList<T>* chain_set;
    LinkedList<T>* A;
    int size_ = 0;
    int r;
    int p;
    int a;

    int _hash(int k, int m) {
        return ((a * k) % p) % m;
    }

    void _compute_bounds() {
        upper = A->size();
        lower = A->size() * 100 * 100 ;
    }

    void _resize(int n) {
        if (lower >= n or n >= upper) {
            int f = r / 100;
            if (r % 100) {
                f += 1;
            }
            int m = max(n, 1) * f;
            LinkedList<T>* newA = new LinkedList<T>[m];
            for (const auto& x : *A) {
                int h = _hash(x.key, m);
                newA[h].insert(x);
            }
            delete[] A;
            A = newA;
            _compute_bounds();
        }
    }

    int upper;
    int lower;

};

#endif //SEMANA_2_HASH_TABLE_H
