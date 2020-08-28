#include <iostream>
using namespace std;

class Node
{
public:
  int key;
  int data;
  Node* next; // pointer of type Node that points to Node type

  Node()
  {
    key = 0;
    data = 0;
    next = NULL;
  }

  Node(int k, int d)
  {
    key = k;
    data = d;
  }
};

class SinglyLinkedList
{
public:
  Node* head; // pointer points to head of node.

  SinglyLinkedList()
  {
    head = NULL;
  }

  SinglyLinkedList(Node *n)
  {
    head = n;
  }

  Node* nodeExists(int k)
  {

  }


  
};

int main(0)
{
  return 0;
}
