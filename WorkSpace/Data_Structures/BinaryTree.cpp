#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
class BinaryTree {
private:
    T data;
    BinaryTree *left, *right;

public:
    BinaryTree(T newData) : data(newData), left(nullptr), right(nullptr) {}

    void setData(T newData) {
        data = newData;
    }

    void setLeftNode(BinaryTree *newLeft) {
        if (newLeft == nullptr || newLeft == right) {
            return;
        }
        left = newLeft;
    }

    void setRightNode(BinaryTree *newRight) {
        if (newRight == nullptr || newRight == left) {
            return;
        }
        right = newRight;
    }

    T getData(void) const{
        return data;
    }

    BinaryTree *getLeftNode(void) const {
        return left;
    }

    BinaryTree *getRightNode(void) const {
        return right;
    }

    void printTree(const BinaryTree *root) const {
        if(root == nullptr) {
            return;
        }

        cout << root->data << ": ";
        if(root->left != nullptr) {
            cout << "L: " << root->left->data << ", ";
        } 

        if(root->right != nullptr) {
            cout << "R: " << root->right->data;
        }

        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }

    ~BinaryTree() {
        // Recursively delete left and right nodes
        delete left;
        delete right;
    }
};


template <typename T>
BinaryTree<T>* createBinaryTree() {
    T data;
    std::cout << "Enter data: ";
    std::cin >> data;

    if (data == -1) {
        return nullptr;
    }

    BinaryTree<T>* newNode = new BinaryTree<T>(data);

    std::cout << "Enter left child of " << data << ":\n";
    newNode->setLeftNode(createBinaryTree<T>());

    std::cout << "Enter right child of " << data << ":\n";
    newNode->setRightNode(createBinaryTree<T>());

    return newNode;
}

template <typename T>
BinaryTree<T>* createBinaryTreeLevelWise() {
    std::queue<BinaryTree<T>*> nodeQueue;
    T data;
    std::cout << "Enter root data: ";
    std::cin >> data;

    if (data == -1) {
        return nullptr;
    }

    BinaryTree<T>* root = new BinaryTree<T>(data);
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        BinaryTree<T>* currentNode = nodeQueue.front();
        nodeQueue.pop();

        T leftData, rightData;
        std::cout << "Enter left child of " << currentNode->getData() << ": ";
        std::cin >> leftData;

        if (leftData != -1) {
            currentNode->setLeftNode(new BinaryTree<T>(leftData));
            nodeQueue.push(currentNode->getLeftNode());
        }

        std::cout << "Enter right child of " << currentNode->getData() << ": ";
        std::cin >> rightData;

        if (rightData != -1) {
            currentNode->setRightNode(new BinaryTree<T>(rightData));
            nodeQueue.push(currentNode->getRightNode());
        }
    }

    return root;
}

template <typename T>
vector<vector<T>> levelOrder(const BinaryTree<T>* root) {
    vector<vector<T>> result;
    if (root == nullptr) {
        return result;
    }

    queue<const BinaryTree<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Size of nodes at current level
        vector<T> currentLevel;

        // Process all nodes in the current level
        while (levelSize > 0) {
            const BinaryTree<T>* node = q.front();
            q.pop();
            currentLevel.push_back(node->getData());

            if (node->getLeftNode()) {
                q.push(node->getLeftNode());
            }
            if (node->getRightNode()) {
                q.push(node->getRightNode());
            }

            levelSize--;
        }

        result.push_back(currentLevel);
    }

    return result;
}

int main() {
/**  
 *   BinaryTree<int> *root = new BinaryTree<int> (5);
 *   BinaryTree<int> *left = new BinaryTree<int> (7);
 *   BinaryTree<int> *right = new BinaryTree<int> (10);
 *
 *   root->setLeftNode(left);
 *   root->setRightNode(right);
 */

/**
 * BinaryTree<int> *root = createBinaryTree<int>();
 */

/**
 * BinaryTree<int> *root = createBinaryTreeLevelWise<int>();
 * root->printTree(root);
*/
    BinaryTree<int> *root = createBinaryTreeLevelWise<int>();

    // Performing level-order traversal
    vector<vector<int>> traversalResult = levelOrder(root);

    // Displaying the traversal result
    cout << "Level-order traversal result:" << endl;
    for (const auto& level : traversalResult) {
        for (const auto& node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    // Deleting the root node will trigger the destructor to recursively delete the entire tree
    delete root;

    return 0;
}