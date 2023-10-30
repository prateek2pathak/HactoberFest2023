void repD(TreeNode<int>* root,int t){
    if(root->children.size()==0){
        root->data=0;
        return;
    }
    root->data=0;
    int n=root->children.size();
    for(int i=0;i<n;i++){
        repD(root->children.at(i), t+1);
        root->children.at(i)->data+=t;
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    int t=1;
    repD(root,t);
}
