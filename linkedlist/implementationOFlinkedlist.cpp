#include<bits/stdc++.h>
#include<iostream>
 
using namespace std;




struct Node
{
    /* data */
    int data;
    Node *next;
};


Node* head;

void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

Node* tempNode(int d){
  Node *temp = new Node();
  temp->data = d;
  temp->next = nullptr;

  return temp;
}

int main(){

  head = nullptr;
  Node* A = tempNode(4);
  Node* B = tempNode(5);
  Node* C = tempNode(7);

  head = A;
  A->next = B;
  B->next = C;
  
  traverse();



}