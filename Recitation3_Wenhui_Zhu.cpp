#include<iostream>
#include<stdio.h>

using namespace std;

class Node {
    public:
    string name;
    int waitInterval;
    Node *next;

    Node(string n, int w) {
        name = n;
        waitInterval = w;
        next = NULL;
    }
};

Node *add_element(Node *head, string name, int waitInterval) {
    Node *addElement = new Node(name, waitInterval);

    if(head == NULL || head->waitInterval > waitInterval){
        addElement->next = head;
        head = addElement;
    }
    else{
        Node *pivot = head;
        while(pivot->next != NULL){
            if(pivot->next->waitInterval > waitInterval){
                addElement->next = pivot->next;
                pivot->next = addElement;
                break;
            }
            pivot = pivot->next;
        }
        if(pivot->next == NULL){
            pivot->next = addElement;
        }
    }

    return head;
}

Node *delete_element(Node *head){
    if(head==NULL){
        return NULL;
    }
    string name = head->name;
    int waitInterval = head->waitInterval;
    cout<<name<< " plane landing successed! "<<endl;
    head=head->next;
    return head;
}

void checkAllElements(Node *head){
    if(head == NULL){
        cout<< "No planes in waiting list"<<endl;
        return;
    }
    Node *temp = head;
    cout<<"All planes landing requests: " <<endl;

    while(temp!=NULL){
        cout<<temp->name<<" need to wait " <<temp->waitInterval<<endl;
        temp = temp->next;  
    }
}


int main(){
    Node *head = NULL;
    cout<< " Welcome to plane landing system\n "<<endl;
    string name;
    int waitInterval;
    int option;
    

    do{
        cout<<"====================================="<<endl;        
        cout<<" 1. Make a Landing request "<<endl;
        cout<<" 2. Land a Plane "<<endl;
        cout<<" 3. List All the landing requests "<<endl;
        cout<<" 4. Exit "<<endl;  
        cout<<"====================================="<<endl;
        cout<<" Please Input your choice:  "<<endl;        
        cin>>option;    

        switch (option){
            case 1:
                cout<<"===================================="<<endl;
                cout<< " enter plane name: ";
                cin.ignore();
                getline(cin,name);
                cout<<" enter wait time : ";
                cin>>waitInterval;
                head = add_element(head,name,waitInterval);
                cout<<"Sending request is successful! "<<endl;
                break;

            case 2:
                cout<<"===================================="<<endl; 
                head = delete_element(head);
                break;
            case 3: 
                cout<<"===================================="<<endl;
                checkAllElements(head);
                break;
        }                           
    }
    while(option!=4);
}