//delete a node at position x
Node Delete(Node head, int position){
	if(position == 0){
		Node temp = head.next;
		return temp;
	}
	head.next = Delete(head.next, position-1);
	return head;
}

//c++ version

Node* Delete (Node* head, int position)
{
	int count = 0;
    Node temp = head;
    if(position == 0){
        temp = head.next;
        head = temp;
        return head;
    }
    Node prev = head;
    while(temp.next != null)
    {
        if(count == position){
           prev.next = temp.next;
            return head;
        }
        count++;
        prev = temp;
        temp = temp.next;
    }
    if(count == position){
        prev.next = null;
    }
    return head;
}