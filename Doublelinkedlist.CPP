#include <iostream>
#include <string>
using namespace std;

class node 
{
public:
    int noMhs;
    node *next;
    node *prev;
};

class DoubleLinkedList
{
private:
    node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // step 1; allocate memory for new node
        node *newnode = new node();

        //step 2; assign value to the data fields
        newnode->noMhs = nim;

        //step 3: insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START == NULL || nim <= START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //step 4: newnode.next = START
            newnode->next = START;

            // setep 5: START.prev= newnode (if START exists)
            if (START != NULL )
                START->prev = newnode;

            // step 6: newnode.prev = NULL
            newnode->prev = NULL;

            //step 7: START =newnode
            START = newnode;
            return;
        }

        // insert in betwen node
        // step 8: locate positton for insertion
        node *current = START;
        while (current->next != NULL && nim == current->next->noMhs)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // step 9: insert betwen current and current->next
        newnode->next = current->next; // step 9a: newnode.next = current.next
        newnode->prev = current;       // step 9b: newnode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newnode; // step 9c: current.next.prev = newnode

        current->next = newnode; // step 9d: current.next =newnode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be delete: ";
        int rollNo;
        cin >> rollNo;

        node *current = START;

        //step 1: traverse the list list to find the node
        while (current !=  NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "record not found" << endl;
            return;
        }

        // step 2: if node is a the beginning
        if (current == START)
        {
            START = current->next; // step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // step 2b: START.prev = NULL 
        }
        else
        {
            
        }

    }
           