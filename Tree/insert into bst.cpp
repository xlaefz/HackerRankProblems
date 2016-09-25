node * insert(node * root, int value)
{
    if(root == NULL){
        node* newnode = new node();
        newnode->data = value;
        return newnode;
    }
    else if(root->data >= value){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
   return root;
}
