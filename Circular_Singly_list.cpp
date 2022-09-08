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
void Implementation::insert_before_node()
{
    Node *newnode = new Node;
    Node *ptr = head;
    Node *temp;
    cout << "Enter the value before which you want to insert a node: " << endl;
    int x;
    cin >> x;
    cout << "Enter value to be inserted: " << endl;
    int num;
    cin >> num;
    newnode->data = num;
    while (ptr->data != x)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        cout << "Node not found" << endl;
    }
    else
    {
        newnode->next = ptr;
        temp->next = newnode;
    }
}
void Implementation::insert_after_node()
{
    Node *newnode = new Node;
    Node *ptr, *preptr;
    cout << "Enter the value after which you want to insert a node: " << endl;
    int x;
    cin >> x;
    cout << "Enter value to be inserted: " << endl;
    int num;
    cin >> num;
    newnode->data = num;
    while (ptr->data != x)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
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
void Implementation::delete_first()
{
    Node *node = head;
    node = NULL;
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    delete node;
}
void Implementation::delete_last()
{
    Node *node = head;
    Node *temp = node;
    while (node->next != head)
    {
        temp = node;
        node = node->next;
    }
    temp->next = head;
    node = NULL;
    delete node;
}
void Implementation::delete_before_node()
{
    Node *temp, *ptr;
    ptr = temp = head;
    cout << "Enter the value before which you want to delete a node: " << endl;
    int x;
    cin >> x;
    if (temp->next->data == x)
    {
        delete_first();
    }
    else if (temp->next->next->data == x)
    {
        ptr = temp->next;
        temp->next = temp->next->next;
        ptr = NULL;
        delete ptr;
    }
    else
    {
        while (temp->next->next->data != x)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next->next = temp->next;
        temp->next = temp->next->next;
        Node *k = ptr->next->next;
        k = NULL;
        delete k;
    }
}
void Implementation::delete_after_node()
{
    Node *temp, *ptr;
    temp = head;
    cout << "Enter the value after which you want to delete a node: " << endl;
    int x;
    cin >> x;

    while (temp->data != x)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        delete_first();
    }
    else
    {
        ptr = temp->next;
        temp->next = temp->next->next;
        ptr = NULL;
        delete ptr;
    }
}
int main()
{
    Implementation Circ;
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.insert_at_first();
    Circ.print_list();
    Circ.delete_after_node();
    // Circ.delete_before_node();
    // Circ.delete_first();
    // Circ.delete_last();
    // Circ.insert_at_last();
    // Circ.insert_at_last();
    // Circ.insert_before_node();
    // Circ.insert_after_node();
    Circ.print_list();
    return 0;
}