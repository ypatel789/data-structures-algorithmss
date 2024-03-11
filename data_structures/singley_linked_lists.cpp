#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *head;

void Insert(int x, int pos){
    Node* temp1 = new Node();
    temp1 -> data = x;
    temp1 -> next = NULL;
    if(pos == 1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i<pos-2; i++){
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void Print(Node* head){
    if(head == NULL){
        cout << "\n";
        return;
    } 
    cout << head->data << " "; // First print the value in the node
    Print(head->next); // Recursive call
}

void Delete(int n){
    struct Node* temp1 = head;
    if(n==1){
        head = temp1->next;
        delete(temp1);
        return;
    }
    for(int i = 0; i<n-2; i++){
        temp1 = temp1->next; // temp1 points to (n-1)th Node
    }
    struct Node* temp2 = temp1->next; // nth node
    temp1->next = temp2->next;
    delete(temp2);
}

void Reverse(Node* p){
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main (){
    head = NULL;
    int x, n;
    cout << "Hi, Please enter the size of the linked list:" << "\n";
    cin >> n;

    for(int i = 0; i<n; i++){
        cout << "Enter The Number in Position " << i+1 << "\n";
        cin >> x;
        Insert(x,i+1);
        cout << "The List is: ";
        Print(head);
    }
    bool running = true;
    while(running == true){
        cout << "What would you like to do? insert/delete/print/reverse/exit \n" ;
        string action;
        cin >> action;
        if (action == "exit"){
            running = false;
        }
        else if (action == "delete"){
            cout << "Enter the position to delete: \n";
            cin >> n;
            Delete(n);
            cout << "The List is: ";
            Print(head);
        }
        else if (action == "reverse"){
            Reverse(head);
            cout << "The List is: ";
            Print(head);
        }
        else if (action == "insert"){
            int a,b;
            cout << "At what position would you like to insert this number? \n";
            cin >> a;
            cout << "What would you like this number to be? \n";
            cin >> b;
            Insert(b, a);
            cout << "The list is: \n";
            Print(head);
        }

    }
}
