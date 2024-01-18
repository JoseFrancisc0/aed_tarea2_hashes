#ifndef SEMANA_2_HASH_TABLE_H
#define SEMANA_2_HASH_TABLE_H

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
class HashTable{
    public:
        HashTable();
        ~HashTable();
};

#endif //SEMANA_2_HASH_TABLE_H