#include <iostream>

struct TreeNode {
    int key;
    int value1;
    int value2;
    TreeNode* left;
    TreeNode* right;
};


int max_sum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int sum = root->value1 + root->value2;
    int left_sum = max_sum(root->left);
    int right_sum = max_sum(root->right);
    if (left_sum > sum) {
        sum = left_sum;
    }
    if (right_sum > sum) {
        sum = right_sum;
    }
    return sum;
}


TreeNode* delete_max_sum_node(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    int sum = root->value1 + root->value2;
    int left_sum = max_sum(root->left);
    int right_sum = max_sum(root->right);
    if (left_sum > sum && left_sum >= right_sum) {
        root->left = delete_max_sum_node(root->left);
    }
    else if (right_sum > sum && right_sum >= left_sum) {
        root->right = delete_max_sum_node(root->right);
    }
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->value1 = temp->value1;
        root->value2 = temp->value2;
        root->right = delete_max_sum_node(root->right);
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode{ 10, 5, 7, nullptr, nullptr };
    root->left = new TreeNode{ 6, 3, 2, nullptr, nullptr };
    root->right = new TreeNode{ 15, 1, 4, nullptr, nullptr };
    root->left->left = new TreeNode{ 4, 8, 6, nullptr, nullptr };
    root->left->right = new TreeNode{ 8, 2, 1, nullptr, nullptr };
    root->right->left = new TreeNode{ 12, 7, 9, nullptr, nullptr };
    root->right->right = new TreeNode{ 18, 3, 5, nullptr, nullptr };

    std::cout << "Max sum: " << max_sum(root) << std::endl;
    root = delete_max_sum_node(root);
    std::cout << "Max sum after deletion: " << max_sum(root) << std::endl;

    return 0;
}