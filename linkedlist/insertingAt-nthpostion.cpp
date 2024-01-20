#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void Insert(int data, int n);
void Print();
void Delete(int n);

Node* head;

int main() {
		head = NULL;// initially list is empty
	Insert(2,1);//List: 2
	Insert(3,2);//List: 2,3
	Insert(4,1);//List: 4,2,3
	Insert(5,2);//List 4,5,2,3
    Insert(1,4);//List 4,5,2,1,3
	
	Print();
    Print();
    Delete(1);
    Print();
	
}


void Insert(int data, int n){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;

    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for (int i = 0; i < n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}



void Delete(int n){
  Node* temp1 = head;
  if(n==1){
    head = temp1->next;
    delete(temp1);
    return;
  }
  for(int i = 0; i < n-2; i++){
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete(temp2);
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n";
    
}
