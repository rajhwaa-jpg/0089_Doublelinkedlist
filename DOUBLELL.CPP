#include<iostream>
#include<string>
#include <windows.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *nodeBaru = new Node;

        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }

            nodeBaru->next = START;

            if (START != NULL)
                START->prev = nodeBaru;

            nodeBaru->prev = NULL;

            START = nodeBaru;
            return;
        }

        Node *current = START;

        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        nodeBaru->next = current->next;
        if (current->next != NULL)
            current->next->prev = nodeBaru;

        nodeBaru->prev = current;
        current->next = nodeBaru;
    }

