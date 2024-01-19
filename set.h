#ifndef SEMANA_2_SET_H
#define SEMANA_2_SET_H

template<typename T>
class Set{
    private:
        // TODO: members
    public:
        Set();
        void insert(T data);
        bool remove(T data);
        bool contains(T data);
        Set Union(const Set& other);
        Set Intersect(const Set& other);
        Set Difference(const Set& other);
        ~Set();
};

#endif //SEMANA_2_SET_H