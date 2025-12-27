#include<bits/stdc++.h>
using namespace std;

class Stack{
    int arr[100];
    int top=-1;
public:
    void push(int num){
        if(top==99){
            cout<<"Stack Overflow\n";
            return ;
        }
        top++;
        arr[top]=num;
    }

    int pop(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return -1;
        }
        cout<<"The element popped is:";
        return arr[top--];
    }

    int peek(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return -1;
        }
        cout<<"The peek element is:";
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==100-1;
    }

    int size(){
        return top+1;
    }

    void display(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return;
        }

        for(int i=top;i>=0;i--) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter the number of elements to be entered into the stack: ";
    cin>>n;

    Stack s; //object created

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter the element:";
        cin>>val;
        s.push(val);
    }

    cout<<s.peek()<<endl;
    
    s.display();

    cout<<s.pop()<<endl;

    s.display();

    return 0;
}
