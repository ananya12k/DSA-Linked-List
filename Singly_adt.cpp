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
    int get_length();
    bool isEmpty() const;
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
    cout << "Linked list Elements are :-" << endl;
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
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
    while (ptr->data != x && ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
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
    while (ptr->data != x && ptr != NULL)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void Implementation::delete_first()
{
    Node *node = head;
    node = NULL;
    head = head->next;
    delete node;
}
void Implementation::delete_last()
{
    Node *node = head;
    Node *temp = node;
    while (node->next != NULL)
    {
        temp = node;
        node = node->next;
    }
    temp->next = NULL;
    delete node;
}
void Implementation::delete_before_node()
{
    Node *temp, *ptr;
    ptr = temp = head;
    cout << "Enter the value before which you want to delete a node: " << endl;
    int x;
    cin >> x;
    if (temp->data == x)
    {
        cout << "Node cannot be deleted" << endl;
    }
    else if (temp->next->data == x)
    {
        ptr = temp;
        temp = temp->next;
        ptr = NULL;
        delete ptr;
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
}
bool Implementation ::isEmpty() const
{
    return head == NULL;
}
int Implementation::get_length()
{
    int count = 0;
    Node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
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
    cout << "Welcome to Singly Linked list ADT" << endl;
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
    cout << "Enter the choice 14 to check whether the list is empty or not " << endl;
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
        List.insert_before_node();
        List.print_list();
        break;
    case 5:
        List.insert_after_node();
        List.print_list();
        break;
    case 6:
        List.delete_first();
        List.print_list();
        break;
    case 7:
        List.delete_last();
        List.print_list();
        break;
    case 8:
        List.delete_before_node();
        List.print_list();
        break;
    case 9:
        List.delete_after_node();
        List.print_list();
    case 10:
    {
        cout << "No. of nodes:- " << endl;
        int m = List.get_length();
        cout << m << endl;
    }
    break;

    case 11:
        List.get_nth_node();
        List.print_list();
        break;
    case 12:
        List.print_middle();
        List.print_list();
        break;
    case 13:
        List.reverse_list();
        List.print_list();
        break;
    case 14:
    {
        cout << "Linked list empty--> True" << endl;
        cout << "Linked list empty--> False" << endl;
        bool listempty_or_not = List.isEmpty();
        if (listempty_or_not)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }

    break;
    default:
        break;
    }
}
int main()
{
    Implementation List;
    while (1)
    {
        menu(List);
        std::cout << "Do you want to do any more operations?? " << endl;
        char ans;
        std::cin >> ans;
        while (ans != 'y')
        {

            if (ans == 'y')
            {
                menu(List);
            }
            else
            {
                exit(1);
            }
        }
    }

    return 0;
}