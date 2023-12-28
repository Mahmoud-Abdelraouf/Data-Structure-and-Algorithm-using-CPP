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

    BinaryTree *getLeftNode() const {
        return left;
    }

    BinaryTree *getRightNode() const {
        return right;
    }

    ~BinaryTree() {
        // Recursively delete left and right nodes
        delete left;
        delete right;
    }
};


int main() {

    BinaryTree<int> *root = new BinaryTree<int> (5);
    BinaryTree<int> *left = new BinaryTree<int> (7);
    BinaryTree<int> *right = new BinaryTree<int> (10);

    root->setLeftNode(left);
    root->setRightNode(right);

    // Deleting the root node will trigger the destructor to recursively delete the entire tree
    delete root;

    return 0;
}