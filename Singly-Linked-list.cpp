#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    friend class Implementation;

public:
    ~Node()
    {
        // deleting next pointer
        delete next;
    }
};

class Implementation
{
private:
    // Memory allocated in heap
    Node *head;

public:
    Implementation();  // constructor
    ~Implementation(); // destructor
    // Basic Linked list functions
    bool isempty() const;
    int listlength();
    void print_list();
    // Implementation functions
    void begininsertNode(int a);
    void endinsertNode(int a);
    void insertinMiddle(int a, int pos);
    // Deletion Functions
    void deletefront();
    void delete_end();
    void delete_middle();
};

void Implementation ::begininsertNode(int a)
{
    cout << "Entering at the front " << endl;
    Node *newNode;
    newNode = new Node;
    if (!newNode)
    {
        cout << "Memory Error" << endl;
        return;
    }
    newNode->data = a;
    newNode->next = head;
    head = newNode;
}
void Implementation::endinsertNode(int a)
{
    cout << "Entering at the end " << endl;
    Node *newNode;
    newNode = new Node;
    if (!newNode)
    {
        cout << "Memory Error" << endl;
        return;
    }
    newNode->data = a;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
}
void Implementation ::insertinMiddle(int a, int pos)
{
    int k = 1;
    Node *position = head;
    Node *newNode = new Node;
    Node *temp;
    newNode->data = a;
    while (k <= pos && position != NULL)
    {
        k++;
        if (k == pos - 1)
        {
            position = position->next;
            temp = position->next;
        }
    }
    position->next = newNode;
    newNode->next = temp;
}

void Implementation ::print_list()
{
    cout << "Linked list Elements are :-" << endl;
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}
bool Implementation ::isempty() const
{
    return head == NULL;
}
int Implementation::listlength()
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

void Implementation::deletefront()
{
    Node *first=head;
    first=NULL;
    head=head->next;
    delete first;
}
void Implementation ::delete_end() {}
void Implementation ::delete_middle() {}

Implementation::Implementation() : head(NULL)
{
    cout << "Constructor called" << endl;
}
Implementation::~Implementation()
{
    cout << "Destructor called" << endl;
    delete head;
}
int main()
{
    Implementation T;
    int p, q, r, s;
    cin >> p >> q >> r >> s;

    // Creating linked list
    T.begininsertNode(p);
    T.begininsertNode(q);
    T.endinsertNode(r);
    T.endinsertNode(s);
    // T.deletefront();
    // Checking whether the list is empty or not
    cout << "Linked list empty--> True" << endl;
    cout << "Linked list empty--> False" << endl;
    bool listempty_or_not = T.isempty();
    if (listempty_or_not)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    T.insertinMiddle(100, 4);
    // Printing list
    T.print_list();

    // To print no. of nodes present in the list
    cout << "No. of nodes:- " << endl;
    int m = T.listlength();
    cout << m << endl;
    return 0;
}