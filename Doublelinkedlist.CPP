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
}