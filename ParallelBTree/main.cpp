// C++ program for B-Tree insertion
#include "Btree.hpp"
#include "ParallelBTree.hpp"
#include <time.h>       /* time */
#include <ctime>

using namespace std;

// Driver program to test above functions
int main()
{
    srand (time(NULL));
    
    BTree bt(3);
    ParallelBTree pbt(3); // A B-Tree with minium degree 3
    
    for(int i = 0; i < 10000; i++){
        int value = rand() % 2000 - 1000;
        bt.insert(value);
        pbt.insert(value);
    }
    
//     Code to check both trees have same results
//    (bt.search(-100) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(-100) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
//
//    (bt.search(-10) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(-10) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
//
//    (bt.search(-500) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(-500) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
//
//    (bt.search(598) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(598) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
//
//    (bt.search(999) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(999) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
//
//    (bt.search(0) != NULL)? cout << "Found\t" : cout << "Not Found\t";
//    (bt.search(0) != NULL)? cout << "Found" : cout << "Not Found";
//    cout << endl;
    
    clock_t begin = clock();
    
    bt.search(-100);
    bt.search(500);
    bt.search(123);
    bt.search(157);
    bt.search(999);
    bt.search(-4);
    bt.search(0);
    bt.search(456);
    bt.search(-879);
    bt.search(-90);
    
    clock_t end = clock();
    double btElapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    
    begin = clock();
    
    pbt.search(-100);
    pbt.search(500);
    pbt.search(123);
    pbt.search(157);
    pbt.search(999);
    pbt.search(-4);
    pbt.search(0);
    pbt.search(456);
    pbt.search(-879);
    pbt.search(-90);
    
    end = clock();
    double pbtElapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "Time elapsed:" << endl;
    cout << "BTree: " << btElapsedTime << endl;
    cout << "Parallel BTree: " << pbtElapsedTime << endl;
    
    cout << endl;
    
    return 0;
}
