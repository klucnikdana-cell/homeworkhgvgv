#include <iostream>
#include <stdexcept>
using namespace std;

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

class List
{
private:
    Node* head;

public:
    List()
    {
        head = NULL;
    }

    void Add(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void Remove()
    {
        if (head == NULL)
        {
            throw runtime_error("List is empty");
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void Show()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    List list;

    try
    {
        list.Add(10);
        list.Add(20);
        list.Add(30);

        list.Show();

        list.Remove();
        list.Remove();
        list.Remove();
        list.Remove();
    }
    catch (const runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

