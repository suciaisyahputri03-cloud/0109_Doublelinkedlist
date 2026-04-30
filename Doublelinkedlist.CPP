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
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5: Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        node *currentnode = START;

        // Step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentnode != NULL)
        {
             cout << i + 1 << ": " << currentnode->noMhs << " " << endl;

             // Step 3: Move to next node
             currentnode = currentnode->next;
             i++;
        }
    }

    void revtraverse()
    {
         if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        node *currentnode = START;
        int i = 0;
        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }
    }
    
    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        node *current = START;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
            list.addnode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");

    } while (choice != '6');

    return 0;
}