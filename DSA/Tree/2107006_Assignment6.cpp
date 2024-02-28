
// 2107006 - Sarwad Hasan Siddiqui
// Assignment - 6: Binary Tree & Traversal Iterator Class Making


#include <bits/stdc++.h>

using namespace std;

template <class E>
class BinaryTree
{
private:
    E value;
    BinaryTree<E>* left;
    BinaryTree<E>* right;
    BinaryTree<E>* parent;

public:
    BinaryTree()
    {
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    BinaryTree(E val)
    {
        value=val;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    BinaryTree(E val, BinaryTree<E>* l, BinaryTree<E>* r)
    {
        value=val;
        left=l;
        right=r;
        parent=nullptr;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
    int height()
    {
        if (this == nullptr)
            return 0;

        int LH = left ? left->height() : 0;
        int RH = right ? right->height() : 0;

        return 1+max(LH,RH);
    }
    E getValue()
    {
        return value;
    }
    BinaryTree<E>* getLeft()
    {
        return left;
    }
    BinaryTree<E>* getRight()
    {
        return right;
    }
    BinaryTree<E>* getParent()
    {
        return parent;
    }

    void setLeft(BinaryTree<E>* newLeft)
    {
        left = newLeft;
        if (newLeft)
            newLeft->parent = this;
    }
    void setRight(BinaryTree<E>* newRight)
    {
        right = newRight;
        if (newRight)
            newRight->parent = this;
    }
    void setParent(BinaryTree<E>* newParent)
    {
        parent = newParent;
    }
    void setValue(E newValue)
    {
        value = newValue;
    }

    bool isBalanced()
    {
        if (this == nullptr) return true;
        int leftHeight = left->height();
        int rightHeight = right->height();
        return abs(leftHeight - rightHeight) <= 1 && left->isBalanced() && right->isBalanced();
    }

    bool isComplete()
    {
        if (this == nullptr) return true;
        queue<BinaryTree<E>*> q;
        q.push(this);
        bool nof = false;

        while (!q.empty())
        {
            BinaryTree<E>* cur = q.front();
            q.pop();

            if (cur == nullptr)
            {
                nof = true;
            }
            else
            {
                if (nof) return false;

                q.push(cur->getLeft());
                q.push(cur->getRight());
            }
        }
        return true;
    }

    bool isFull()
    {
        if (this == nullptr) return true;
        if (left == nullptr && right == nullptr) return true;
        if (left != nullptr && right != nullptr) return left->isFull() && right->isFull();
        return false;
    }

    bool isBinarySearchTree()
    {
        return isBSTUtil(this, nullptr, nullptr);
    }


    class Iterator
    {
    private:
        queue<E> elements;

        void postOrderTraversal(BinaryTree<E>* root)
        {
            if (root)
            {
                postOrderTraversal(root->left);
                postOrderTraversal(root->right);
                elements.push(root->value);
            }
        }

        void preOrderTraversal(BinaryTree<E>* root)
        {
            if (root)
            {
                elements.push(root->value);
                preOrderTraversal(root->left);
                preOrderTraversal(root->right);
            }
        }
        stack<BinaryTree<E>*> s;
        BinaryTree<E>* cur;
    public:
        Iterator(BinaryTree<E>* root, string s)
        {
            if (s == "postorder")
                postOrderTraversal(root);
            else if (s == "preorder")
                preOrderTraversal(root);
        }
        Iterator(BinaryTree<E>* root)
        {
            cur = root;
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->getLeft();
            }
        }

        bool hasNext()
        {
            return !s.empty();
        }

        bool quenext(){
            return !elements.empty();
        }

        E quenextele(){
            E cur = elements.front();
            elements.pop();
            return cur;
        }

        E next()
        {
            cur = s.top();
            s.pop();
            BinaryTree<E>* temp = cur->getRight();
            while (temp != nullptr)
            {   
                s.push(temp);
                temp = temp->getLeft();
            }
            return cur->getValue();
        }

        
    };
    bool isBSTUtil(BinaryTree<E>* root, BinaryTree<E>* min, BinaryTree<E>* max)
    {
        if (root == nullptr)
            return true;

        if ((min && root->value <= min->value) || (max && root->value >= max->value))
            return false;

        return isBSTUtil(root->left, min, root) && isBSTUtil(root->right, root, max);
    }
    Iterator inorderBegin()
    {
        return Iterator(this);
    }

    Iterator inorderEnd()
    {
        return Iterator(nullptr);
    }
    Iterator postorderIterator()
    {
        return Iterator(this, "postorder");
    }

    Iterator preorderIterator()
    {
        return Iterator(this, "preorder");
    }

};

template<class E>
void extractInorder(BinaryTree<E>* root, vector<E>& inorder)
{
    if (root == nullptr) return;
    extractInorder(root->getLeft(), inorder);
    inorder.push_back(root->getValue());
    extractInorder(root->getRight(), inorder);
}

template<class E>
BinaryTree<E>* buildBalancedBST(vector<E>& inorder, int start, int end)
{
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    BinaryTree<E>* newNode = new BinaryTree<E>(inorder[mid]);
    newNode->setLeft(buildBalancedBST(inorder, start, mid - 1));
    newNode->setRight(buildBalancedBST(inorder, mid + 1, end));
    return newNode;
}

template<class E>
BinaryTree<E>* balance_tree(BinaryTree<E>* root)
{
    vector<E> inorder;
    extractInorder(root,inorder);
    return buildBalancedBST(inorder, 0, inorder.size() - 1);
}

int main()
{
    BinaryTree<int>* root = new BinaryTree<int>(20);
    root->setLeft(new BinaryTree<int>(10));
    root->setRight(new BinaryTree<int>(30));
    root->getLeft()->setLeft(new BinaryTree<int>(6));
    root->getLeft()->setRight(new BinaryTree<int>(14));
    root->getRight()->setRight(new BinaryTree<int>(55));
    root->getRight()->setLeft(new BinaryTree<int>(25));

    cout << "Height: " << root->height() << endl;
    if(root->isBalanced())
        cout << "Tree is balanced." << endl;
    else cout << "Tree is not balanced." << endl;
    if(root->isComplete())
        cout << "Tree is complete." << endl;
    else  cout << "Tree is not complete." << endl;
    if(root->isFull())
        cout << "Tree is full." << endl;
    else cout << "Tree is not full." << endl;
    if(root->isBinarySearchTree())
        cout << "It's a BST." << endl;
    else cout << "It's not a BST." << endl;

    cout << "Inorder traversal: ";
    BinaryTree<int>::Iterator it = root->inorderBegin();
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;

    cout<< "Preorder traversal: ";
    BinaryTree<int>::Iterator it2 = root->preorderIterator();
    while (it2.quenext())
    {
        cout << it2.quenextele() << " ";
    }
    cout<<endl;

    cout<< "Postorder traversal: ";
    BinaryTree<int>::Iterator it3 = root->postorderIterator();
    while (it3.quenext())
    {
        cout << it3.quenextele() << " ";
    }
    cout<<endl;

    BinaryTree<int>* balancedRoot = balance_tree(root);
    cout << "Balanced tree inorder traversal: ";
    BinaryTree<int>::Iterator balancedIt = balancedRoot->inorderBegin();
    while (balancedIt.hasNext())
    {
        cout << balancedIt.next() << " ";
    }
    cout << endl;

    delete root;
    delete balancedRoot;

    return 0;
}

