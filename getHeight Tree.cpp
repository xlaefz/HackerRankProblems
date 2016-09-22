int getHeight(node* root){
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
int height(node * root)
{
    if(root == NULL) return 0;
  return getHeight(root) -1;
}

//this has root as height 0; if we have root as 1 remove the -1