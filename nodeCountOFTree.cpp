int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root->children.size()==0){
        if(root->data>x){
            return 1;
        }
        return 0;
    }
    int k;
    if(root->data>x) k=1;
    else k=0;

    int n=root->children.size();
    for(int i=0;i<n;i++){
        k+=getLargeNodeCount(root->children.at(i), x);
    }
    return k;
}
