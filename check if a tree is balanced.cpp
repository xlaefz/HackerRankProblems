int getHeight(node* root)
{
	if(root == NULL) return 0;
	return max(getHeight(root->left) , getHeight(root->right)) + 1;
}

bool isBalanced(node* root)
{
	if(root == NULL) return true;
	int height = getHeight(root->left) - getHeight(root->right);
	if(abs(height) > 1)
	{
		return false;
	}else
	{
		return isBalanced(root->left) && isBalanced(root->right);
	}
}