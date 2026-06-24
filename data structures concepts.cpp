/*      Part 1: Stack Implementation
        Operations
        1) Push
        2) Pop
        3) Peek/Top
        4) Display */

#include <iostream>
using namespace std;
class Stack
{
private:
    int arr[100];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if(top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top--] << " removed\n";
    }

    void peek()
    {
        if(top == -1)
        {
            cout << "Stack Empty\n";
            return;
        }

        cout << "Top Element: " << arr[top] << endl;
    }

    void display()
    {
        if(top == -1)
        {
            cout << "Stack Empty\n";
            return;
        }

        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

         /*Part 2: Queue Implementation
        Operations
        1)Enqueue
        2)Dequeue
        3)Front
        4)Display*/

class Queue
{
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(int value)
    {
        if(rear == 99)
        {
            cout << "Queue Full\n";
            return;
        }

        arr[++rear] = value;
    }

    void dequeue()
    {
        if(front > rear)
        {
            cout << "Queue Empty\n";
            return;
        }

        cout << arr[front++] << " removed\n";
    }

    void display()
    {
        if(front > rear)
        {
            cout << "Queue Empty\n";
            return;
        }

        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

         /*Part 3: Singly Linked List
        1)Node Structure*/

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
     //2)Linked List Class

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteNode(int value)
    {
        if(head == NULL)
        {
            return;
        }

        if(head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while(current->next != NULL &&
              current->next->data != value)
        {
            current = current->next;
        }

        if(current->next == NULL)
        {
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        delete temp;
    }

    void traverse()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};
          
//Main Menu
int main()
{
    Stack s;
    Queue q;
    LinkedList list;
    int choice;

cout << "\n===== DATA STRUCTURES IMPLEMENTATION =====\n";
cout << "1. Stack\n";
cout << "2. Queue\n";
cout << "3. Linked List\n";
cout << "4. Exit\n";
cout << "Enter choice: ";
cin >> choice;
    switch(choice) {

case 1:
{
    int stackChoice, value;

    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";
        cin >> stackChoice;

        switch(stackChoice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;
        }

    } while(stackChoice != 5);

    break;
}

case 2:
{
    int queueChoice, value;

    do
    {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> queueChoice;

        switch(queueChoice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;
        }

    } while(queueChoice != 4);

    break;
}
case 3:
{
    int listChoice, value;

    do
    {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Traverse\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> listChoice;

        switch(listChoice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.traverse();
                break;
        }

    } while(listChoice != 4);

    break;
}

    }
    return 0;
}