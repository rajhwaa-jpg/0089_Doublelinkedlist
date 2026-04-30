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

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nRecord not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current;
        cout << "\nRecord with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;

        cout << "\nRecords in ascending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void reverseTraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 1;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        cout << "\nRecords in descending order of roll number are:\n";

        while (currentNode != NULL)
        {
            cout << i << ". " << currentNode->noMhs << " ";
            currentNode = currentNode->prev;
            i--;
        }

        cout << endl;
    }

    void search()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nRecord not found" << endl;
        }
        else
        {
            cout << "\nRecord found" << endl;
            cout << "\nRoll number: " << current->noMhs << endl;
        }
    }
};

