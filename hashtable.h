#ifndef SEMANA_2_HASH_TABLE_H
#define SEMANA_2_HASH_TABLE_H
#include <cstdlib>
#include <vector>
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
        A = new LinkedList<T>();
        _compute_bounds();
        _resize(0);
    }
    ~Hash_Table_Set() {
        delete A;
    }
    T size() const {
        return size;
    }

    void build(const std::vector<T>& X) {
        for (const auto& x : X) {
            insert(x);
        }
    }

    const T* find(const T& k) {
        int h = _hash(k, A->getSize());
        return A[h]->find(k);
    }

    bool insert(const T& x) {   // Creo q ya esta bien
        _resize(size_ + 1);
        int h = _hash(x, A->size());
        bool added = A[h]->insert(x);
        if (added) {
            size_++;
        }
        return added;
    }

    bool remove(const T& k) {  // ????? esta bien
        assert(size_ > 0);

        int h = _hash(k.key, A->size());
        bool removed = A[h]->remove(k);

        if (removed) {
            size_--;
            _resize(size_);
        }
        return removed;
    }

    T* find_min(){
        T* out = nullptr;
        for (const auto& x : *A) {
            if (!out or (x.key < out->key)) {
                out = &x;
            }
        }
        return *out;
    }

    T* find_max(){
        T* out = nullptr;
        for (const auto& x : *A) {
            if (!out or (x.key > out->key)) {
                out =&x;
            }
        }
        return *out;
    }

    T* find_next(int k){
        T* out = nullptr;
        for (const auto& x : *A) {
            if (x.key > k) {
                if (!out or (x.key < out->key)) {
                    out = &x;
                }
            }
        }
        return *out;
    }

    T* find_prev(int k){
        T* out = nullptr;
        for (const auto& x : *A) {
            if (x.key < k) {
                if (!out or (x.key > out->key)) {
                    out = &x;
                }
            }
        }
        return *out;
    }

    void iter_order() {
        T* x = &find_min();
        while (x) {
            x = &find_next(x->key);
        }
    }


private:
    LinkedList<T>* A;
    int size_ = 0;
    int r;
    int p;
    int a;
    int upper;
    int lower;

    int _hash(int k, int m) {
        return ((a * k) % p) % m;
    }

    void _compute_bounds() {
        this->upper = A->size();
        this->lower = (A->size() * 100 * 100)/(r*r) ;
    }

    void _resize(int n) {
        if (lower >= n || n >= upper) {
            int f = r / 100;
            if (r % 100) {
                f += 1;
            }
            int m = max(n, 1) * f;
            LinkedList<T>* newA = new LinkedList<T>[m];

            for (const T& x : *A) {
                int h = _hash(x, m);
                newA[h].insert(x);
            }
            
            delete[] A;
            A = newA;
            _compute_bounds();
        }
    }

};



#endif //SEMANA_2_HASH_TABLE_H
