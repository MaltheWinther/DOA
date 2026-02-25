#include <iostream>
#include <queue_class.h>

int main() {
    QueueWithStacks<int> q;

    // Test put (enqueue)
    q.put(10);
    q.put(20);
    q.put(30);

    std::cout << "Front after 3 puts: " << q.front() << std::endl; // 10

    // Test get (dequeue)
    std::cout << "Get (remove): " << q.get() << std::endl; // 10
    std::cout << "Front now: " << q.front() << std::endl; // 20

    // More puts
    q.put(40);
    q.put(50);

    // Remove the rest and print them
    while (!q.empty()) {
        std::cout << "Get: " << q.get() << std::endl;
    }

    // Check if the queue is now empty
    std::cout << "After everything is removed, is the queue empty? " << (q.empty() ? "yes" : "no") << std::endl;

    return 0;
}