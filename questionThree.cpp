#include <iostream>

struct Node
{
    Node* left;
    Node* right;
};

bool hasDuplicateNode(Node* root)
{
    if (root == nullptr)
        return false;

    Node* leftSubtree = root->left;
    Node* rightSubtree = root->right;

    if (hasDuplicateNode(leftSubtree))
        return true;

    if (hasDuplicateNode(rightSubtree))
        return true;

    while (leftSubtree != nullptr)
    {
        if (leftSubtree == root)
            return true;
        leftSubtree = leftSubtree->right;
    }

    while (rightSubtree != nullptr)
    {
        if (rightSubtree == root)
            return true;
        rightSubtree = rightSubtree->left;
    }

    return false;
}

int main()
{

    Node* root = new Node();
    Node* leftChild = new Node();
    Node* rightChild = new Node();
    Node* duplicateNode = new Node();

    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = duplicateNode;
    leftChild->right = nullptr;
    rightChild->left = nullptr;
    rightChild->right = nullptr;
    duplicateNode->left = nullptr;
    duplicateNode->right = nullptr;

    bool hasDuplicate = hasDuplicateNode(root);
    std::cout << "Anomali Tespiti: " << (hasDuplicate ? "True" : "False") << std::endl;

    delete root;
    delete leftChild;
    delete rightChild;
    delete duplicateNode;

    return 0;
}