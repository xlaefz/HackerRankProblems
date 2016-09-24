//Given a binary tree, create a ll of all the nodes at each depth

vector<vector<node*> > createLevelLL(node* root)
{
	vector< vector<node*>* >* result = new vector<vector<node*> >();
	vector<node*>* current = new vector<node*>();
	if(root != NULL)
	{
		current->push_back(root);
	}
	while(current.size() != 0 )
	{
		result->push_back(current);
		vector<node*>* parents = current;
		current = new std::vector<node*>();
		for(node* parent: parents)
		{
			if(parent->left)
			{
				current->push_back(parent->left);
			}
			if(parent->right)
			{
				current->push_back(parent->right);
			}
		}
	}
	return result;
}