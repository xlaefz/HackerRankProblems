void kthLargest(node* root,int &k,int c)   
{
    if(root==NULL)
        return;   
 
    kthLargest(root->right,k,c);  // First recurse for the right sub-tree
 
    k=k-1; // Here k is a reference variable
 
    if(k==0)
        printf("%d-Largest is %d\n",c,root->data);   // Variable c is used just for the print statement
 
    kthLargest(root->left,k,c); // Recurse for the left sub-tree
}