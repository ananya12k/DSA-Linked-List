#include <iostream>
using namespace std;
class node
{
   friend class poly;

   int coeff;
   int exp;
   node *link;

public:
   node(int c, int e)
   {
      coeff = c;
      exp = e;
      link = NULL;
   }
};

class poly
{
   node *first;

public:
   poly()
   {
      first = NULL;
   }
   void insert_end(int c, int e)
   {
      if (first == NULL)
      {
         first = new node(c, e);
      }
      else
      {
         node *nn = new node(c, e);
         node *temp = first;
         while (temp->link != NULL)
         {
            temp = temp->link;
         }
         temp->link = nn;
      }
   }
   void add(node *head1, node *head2)
   {
      node *f = head1;
      node *s = head2;
      while (f != NULL && s != NULL)
      {
         if (f->exp == s->exp)
         {
            insert_end((f->coeff + s->coeff), f->exp);
            f = f->link;
            s = s->link;
         }
         else if (f->exp < s->exp)
         {
            this->insert_end(s->coeff, s->exp);
            s = s->link;
         }
         else if (f->exp > s->exp)
         {
            this->insert_end(f->coeff, f->exp);
            f = f->link;
         }
      }
      while (f != NULL)
      {
         this->insert_end(f->coeff, f->exp);
         f = f->link;
      }
      while (s != NULL)
      {
         this->insert_end(s->coeff, s->exp);
         s = s->link;
      }
   }

   node *getfirst()
   {
      return first;
   }
   void display()
   {
      node *temp = first;
      while (temp->link != NULL)
      {
         cout << temp->coeff << "x^" << temp->exp << " + " << endl;
         temp = temp->link;
      }
      cout << temp->coeff << "x^" << temp->exp << endl;
   }
};

int main()
{
   int m;
   cout << "Enter no. of terms:";
   cin >> m;
   poly p1, p2;
   int c, e;
   cout << "Enter co and exp:";
   for (int i = 0; i < m; i++)
   {
      cin >> c >> e;
      p1.insert_end(c, e);
   }

   cout << "Enter no. of terms:";
   cin >> m;

   cout << "Enter co and exp:";
   for (int i = 0; i < m; i++)
   {
      cin >> c >> e;
      p2.insert_end(c, e);
   }
   poly p3;
   p3.add(p1.getfirst(), p2.getfirst());
   p3.display();
   return 0;
}