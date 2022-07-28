#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
  
    node(int value)        
    {                     
        data = value;     
        next = NULL;    
    }
};

void printlinked(node*& head)
{
    node* temp = head;
  
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int deleteValue(node*& head_ref, int key)
{
    node* temp = head_ref;
    node* prev = NULL;
    int position =0;
    if (temp != NULL && temp->data == key)
    {
        head_ref = temp->next; 
        delete temp;            
        return 0;
    }
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
        position++;
    }
 
    if (temp == NULL)
        return 0;

    prev->next = temp->next;

    delete temp;
    }
    return position;
}


void deleteNode(node*& head_ref, int position)
{
    if (head_ref == NULL)
        return;
  
    node* temp = head_ref;
  
    if (position == 0) {
        head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 2; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next;
}

void deleteList(node** head_ref)
{
 
    /* deref head_ref to get the real head */
    node* current = *head_ref;
    node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}

void append(node*& head, int val)
{
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
  
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void printReverse(node* head)
{
    // Base case
    if (head == NULL)
    return;
    printReverse(head->next);
 
    cout << head->data <<"->";
}

int listLength(node*& item)
{
  node * cur = item;
  int size = 0;

  while (cur != NULL)
  {
    size=size+sizeof(cur->data);
    cur = cur->next;
  }

  return size;
}

int main(){
    node* head = NULL; 
    int choice,temp;
    while(choice!=9){
        cout<<"---------------------------------------MENU---------------------------------------"<<endl;
        cout<<"1.Adding a new node"<<endl;
        cout<<"2.Deleting a particular node (referenced by the location)"<<endl;
        cout<<"3.Delete all the nodes from the list which contain a particular data say a number 5"<<endl;
        cout<<"4.Delete the complete linked list"<<endl;
        cout<<"5.Display the linked list"<<endl;
        cout<<"6.Display the inverted linked list"<<endl;
        cout<<"7.Display the total memory space occupied by the linked list"<<endl;
        cout<<"8.Delete all the nodes from the list which contain a particular data say a number 5 and the next subsequent node"<<endl;
        cout<<"9.Exit\n"<<endl;
        cout<<"Enter Choice ? (Enter Number) ";
        cin>>choice;

        switch(choice){
            case 1:
                int val;
                cout<<"Enter value to be added: "<<endl;
                cin>>val;
                append(head,val);
                break;

            case 2:
                int pos;
                cout<<"Enter position to be deleted: ";
                cin>>pos;
                deleteNode(head,pos);
                break;

            case 3:
                cout<<"Enter value to be deleted: "<<endl;
                cin>>val;
                cout<<deleteValue(head,val);
                break;

            case 4:
                deleteList(&head);
                break;

            case 5:
                printlinked(head);
                break;

            case 6:
                printReverse(head);
                cout<<"NULL"<<endl;
                break;

            case 7:
                cout<<"Size of the Linked List: "<<listLength(head)<<endl;
                break;

            case 8:
                cout<<"Enter value to be deleted: "<<endl;
                cin>>val;
                temp=deleteValue(head,val);
                deleteNode(head,temp);
                break;

            
            default:
                continue;
        }
    }
}