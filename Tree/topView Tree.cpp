void goleft(node* node){
    if(node == NULL) return;
    goleft(node->left);
    cout<< node->data << " " ;
}

void goright(node* node){
    if(node == NULL) return;
        cout<< node->data << " ";
    goright(node->right);
}

void top_view(node * root)
{
    goleft(root->left);
    cout<< root->data << " ";
    goright(root->right);
}
