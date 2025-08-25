
#include <bits/stdc++.h>
using namespace std;

class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
   
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
Node* Convert(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
// Removes head
Node* Removehead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

//Removes tail
Node* Removetail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
void PrintList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr={2,5,8,7};
    Node* head= Convert(arr);
    // head=Removehead(head);
    head=Removetail(head);
    PrintList(head);

    return 0;
}


