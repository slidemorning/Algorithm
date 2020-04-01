#include <iostream>

template <typename T>
class BinarySearchTree;

template <typename T>
class Node{
    friend class BinarySearchTree<T>;
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(){ left=right=nullptr; }
    Node(T data){ this->data=data; left=right=nullptr; }
};

template <typename T>
class BinarySearchTree{
private:
    Node<T>* root;
public:
    BinarySearchTree<T>() {root=nullptr;}
    ~BinarySearchTree<T>() {delete root;}

    // Interface
    void insert(T data);
    bool search(T data);
    void remove(T data); 
    void preorder();
    void inorder();
    void postorder();

    // Hidden
    Node<T>* find_min_node(Node<T>* curr);

    // Wrapper
    void wrap_insert(Node<T>*& curr, T data);
    bool wrap_search(Node<T>*& curr, T data);
    void wrap_remove(Node<T>*& curr, T data);
    void wrap_preorder(Node<T>*& curr);
    void wrap_inorder(Node<T>*& curr);
    void wrap_postorder(Node<T>*& curr);
};

// Interface

template <typename T>
void BinarySearchTree<T>::insert(T data){
    wrap_insert(this->root, data);
}

template <typename T>
bool BinarySearchTree<T>::search(T data){
    wrap_search(this->root, data);
}

template <typename T>
void BinarySearchTree<T>::remove(T data){
    wrap_remove(this->root, data);
}

template <typename T>
void BinarySearchTree<T>::preorder(){
    wrap_preorder(this->root);
    std::cout << '\n';
}

template <typename T>
void BinarySearchTree<T>::inorder(){
    wrap_inorder(this->root);
    std::cout << '\n';
}

template <typename T>
void BinarySearchTree<T>::postorder(){
    wrap_postorder(this->root);
    std::cout << '\n';
}

// Hidden
template <typename T>
Node<T>* BinarySearchTree<T>::find_min_node(Node<T>* curr){
    Node<T>* node = curr;
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

// Wrapper

template <typename T>
void BinarySearchTree<T>::wrap_insert(Node<T>*& curr, T data){
    if(curr == nullptr){
        curr = new Node<T>(data);
        return;
    }else if(data < curr->data){
        wrap_insert(curr->left, data);
    }else{
        wrap_insert(curr->right, data);
    }
}

template <typename T>
bool BinarySearchTree<T>::wrap_search(Node<T>*& curr, T data){
    if(curr == nullptr) return false;
    if(curr->data == data) return true;
    else if(data < curr->data) return wrap_search(curr->left, data);
    else return wrap_search(curr->right, data);
}

template <typename T>
void BinarySearchTree<T>::wrap_remove(Node<T>*& curr, T data){
    if(curr == nullptr) return;
    if(data < curr->data) wrap_remove(curr->left, data);
    else if(data > curr->data) wrap_remove(curr->right, data);
    else{
        if(curr->left != nullptr && curr->right != nullptr){
            Node<T>* node = find_min_node(curr->right);
            curr->data = node->data;
            wrap_remove(curr->right, node->data);
        }
        else if(curr->left == nullptr && curr->right != nullptr){
            curr->data = curr->right->data;
            delete curr->right;
            curr->right = nullptr;
        }
        else if(curr->left != nullptr && curr->right == nullptr){
            curr->data = curr->left->data;
            delete curr->left;
            curr->left = nullptr;
        }
        else{
            delete curr;
            curr = nullptr;
        }
    }
}

template <typename T>
void BinarySearchTree<T>::wrap_preorder(Node<T>*& curr){
    if(curr == nullptr) return;
    std::cout << curr->data << "  ";
    wrap_preorder(curr->left);
    wrap_preorder(curr->right);
}

template <typename T>
void BinarySearchTree<T>::wrap_inorder(Node<T>*& curr){
    if(curr == nullptr) return;
    wrap_inorder(curr->left);
    std::cout << curr->data << "  ";
    wrap_inorder(curr->right);
}

template <typename T>
void BinarySearchTree<T>::wrap_postorder(Node<T>*& curr){
    if(curr == nullptr) return;
    wrap_inorder(curr->left);
    wrap_inorder(curr->right);
    std::cout << curr->data << "  ";
}


int main(void){
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();
    bst->insert(5);
    bst->insert(7);
    bst->insert(1);
    bst->insert(9);
    bst->insert(3);
    bst->insert(0);
    bst->preorder();
    bst->remove(1);
    bst->preorder();
    bst->inorder();
    bst->postorder();
}
