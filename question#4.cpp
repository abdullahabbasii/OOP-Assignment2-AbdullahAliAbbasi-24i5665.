#include <iostream>
using namespace std;

struct Customer
{
    int id;
    char name[50];
    int tickets;
    Customer *next;
};

class Queue
{
public:
    Customer *front, *rear;

    Queue()
    {
        front = rear = NULL;
    }

    void enqueue()
    {
        Customer *c = new Customer;
        cout << "Enter Customer ID: ";
        cin >> c->id;
        cout << "Enter Name (one word): ";
        cin >> c->name;
        cout << "Enter Tickets: ";
        cin >> c->tickets;
        c->next = NULL;

        if (rear == NULL)
        {
            front = rear = c;
        }
        else
        {
            rear->next = c;
            rear = c;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue empty.\n";
            return;
        }

        cout << "\nServing Customer (ID " << front->id << ") " << front->name << endl;
        Customer *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue empty.\n";
            return;
        }

        cout << "\nQueue:\n";
        Customer *temp = front;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;
    int choice;

    while (true)
    {
        cout << "\n1. Add Customer\n2. Serve Customer\n3. Show Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            q.enqueue();
        else if (choice == 2)
            q.dequeue();
        else if (choice == 3)
            q.display();
        else if (choice == 4)
            break;
        else
            cout << "Invalid choice.\n";
    }

    return 0;
}
