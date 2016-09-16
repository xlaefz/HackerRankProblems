/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    if(head == NULL){
        head = new Node();
        head->data = data;
        return head;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node();
    temp->next->data = data;
    return head;
    
  // Complete this method
}
