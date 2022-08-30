#include <iostream>
using namespace std;
class Node
{
protected:
    int data;
    Node *next;
public:
    Node()
    {
        next=NULL;
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
};

Implementation::Implementation(/* args */)
{
}

Implementation::~Implementation()
{
}

int main()
{

    return 0;
}