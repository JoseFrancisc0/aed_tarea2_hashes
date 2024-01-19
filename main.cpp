#include <iostream>
#include "set.h"

int main(int, char**){
    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);

    set1.contains(1);
    set1.remove(4);

    Set<int> set2;
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    
    Set<int> set3 = set1.Union(set2);
    Set<int> set4 = set1.Intersect(set2);
    Set<int> set5 = set1.Difference(set2);
}
