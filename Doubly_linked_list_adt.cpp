#include <iostream>
using namespace std;
class Node
{
protected: // Doubly linked had 3 elements
    Node *prev;
    int data;
    Node *next;

public:
    friend class Implementation;
    Node()
    {
        prev = NULL;
        next = NULL;
    }

    ~Node()
    {
        delete prev;
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
    friend void menu(Implementation &list);
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
    void get_length();
    void get_nth_node();
    void print_middle();
    void reverse_list();
};

Implementation::Implementation(/* args */)
{
    head = NULL;
}

Implementation::~Implementation()
{
    delete head;
}
void Implementation::creation()
{
    cout << "Enter how many elements do you want in your list : " << endl;
    int ele;
    cin >> ele;

    for (int i = 0; i < ele; i++)
    {
        insert_at_last();
    }
}
void Implementation::print_list()
{
    Node *node = head;
    cout << "Doubly Linked list Elements are :-" << endl;
    while (node != NULL)
    {
        cout << node->data << endl;
        node = node->next;
    }
}
void Implementation::insert_at_first()
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cout << "Memory Error" << endl;
        return;
    }
    cout << "Enter value to be inserted: " << endl;
    int val;
    cin >> val;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
}
void Implementation::insert_at_last()
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cout << "Memory Error" << endl;
        return;
    }
    cout << "Enter value to be inserted: " << endl;
    int val;
    cin >> val;

    newNode->data = val;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {

        Node *curNode = head;
        while (curNode->next != NULL)
        {
            curNode = curNode->next;
        }
        curNode->next = newNode;
        newNode->next = NULL;
    }
}
void Implementation::insert_before_node()
{
}
void Implementation::insert_after_node()
{
}
void Implementation::delete_first()
{
}
void Implementation::delete_last()
{
}
void Implementation::delete_before_node()
{
}
void Implementation::delete_after_node()
{
}
void Implementation::get_length()
{
}
void Implementation::get_nth_node()
{
}
void Implementation::print_middle()
{
}
void Implementation::reverse_list()
{
}

void menu(Implementation &List)
{
    cout << "Welcome to Doubly Linked list ADT" << endl;
    int x;
    cout << "Enter the choice 1 for creating list using user input and printing it" << endl;
    // cout << "Enter the choice 2 to only print the elements" << endl;
    cout << "Enter the choice 2 to inserting element at first" << endl;
    cout << "Enter the choice 3 to insert element at last" << endl;
    cout << "Enter the choice 4 to insert before a given node" << endl;
    cout << "Enter the choice 5 to insert after a given node " << endl;
    cout << "Enter the choice 6 to deleting first node" << endl;
    cout << "Enter the choice 7 to deleting last node" << endl;
    cout << "Enter the choice 8 to delete before a given node" << endl;
    cout << "Enter the choice 9 to delete after a given node " << endl;
    cout << "Enter the choice 10 to get length of a linked list " << endl;
    cout << "Enter the choice 11 to get Nth node of a linked list " << endl;
    cout << "Enter the choice 12 to print middle of a linked list " << endl;
    cout << "Enter the choice 13 to reverse the list " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter your choice for opertion : " << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        List.creation();
        List.print_list();
        break;
    case 2:
        List.insert_at_first();
        List.print_list();

        break;
    case 3:
        List.insert_at_last();
        List.print_list();
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    case 10:
        /* code */
        break;

    case 11:
        /* code */
        break;
    case 12:
        /* code */
        break;
    case 13:
        /* code */
        break;
    case 14:
        /* code */
        break;
    default:
        break;
    }
}
int main()
{
    Implementation List;
    menu(List);
    while (1)
    {
        std::cout << "Do you want to do any more operations?? " << endl;
        char ans;
        std::cin >> ans;
        if (ans == 'y')
        {
            menu(List);
        }
        else
        {
            exit(1);
        }

        return 0;
    }
}