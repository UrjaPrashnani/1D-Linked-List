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
// inserting at head
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

// inserting at tail
Node* insertTail(Node* head, int val) {
    if (head == NULL)
        return new Node(val);

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}
// insert at before kth position
Node* insertAtK(Node* head, int val, int k) {
    // If the linked list is empty and k is 1, insert the new node as the head
    if (head == NULL) {
        if (k == 1)
            return new Node(val);
        else
            return head;
    }

    // If k is 1, insert the new node at the beginning of the linked list
    if (k == 1)
        return new Node(val, head);

    int cnt = 0;
    Node* temp = head;

    // Traverse the linked list to find the node at position k-1
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            // Insert the new node after the node at position k-1
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

//insert before the value
Node* insertval(Node* head, int el, int val) {
    if (head == NULL) {
        return NULL;
    }

    // Insert at the beginning if the value matches the head's data
    if (head->data == val)
        return new Node(el, head);

    Node* temp = head;
    while (temp->next != NULL) {
        // Insert at the current position if the next node has the desired value
        if (temp->next->data == val) {
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
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
    // head = insertHead(head, 100);
    //head= insertTail(head, 100);
    //head=insertAtK(head,200,2);
    head=insertval(head,200,7);
    PrintList(head);
    return 0;
}