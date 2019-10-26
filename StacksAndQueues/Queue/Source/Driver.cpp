#include <iostream>

#include "Queue.h"

using namespace std;

int main() {

    Queue<int> queue;

    queue.enqueue(5);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(10);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(15);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(20);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(25);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(30);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(35);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(40);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(45);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(50);
    cout << "Peek: " << queue.peek() << endl;
    queue.enqueue(55);
    cout << "Peek: " << queue.peek() << endl;

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.enqueue(60);
    cout << "Peek: " << queue.peek() << endl;
    // cout << "Dequeued: " << queue.dequeue() << endl;
    // cout << "Dequeued: " << queue.dequeue() << endl;
    // cout << "Peek: " << queue.peek() << endl;

    return 0;
}