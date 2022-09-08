#include <iostream>
using namespace std;
class Node
{
protected:
    int data;
    Node *next;

public:
    friend class Implementation;
    Node()
    {
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};
class Implementation
{
private:
    Node *head;

public:
    Implementation(/* args */);
    ~Implementation();
    void creation();
    void print_list();
    void insert_at_first();
    void insert_at_last();
    void insert_before_node();
    void insert_after_node();
    void delete_first();
    void delete_last();
    void delete_before_node();
    void delete_after_node();
    int get_length();
    bool isEmpty() const;
};

Implementation::Implementation(/* args */)
{
    head = NULL;
}

Implementation::~Implementation()
{
    delete head;
}
void Implementation::print_list()
{
    cout << "Linked list Elements are :-" << endl;
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }
}
void Implementation::insert_at_first()
{
    Node *newnode = new Node;
    cout << "Enter value to be inserted: " << endl;
    int val;
    cin >> val;
    newnode->data = val;
    if (head == NULL)
    {

        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void Implementation::insert_at_last()
{
    Node *newnode = new Node;
    cout << "Enter value to be inserted: " << endl;
    int val;
    cin >> val;
    newnode->data = val;
    if (head == NULL)
    {

        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }
}
int main()
{
    Implementation Circ;
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.insert_at_last();
    Circ.insert_at_last();
    Circ.print_list();
    return 0;
}