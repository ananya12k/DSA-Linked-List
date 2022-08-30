#include <iostream>
using namespace std;
class Node
{
protected: // Doubly linked had 3 elements
    Node *prev;
    int data;
    Node *next;

public:
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
    void creation() {}
    void print_list() {}
    void insert_at_first() {}
    void insert_at_last() {}
    void insert_before_node() {}
    void insert_after_node() {}
    void delete_first() {}
    void delete_last() {}
    void delete_before_node() {}
    void delete_after_node() {}
    void get_length(){}
    void get_nth_node(){}
    void print_middle() {}
    void reverse_list(){}
};

Implementation::Implementation(/* args */)
{
    head = NULL;
}

Implementation::~Implementation()
{
    delete head;
}
void menu(Implementation &List)
{
    cout << "Welcome to Doubly Linked list ADT" << endl;
    int x;
    cout << "Enter the choice 1 for creating list using user input" << endl;
    cout << "Enter the choice 2 for printing the elements" << endl;
    cout << "Enter the choice 3 to inserting element at first" << endl;
    cout << "Enter the choice 4 to insert element at last" << endl;
    cout << "Enter the choice 5 to insert before a given node" << endl;
    cout << "Enter the choice 6 to insert after a given node " << endl;
    cout << "Enter the choice 7 to deleting first node" << endl;
    cout << "Enter the choice 8 to deleting last node" << endl;
    cout << "Enter the choice 9 to delete before a given node" << endl;
    cout << "Enter the choice 10 to delete after a given node " << endl;
    cout << "Enter the choice 11 to get length of a linked list " << endl;
    cout << "Enter the choice 12 to get Nth node of a linked list " << endl;
    cout << "Enter the choice 13 to print middle of a linked list " << endl;
    cout << "Enter the choice 14 to reverse the list " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enter your choice for opertion : " << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
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