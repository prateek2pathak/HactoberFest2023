TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == NULL || root->children.size() == 0) {
        return NULL;
    }

    static TreeNode<int>* secHighest=NULL ; 
    static TreeNode<int>* highest=root ;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){

        TreeNode<int> * front=q.front();
        q.pop();
        int n=front->children.size();
        for(int i=0;i<n;i++){
            int temp_data=front->children.at(i)->data;
            q.push(front->children.at(i));
            if(temp_data>highest->data){
                secHighest=highest;
                highest=front->children.at(i);
            }
            else if(highest->data!=temp_data &&( secHighest ==NULL || secHighest->data<temp_data)){
                 secHighest=front->children.at(i);
            }
        }
    }


    return secHighest;
}
