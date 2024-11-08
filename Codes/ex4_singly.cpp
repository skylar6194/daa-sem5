#include <iostream>
using namespace std;

// Define node structure
class Element
{
public:
    int data;
    Element *next;

    Element(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Singly Linked List class
class SinglyLL
{
private:
    Element *head;
    Element *tail;

public:
    SinglyLL()
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
            Element *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
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
            delete temp;
        }
    }

    // Print the list
    void printList()
    {
        Element *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~SinglyLL()
    {
        while (head != nullptr)
        {
            Element *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SinglyLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Native List: " << endl;
    list.printList();

    list.insertAtEnd(5);

    cout << "List after inserting 5 at end: " << endl;
    list.printList();

    list.insertAtBeginning(5);
    cout << "List after inserting 5 at beginning: " << endl;
    list.printList();

    list.deleteAtBeginning();
    cout << "List after deleting 5 at beginning: " << endl;
    list.printList();

    list.deleteAtEnd();
    cout << "List after deleting 5 at end: " << endl;
    list.printList();

    return 0;
}