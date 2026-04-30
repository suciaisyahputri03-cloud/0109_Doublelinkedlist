#include <iostream>
#include <string>
using namespace std;

class node 
{
public:
    int noMhs;
    node *nex;
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
           