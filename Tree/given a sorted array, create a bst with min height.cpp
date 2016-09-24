
node* createMinBSTHelper(int array[], int l, int r)
{
	if(r < l) return NULL;
	int mid = l + (r-l)/2; //protects from int overflow
	node* n = new node(array[mid]);
	createMinBSTHelper(array[], l, mid-1);
	createMinBSTHelper(array[], mid+1, r);
	return n;
}

node* createminBST(int array[])
{
	return createMinBSTHelper(array, 0, array.size() -1);
}