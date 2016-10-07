void mirror(node* node){
	if(node == NULL){
		return;
	}
	else{
		node* temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}