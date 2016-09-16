/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    if(head == NULL) return head;
    Node* iter = head;
    while(iter->next){
        if(iter->data == iter->next->data){
            Node* temp = iter->next->next; 
            delete iter->next;
            iter->next = temp;
        }else{
            iter = iter->next;
        }
    }
    return head;
}