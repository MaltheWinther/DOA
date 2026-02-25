#include <iostream>
#include <simple_linked_list.h>


int main() {
    
   LinkedList<int> testlist;


    // Test push_front and push_back
    testlist.push_back(1); // List: 3
    testlist.push_back(3);  // List: 1 3
    testlist.push_back(5); // List: 1 3 5
    testlist.push_back(7);  // List: 1 3 5 7

    std::cout << testlist.search(5) << std::endl; //Output = 2
    std::cout << testlist.search(10) << std::endl; //Output = -1
    
   
    return 0;
}   