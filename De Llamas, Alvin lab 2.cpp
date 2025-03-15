#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}        

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}    

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" << endl;
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) !=0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;

    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after " + after + "\n";

}

int main(){
    Node *head = createNode("Sanctuary by JOJI");
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    insertAtEnd("Kahit Maputi Na Ang Buhok KO By Rey Valera", head);
    insertAtEnd("Through The Years by Kenny Roger", head);
    insertAtEnd("Two Less People In The World by Air Supply", head);

    head = insertAtBeginning("Ako Naman Muna by Angela Ken", head);
    head = insertAtBeginning("Pangako Sayo by Rey Valera", head);
    head = insertAtBeginning("Ipagpatawad Mo by VST & COMPANY", head);
    head = insertAtBeginning("Nandito Ako by Ogie Alcasid", head);


    traverse(head);
 
   string result = insertAfter("Staring Over Again", "kahit maputi na ang buhok ko", head);
   cout << result;


   string result1 = insertAfter("by Ogie Alcasid", "Nandito Ako", head);
   cout << result1;
   
   
   string result2 = insertAfter("The Lazy song", "Bruno Mars", head);
   string END = deleteAtEnd(head);
   
   cout << END << endl;
   head = deleteFromBeginning(head);
   head = deleteFromGivenNode("Kahit Maputi Na Ang Buhok Ko by Rey Valera",head);
   traverse(head);

    return 0;
}
