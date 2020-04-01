#include <iostream>

#define LR

template<typename T>
class AvlTree;

template <typename T>
class Node{
    friend class AvlTree<T>;
private:
    T data;
    int height;
    Node* left;
    Node* right;
public:
    Node(){height=1; left=right=nullptr;}
    Node(T data){
        this->data = data;
        this->height = 1;
        left = right = nullptr;
    }
    ~Node(){}
};

template <typename T>
class AvlTree{
private:
    Node<T>* root;
public:
    AvlTree(){root = nullptr;}
    ~AvlTree(){delete root;}

    // Interface
    void insert(T data);
    //bool search(T data);
    //void remove(T data);
    void display();

    // Hidden
    T get_max(T x, T y);
    void set_height(Node<T>*& node);
    int get_height(Node<T>*& node);
    int get_difference(Node<T>*& node);
    void balance(Node<T>*& node);
    void rotate_ll(Node<T>*& node);
    void rotate_rr(Node<T>*& node);
    void rotate_lr(Node<T>*& node);
    void rotate_rl(Node<T>*& node);

    // Wrapper
    void wrap_insert(Node<T>*& node, T data);
    void wrap_display(Node<T>*& curr, int level);
};

// Interface
template <typename T>
void AvlTree<T>::insert(T data){
    wrap_insert(this->root, data);
}

template <typename T>
void AvlTree<T>::display(){
    wrap_display(this->root, 1);
}

// Hidden
template <typename T>
T AvlTree<T>::get_max(T x, T y){
    return x > y ? x : y;
}

template <typename T>
void AvlTree<T>::set_height(Node<T>*& node){
    node->height = get_max(get_height(node->left), get_height(node->right)) + 1;
}

template<typename T>
int AvlTree<T>::get_height(Node<T>*& node){
    if(node == nullptr) return 0;
    return node->height;
}

// Get balance factor
template<typename T>
int AvlTree<T>::get_difference(Node<T>*& node){
    if(node == nullptr) return 0;
    Node<T>* left = node->left;
    Node<T>* right = node->right;
    // Return balance factor
    return get_height(left)-get_height(right);
}

template <typename T>
void AvlTree<T>:: rotate_ll(Node<T>*& node){
    std::cout << "LL Rotation\n";
    Node<T>* left = node->left;
    node->left = left->right;
    left->right = node;
    set_height(node);
    node = left;
}

template <typename T>
void AvlTree<T>:: rotate_lr(Node<T>*& node){
    std::cout << "LR Rotation\n";
    rotate_rr(node->left);
    set_height(node->left);
    rotate_ll(node);
}

template <typename T>
void AvlTree<T>:: rotate_rr(Node<T>*& node){
    std::cout << "RR Rotation\n";
    Node<T>* right = node->right;
    node->right = right->left;
    right->left = node;
    set_height(node);
    node = right;
}

template <typename T>
void AvlTree<T>:: rotate_rl(Node<T>*& node){
    std::cout << "RL Rotation\n";
    rotate_ll(node->right);
    set_height(node->right);
    rotate_rr(node);
}

template <typename T>
void AvlTree<T>::balance(Node<T>*& node){
    int difference = get_difference(node);
    if(difference >= 2){
        if(get_difference(node->left) >= 1){
            rotate_ll(node);
        }else{
            rotate_lr(node);
        }
    }else if(difference <= -2){
        if(get_difference(node->right) <= -1){
            rotate_rr(node);
        }else{
            rotate_rl(node);
        }
    }
    set_height(node);
}

// Wrapper
template <typename T>
void AvlTree<T>::wrap_insert(Node<T>*& curr, T data){
    if(curr == nullptr){
        curr = new Node<T>(data);
        return;
    }else if(data < curr->data){
        wrap_insert(curr->left, data);
        balance(curr);
    }else if(data > curr->data){
        wrap_insert(curr->right, data);
        balance(curr);
    }else{
        std::cout << "Occur data redundancy ...\n";
    }
}

template <typename T>
void AvlTree<T>::wrap_display(Node<T>*& curr, int level){
    if(curr == nullptr) return;
    wrap_display(curr->right, level+1);
    std::cout << '\n';
    if(curr == this->root){
        std::cout << "Root -> ";
    }
    for(int i=0; i<level && curr != root; i++){
        std::cout << "          ";
    }
    std::cout << curr->data << "(" << get_height(curr) << ")\n";
    wrap_display(curr->left, level+1);
}

int main(void){
    AvlTree<int>* avl = new AvlTree<int>();

    
    #ifdef LL
    avl->insert(96);
    avl->insert(85);
    avl->insert(110);
    avl->insert(64);
    avl->insert(90);
    avl->display();
    std::cout << "\n\n\n";
    avl->insert(36);
    avl->display();
    #endif

    #ifdef LR
    avl->insert(44);
    avl->insert(30);
    avl->insert(76);
    avl->insert(16);
    avl->insert(39);
    avl->display();
    std::cout << "\n\n\n";
    avl->insert(33);
    avl->display();
    #endif

    #ifdef RR
    avl->insert(27);
    avl->insert(13);
    avl->insert(42);
    avl->insert(31);
    avl->insert(51);
    avl->display();
    std::cout << "\n\n\n";
    avl->insert(63);
    avl->display();
    #endif

    #ifdef RL
    avl->insert(27);
    avl->insert(13);
    avl->insert(42);
    avl->insert(33);
    avl->insert(51);
    avl->display();
    std::cout << "\n\n\n";
    avl->insert(37);
    avl->display();
    #endif 

    delete avl;
    return 0;
}
