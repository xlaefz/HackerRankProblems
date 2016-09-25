node* deletenodeswithvalue(int value, node* head){
	if(!head) return head;

	node* prev = NULL;
	node* curr = head;
	while(curr && curr->data == value){
		prev = curr;
		curr = curr->next;
		head = curr;
		delete prev;
	}
	while(curr){
		if(curr->data == value){
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}else{
			prev = curr;
			curr = curr->next;
		}
	}
	return head;
}