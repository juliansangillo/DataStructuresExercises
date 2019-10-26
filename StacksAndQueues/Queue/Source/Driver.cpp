#include <iostream>

#include "Queue.h"

using namespace std;

int main() {

    Queue<int> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);

    return 0;
}