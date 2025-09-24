#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head!=NULL){
            tail->next=newNode;
            tail=newNode;
        }else{
            head=tail=newNode;
        }
    }

    void pop_front(){
        if (head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
        
    }

    void insert(int val,int pos){
        if(pos<0){
            cout<<"invalid pos"<<endl;
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }

        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"inavlid pos"<<endl;
                return;
            }
            temp=temp->next;
        }

        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void printLL(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int search(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp= temp->next;
            idx++;
        }
        return -1;
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.insert(4,1);
    ll.pop_front();
    ll.pop_back();
    
    ll.printLL();
    cout<<ll.search(2)<<endl;
    return 0;
}