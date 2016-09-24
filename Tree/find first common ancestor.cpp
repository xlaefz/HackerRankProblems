bool inTree(node* root, node* curr)
{
	if(root == NULL) return false;
	if(root == curr) return true;
	return inTree(root->left, curr) || inTree(root->right, curr);
}

node* commonAncestorHelper(node* root, node* p, node*q)
{
	if(root == NULL) return NULL;
	if(root == p || root == q) return root;
	bool ponleft = inTree(root->left, p);
	bool qonright = inTree(root->right, q);
	//if ponleft is false p is on right 
	//if "" is true p is on left
	//if qonright is false q is on left
	//if "" is true q is on right
	if(ponleft != qonright) //if on diff side, return root
	{
		return root;
	}
	if(ponleft == true)
	{
		return commonAncestorHelper(root->left, p, q);
	}
	else
	{
		return commonAncestorHelper(root->right, p, q);
	}
}


node* findFirstCommonAncestor(node* root, node* p, node* q)
{
	if(!inTree(root, p) || !inTree(root, q)) //check if p and q are in tree
	{
		return NULL
	}
	return commonAncestorHelper(root, p, q);
}