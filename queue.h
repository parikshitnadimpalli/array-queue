#include <iostream>
#include <new>
#include <string>
#include <limits>
#include <cstdlib>

class Queue
{
    int *arr, size, front, rear;

    public:
    Queue(int);
    void enqueue(int);
    int dequeue();
    void display();
    int count();
};

void clearScreen();
int integerInput();