/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    if(head == NULL){
        head = new Node();
        head->data = data;
        return head;
    }
    if(position == 0){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(temp->next){
        count++;
        temp = temp->next;
    }
    if(count +1 == position){
        Node* newNode = new Node();
        newNode->data = data;
        temp->next = newNode;
    }else{
        int i =0;
        temp = head;
        while(i+1 != position){
            temp = temp->next;
            i++;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
