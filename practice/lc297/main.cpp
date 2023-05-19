#include "solution.h"

int main(void)
{

    cout << "haha" << endl;

    Codec solution_obj;


    return 0;
}



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:

//     void width_first_traversal(TreeNode *root, string &encoded_str)
//     {
//         if(root!=nullptr)
//         {
//             return;
//         }

//         queue<TreeNode> node_queue;
//         node_queue.push(*root);
//         encoded_str.append(to_string(root->val));

//         while(node_queue.size()!=0)
//         {
//             TreeNode node_ref = node_queue.front();
//             node_queue.pop();
            
//             if(node_ref.left!=nullptr)
//             {
//                 node_queue.push(*node_ref.left);
//                 encoded_str.append(to_string(node_ref.left->val)+"_");
//             }
//             else{
//                 encoded_str.append("#_");
//             }
//             if(node_ref.right!=nullptr)
//             {
//                 node_queue.push(*node_ref.right);
//                 encoded_str.append(to_string(node_ref.right->val)+"_");
//             }
//             else{
//                 encoded_str.append("#_");
//             }

//         }

//     }

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
        
//         string ret_str;

//         vector<TreeNode> node_list;
//         width_first_traversal(root, ret_str);

//         return ret_str;
//     }




//     TreeNode *construct_tree_from_str_queue(vector<string> &node_val_vec)
//     {
//         // vector<TreeNode *> node_vec;
//         // for(int i=0;i<node_val_vec.size();i++)
//         // {
//         //     if(node_val_vec[i]=="#")
//         //     {
//         //         node_vec.push_back(nullptr);
//         //     }
//         //     else{
//         //         int node_val = atoi(node_val_vec[i].c_str());
//         //         TreeNode * new_node = new TreeNode(node_val);
//         //         node_vec.push_back(new_node);
//         //     }
            
//         // }

        
        
//         for(int i=0; i<node_val_vec.size(); i++)
//         {    
//             if(node_val_vec[i]=="#")
//             {
//                 continue;
//             }
//             int l_idx = i*2+1;
//             int r_idx = i*2+2;

//             int node_val = 
//             TreeNode* new_node = new TreeNode();
            
//             // node_vec[i]->left = node_vec[l_idx];
//             // node_vec[i]->right = node_vec[r_idx];
//         }

//         return node_vec[0];
//     }


//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         // 第一步进行数组切分

//         char *s_input = (char *)data.c_str();
//         char *split_arr = strtok(s_input, "_"); // 注意这是一个c函数，需要引入 string.h 单单引入string是不够的

//         // 将字符串使用下划线进行分割，放入队列中
//         vector<string> node_val_vec;

//         while (split_arr != NULL)
//         {
//             node_val_vec.push_back(split_arr);
//             split_arr = strtok(NULL, "_");
//         }


//         return construct_tree_from_str_queue(node_val_vec);
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec codec;
// // codec.deserialize(codec.serialize(root));