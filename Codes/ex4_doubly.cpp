#include <iostream>
using namespace std;

// Define node structure
class Element
{
public:
    int data;
    Element *next;
    Element *prev;

    Element(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLL
{
private:
    Element *head;
    Element *tail;

public:
    DoublyLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end of the list
    void insertAtEnd(int data)
    {
        Element *newNode = new Element(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int data)
    {
        Element *newNode = new Element(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Delete from the end of the list
    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Element *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Delete from the beginning of the list
    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Element *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Print the list in forward direction
    void printForward()
    {
        Element *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print the list in backward direction
    void printBackward()
    {
        Element *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "*** Native List ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.insertAtEnd(5);
    cout << "*** List after inserting 5 at end ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.insertAtBeginning(6);
    cout << "*** List after inserting 6 at beginning ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.deleteAtBeginning();
    cout << "*** List after deleting 6 at beginning ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.deleteAtEnd();
    cout << "*** List after deleting 5 at end ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    return 0;
}