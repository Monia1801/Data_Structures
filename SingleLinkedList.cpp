#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* n=NULL;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
    display(head);
}

void insertAtBeg(Node* &head,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    display(head);
}

void insertAtPos(Node* &head, int data, int position){

    if(position < 1){
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(data);

    if(position == 1 || head==NULL){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(temp != NULL && cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL){
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    display(head);
}

void insertAtEnd(Node* &head,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;

    display(head);
}

int main(){
    int n;
    cout<<"Enter number of nodes to be inserted:";
    cin>>n;

    Node* head=NULL;
    Node* temp=NULL;

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter node value:";
        cin>>val;

        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    cout<<"The elements in the list are: ";
    display(head);

    cout<<"Reverse of the list is: ";
    reverse(head);

    cout<<"Enter value to insert at beginning:";
    int beg;
    cin>>beg;
    insertAtBeg(head,beg);


    cout<<"Enter value to be inserted at end:";
    int end;
    cin>>end;
    insertAtEnd(head,end);

    cout<<"Enter value and position(1-based) to insert the node:";
    int ele,pos;
    cin>>ele>>pos;
    insertAtPos(head,ele,pos);

    return 0;
}