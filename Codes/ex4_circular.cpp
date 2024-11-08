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

// Circular Doubly Linked List class
class CircularDoublyLL
{
private:
    Element *head;
    Element *tail;

public:
    CircularDoublyLL()
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
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
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
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            tail->next = head;
            head->prev = tail;
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
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            Element *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
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
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            Element *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    // Print the list in forward direction
    void printForward()
    {
        Element *current = head;
        if (head != nullptr)
        {
            do
            {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
        }
        cout << endl;
    }

    // Print the list in backward direction
    void printBackward()
    {
        Element *current = tail;
        if (tail != nullptr)
        {
            do
            {
                cout << current->data << " ";
                current = current->prev;
            } while (current != tail);
        }
        cout << endl;
    }
};

int main()
{
    CircularDoublyLL list;

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

    list.insertAtBeginning(34);
    cout << "*** List after inserting 34 at Beginning ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.deleteAtEnd();
    cout << "*** List after Deleting 5 at end ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;

    list.deleteAtBeginning();
    cout << "*** List after Deleting 34 at Beginning ***" << endl;
    cout << "Forward" << endl;
    list.printForward();
    cout << "Backward" << endl;
    list.printBackward();
    cout << " " << endl;
}