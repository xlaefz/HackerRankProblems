/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    struct Node *temp;
  struct Node *newNode = new Node();
  newNode->data=data;
  newNode->next=NULL;
  newNode->prev=NULL;
  temp=head;

if(head==NULL)
 {
    head = newNode;      
 }

else
 {
    while(temp!=NULL)
    {
        if(temp->data<data&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        else
            {
            if(temp->next==NULL&&temp->data<data)
                {
                temp->next = newNode;
                newNode->prev = temp;
                break;
            }

           else if(temp->prev==NULL&&temp->data>data)
                {
                newNode->next=temp;
                temp->prev = newNode;
                head=newNode;
                break;
            }

           else
                {
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next =newNode;
                temp->prev=newNode;
                break;
                }    
             }
         }
   }
  return head;
}
