#include <iostream>
#include <simple_linked_list.h>

int main()
{
    LinkedList<int> testlist;

    std::cout << "LIST TEST" << std::endl;

    // Test push_front og push_back
    testlist.push_front(3); // Liste: 3
    testlist.push_back(5);  // Liste: 3 5
    testlist.push_front(1); // Liste: 1 3 5

    std::cout << "Efter push_front og push_back:" << std::endl;
    testlist.print();

    // Test size og empty
    std::cout << "Size: " << testlist.size() << std::endl;
    std::cout << "Is empty? " << (testlist.empty() ? "yes" : "no") << std::endl;

    // Test insert i midten
    testlist.insert(7, 2); // Indsæt 7 på plads 2: Liste: 1 3 7 5
    std::cout << "Efter insert(7,2):" << std::endl;
    testlist.print();

    // Test contains
    std::cout << "Contains 3? " << (testlist.contains(3) ? "yes" : "no") << std::endl;
    std::cout << "Contains 8? " << (testlist.contains(8) ? "yes" : "no") << std::endl;

    // Test find_kth
    std::cout << "Element på plads 2: " << testlist.find_kth(2) << std::endl;

    // Test pop_front og pop_back
    int popped_front = testlist.pop_front();
    std::cout << "Efter pop_front (" << popped_front << "):" << std::endl;
    testlist.print();

    int popped_back = testlist.pop_back();
    std::cout << "Efter pop_back (" << popped_back << "):" << std::endl;
    testlist.print();

    // Test remove
    int removed = testlist.remove(1); // burde nu være [3,7], fjerner 7
    std::cout << "Efter remove(1) (" << removed << "):" << std::endl;
    testlist.print();

    // Test reverse
    testlist.push_front(11);
    testlist.push_back(42);
    std::cout << "Før reverse: " << std::endl;
    testlist.print();

    testlist.reverse();
    std::cout << "Efter reverse:" << std::endl;
    testlist.print();

    // Test clear
    testlist.clear();
    std::cout << "Efter clear:" << std::endl;
    testlist.print();
    std::cout << "Is empty? " << (testlist.empty() ? "yes" : "no") << std::endl;

    return 0;
}