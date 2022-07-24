#include "queue.h"

using namespace std;

int main()
{
    cout << "--------------------Implementing Circular Queue DS using array--------------------" << endl << endl;
    cout << "Enter the size of the array (default size is 10): ";
    Queue *q = new (nothrow) Queue(integerInput());
    if (q == nullptr)
    {
        cout << endl << "Unable to allocate memory for the Queue. Please restart the application!";
        return 0;
    }
    cout << endl << endl;

    int op, val;
    string msg;

    while(1)
    {
        cout << endl << "---------------Options---------------" << endl;
        cout << "NOTE: 0 value is not accepted as valid data" << endl;
        cout << "1. Enqueue a value" << endl;
        cout << "2. Dequeue a value" << endl;
        cout << "3. Display the values in the Queue" << endl;
        cout << "4. Count the number of values in the Queue" << endl;
        cout << "5. Clear the screen" << endl;
        cout << "6. Exit" << endl;
        cout << endl << "Enter your choice: ";

        op = integerInput();
        switch(op)
        {
            case 1:
                cout << endl << "Enter the value to be Enqueued: ";
                q->enqueue(integerInput());
                break;
            case 2:
                val = q->dequeue();
                msg = val == 0 ? " " : "The Dequeued value is: ";
                cout << endl << msg << val << endl;
                break;
            case 3:
                q->display();
                break;
            case 4:
                cout << endl << "The Queue has " << q->count() << " values." << endl;
                break;
            case 5:
                clearScreen();
                break;
            case 6:
                return 0;
                break;
            default:
                cout << endl << "Wrong option! Please try again!";
                break;
        }
    }
}