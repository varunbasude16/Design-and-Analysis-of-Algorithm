#include<iostream>
#include<vector>
using namespace std;

struct Node {
      int val;
      Node *next;
      Node(int x){
            val = x;
            next = NULL;
      }
  };


bool hasCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
}

void makeCycle(Node* head){
    if(head == NULL) return;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    
}
void LinkNonCyclic(){

}
Node* insertAtEnd(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


int main() {
    cout<<"Enter number of nodes: ";
    int n;
    cin>>n;
    Node* head = NULL;
    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        head = insertAtEnd(head, val);
    }
    cout<<"create a cycle? (1 for yes, 0 for no): ";
    int choice;
    cin>>choice;
    if(choice)  
        makeCycle(head);
  
    cout<< (hasCycle(head )? "Its has cycle": "Its has no cycle ")<<endl;

    return 0;
}

