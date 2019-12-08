// C++ program for B-Tree insertion
#include "Btree.hpp"

using namespace std;

// Driver program to test above functions
int main()
{
    BTree t(3); // A B-Tree with minium degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    
    cout << "Traversal of the constucted tree is ";
    t.traverse();
    
    int k = 6;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    
    k = 15;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    
    return 0;
}
