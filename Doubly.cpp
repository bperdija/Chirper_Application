#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Struct Node
{
  int data;
  struct Node* next;
  Node* prev;
};
struct Node* head; // global variable - pointer to head node.



void InsertAtHead(int x)
{
  struct Node* newNode = new Node; // temp is pointer to node. You can fill in values .
  newNode -> data = x;
  newNode -> pref = NULL;
  newNode -> next = NULL;
}

int main()
{

}
