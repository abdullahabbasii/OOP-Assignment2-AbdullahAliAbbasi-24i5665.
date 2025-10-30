#include <iostream>
using namespace std;

class Node 
{
public:
    char data;
    Node* next;
    Node(char c) 
    { 
        data = c; 
        next = nullptr; 
    }
};

class NodeStack 
{
private:
    Node* top;
public:
    NodeStack() 
    { 
        top = nullptr; 
    }
    void push(char c) 
    {
        Node* node = new Node(c);
        node->next = top;
        top = node;
    }
    char pop() 
    {
        if (top == nullptr)
            return '\0';
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }
    bool empty()
    {
        return top == nullptr;
    }
};

class ArrayStack 
{
private:
    char* arr;
    int size;
    int top;
public:
    ArrayStack() 
    { 
        size = 10;
        arr = new char[size];
        top = -1;
    }
    void push(char c) 
    {
        if (top == size - 1) 
        {
            char* temp = new char[size * 2];
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            size *= 2;
        }
        arr[++top] = c;
    }
    char pop() 
    {
        if (top < 0)
            return '\0';
        return arr[top--];
    }
    bool empty()
    {
        return top == -1;
    }
};

void ChangeLocationArray(char* Array, int b1, int b2) 
{
    ArrayStack stack;
    for (int i = b1 - 1; i < b2; i++)
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++)
        Array[i] = stack.pop();
}

void ChangeLocationList(char* Array, int b1, int b2) 
{
    NodeStack stack;
    for (int i = b1 - 1; i < b2; i++)
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++)
        Array[i] = stack.pop();
}

void PrintPatternArray(int n) 
{
    ArrayStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2)
            {
                stack.push('2');
                rem -= 2;
            }
            else
            {
                stack.push('1');
                rem--;
            }
        }
        char c;
        while ((c = stack.pop()) != '\0')
            cout << c << " ";
        cout << endl;
    }
}

void PrintPatternList(int n) 
{
    NodeStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2)
            {
                stack.push('2');
                rem -= 2;
            }
            else
            {
                stack.push('1');
                rem--;
            }
        }
        char c;
        while ((c = stack.pop()) != '\0')
            cout << c << " ";
        cout << endl;
    }
}

int main() 
{
    char arr1[] = "COMPUTER";
    char arr2[] = "COMPUTER";

    cout << "Original Array: " << arr1 << endl;

    cout << "\nArray-based Stack Implementation:\n";
    ChangeLocationArray(arr1, 3, 7);
    cout << "Changed: " << arr1 << endl;

    cout << "\nLinked List-based Stack Implementation:\n";
    ChangeLocationList(arr2, 3, 7);
    cout << "Changed: " << arr2 << endl;

    cout << "\nPattern for n=4 (Array-based Stack):\n";
    PrintPatternArray(4);

    cout << "\nPattern for n=4 (Linked List-based Stack):\n";
    PrintPatternList(4);

    cout << "\n----- Simple Explanation -----\n";
    cout << "In both stacks, push adds an item and pop removes it from the top.\n";
    cout << "The linked list stack stores items using nodes.\n";
    cout << "The array stack stores items in a dynamic array.\n";
    cout << "Both give the same results, just use different storage methods.\n";

    return 0;
}
 