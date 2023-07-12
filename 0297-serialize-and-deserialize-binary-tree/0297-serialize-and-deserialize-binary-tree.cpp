/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) ans.append("#,");
            else ans.append(to_string(node->val)+',');
            if(node!=NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string ans;
        getline(s,ans,',');
        TreeNode* root=new TreeNode(stoi(ans));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,ans,',');
            if(ans=="#")
            {
                node->left=NULL;
            }
            else{
                TreeNode* lNode=new TreeNode(stoi(ans));
                node->left=lNode;
                q.push(lNode);
            }
            getline(s,ans,',');
            if(ans=="#")
            {
                node->right=NULL;
            }
            else{
                TreeNode* rNode=new TreeNode(stoi(ans));
                node->right=rNode;
                q.push(rNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));