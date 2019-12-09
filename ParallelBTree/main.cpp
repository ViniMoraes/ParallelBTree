// C++ program for B-Tree insertion
#include "Btree.hpp"
#include "ParallelBTree.hpp"
#include <time.h>       /* time */
#include <ctime>

using namespace std;

void compareTrees(int keys, int searchs);

// Driver program to test above functions
int main()
{
    srand (time(NULL));
    
    compareTrees(10, 5);
    compareTrees(100, 50);
    compareTrees(1000, 500);
    compareTrees(10000, 5000);
    compareTrees(100000, 50000);
    compareTrees(1000000, 500000);
    
    cout << endl;
    
    return 0;
}

void compareTrees(int keys, int searchs){
    
    BTree bt(3);
    ParallelBTree pbt(3);
    
    for(int i = 0; i < keys; i++){
        int value = rand() % 2000 - 1000;
        bt.insert(value);
        pbt.insert(value);
    }
    
    int searchValues[searchs];
    for(int i = 0; i < searchs; i++){
        searchValues[i] = rand() % 10000 - 5000; // -5000 ~ 5000
    }
    
    clock_t begin = clock();
    
    for(int i = 0; i < searchs; i++){
        bt.search(searchValues[i]);
    }
    clock_t end = clock();
    double btElapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    
    begin = clock();
    
    for(int i = 0; i < searchs; i++){
        pbt.search(searchValues[i]);
    }
    end = clock();
    double pbtElapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "Time elapsed for " << keys << " keys and " << searchs << " searchs:" << endl;
    cout << "BTree: " << btElapsedTime << endl;
    cout << "Parallel BTree: " << pbtElapsedTime << endl;
    cout << endl;
}
