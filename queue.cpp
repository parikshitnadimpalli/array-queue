#include "queue.h"

using namespace std;

Queue::Queue(int s = 10)
{
    if (s <= 0)
    {
        cout << endl << "Array size cannot be 0 or negative! Please enter again: ";
        *this = Queue(integerInput());
    }
    else
    {
        size = s;
        arr = new (nothrow) int[size];
        if (arr == nullptr)
        {
            cout << endl << "Failed to allocate memory to the array! Please restart the application";
            abort;
        }
        front = rear = -1;

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
}

void Queue::enqueue(int elem)
{
    if (elem == 0)
    {
        cout << endl << "0 is not a valid data value! Please enter again: ";
        enqueue(integerInput());
    }
    
    if (rear == -1)
    {
        front = rear = 0;
        arr[rear] = elem;
        cout << endl << "Value successfully enqueued!" << endl;
    }
    else if (count() == size)
    {
        cout << endl << "Queue overflow! No more values can be added!" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = elem;
        cout << endl << "Value successfully enqueued!" << endl;
    }
}

int Queue::dequeue()
{
    int temp;
    
    if (front == -1)
    {
        cout << endl << "Queue underflow! No more values can be removed!" << endl;
        return 0;
    }
    else if (front == rear)
    {
        temp = arr[front];
        arr[front] = 0;
        front = rear = -1;
        return temp;
    }
    else
    {
        temp = arr[front];
        arr[front] = 0;
        front = (front + 1) % size;
        return temp;
    }
}

void Queue::display() 
{ 
    if (front == -1) 
    { 
        cout << endl << "Queue is empty!"; 
        return; 
    } 

    cout << endl << "The elements in the queue are: " << endl; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout << " " << arr[i]; 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            cout << " " << arr[i]; 
  
        for (int i = 0; i <= rear; i++) 
            cout << " " << arr[i]; 
    }
    cout << endl; 
} 

int Queue::count()
{
    if (front > rear)
        return size - ((front - rear) - 1);
    else if (front == -1)
        return 0;
    else
        return (rear - front) + 1;
}

void clearScreen()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

int integerInput()
{
    int n;

    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << endl << "Invalid integer input! Please try again with correct input: ";
    }

    return n;
}