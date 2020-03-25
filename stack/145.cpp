/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack < pair < TreeNode* , int >  > st;
    vector<int> postorderTraversal(TreeNode* root) {
        vector < int > ans;
        if(root==NULL) return ans;
        st.push(make_pair(root , 0));
        while(st.size()){
            if(!st.top().second){
                TreeNode* temp = st.top().first;
                if(temp->left == NULL && temp->right == NULL){
                    st.pop();
                    ans.push_back(temp->val);
                } 
                else if(temp->left){
                    st.pop();
                    st.push(make_pair(temp , 1));
                    st.push(make_pair(temp->left , 0));
                }
                else{
                    st.pop();
                    st.push(make_pair(temp , 2));
                    st.push(make_pair(temp->right , 0));
                }
            
            }
            else if(st.top().second == 1){
                TreeNode* temp = st.top().first;
                if(temp->right){
                    st.pop();
                    st.push(make_pair(temp , 2));
                    st.push(make_pair(temp->right , 0));
                }
                else{
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else {
                TreeNode* temp = st.top().first;
                st.pop();
                ans.push_back(temp->val);
            }
        }
        
        return ans;
    }
};
