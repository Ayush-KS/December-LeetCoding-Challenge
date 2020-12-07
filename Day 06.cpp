// Populating Next Right Pointers in Each Node II

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        if(root -> left) {
            Node* temp = root;
            if(temp -> right) {
                temp -> left -> next = temp -> right;
            } else {
                temp = temp -> next;
                while(temp) {
                    if(temp -> left) {
                        root -> left -> next = temp -> left;
                        break;
                    } 
                    else if(temp -> right) {
                        root -> left -> next = temp -> right;
                        break;
                    }
                    temp = temp -> next;
                }
            }
        }
        if(root -> right) {
            Node* temp = root -> next;
            while(temp) {
                if(temp -> left) {
                    root -> right -> next = temp -> left;
                    break;
                } 
                else if(temp -> right) {
                    root -> right -> next = temp -> right;
                    break;
                }
                temp = temp -> next;
            }
        }
        root -> right = connect(root -> right);
        root -> left = connect(root -> left);
        return root;
    }
};