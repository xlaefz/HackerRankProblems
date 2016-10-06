
int sum(node* root)
{
	if(root == NULL) return 0;
	return sum(root->left) + root->data + sum(root->right);
}


bool isSumTree(node* root)
{
	int ls, rs;
	if(root == NULL || root->left == NULL && root->right == NULL) return true;
	ls = sum(root->left);
	rs = sum(root->right);
	if(root->data == ls + rs && isSumTree(root->left) && isSumTree(root->right))
	{
		return true;
	}
	return false;
}