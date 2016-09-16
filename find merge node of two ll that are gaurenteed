/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int findLength(Node* head){
    int count =0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}
int FindMergeNode(Node *headA, Node *headB)
{
    int lenA = findLength(headA);
    int lenB = findLength(headB);
    while(lenA > lenB){
        lenA--;
        headA = headA->next;
    }
    while(lenB > lenA){
        lenB--;
        headB = headB->next;
    }
    while(headA != NULL){
        if(headA == headB) return headA->data;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
