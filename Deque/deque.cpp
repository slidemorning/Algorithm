// deque (double linked list)
// for PS (https://www.acmicpc.net/problem/10866)

#include <iostream>

class Node{
    friend class Deque;
private:
    int data;
    Node *next;
    Node *prev;
public:
    Node(){next=nullptr;}
};

class Deque{
private:
    int cnt;
    Node* head;
    Node* tail;
public:
    Deque(){
        cnt = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int back();
    int front();
    int size();
    bool empty();
};

int Deque::size(){
    return this->cnt;
}

bool Deque::empty(){
    return cnt==0;
}

int Deque::front(){
    if(this->empty()) return -1;
    return head->next->data;
}

int Deque::back(){
    if(this->empty()) return -1;
    return tail->prev->data;
}

void Deque::push_front(int x){
    Node *node = new Node();
    node->data = x;
    
    Node *next = head->next;
    node->prev = head;
    node->next = next;
    next->prev = node;
    head->next = node;

    cnt += 1;
}

void Deque::push_back(int x){
    Node *node = new Node();
    node->data = x;

    Node *prev = tail->prev;
    node->next = tail;
    node->prev = prev;
    prev->next = node;
    tail->prev = node;

    cnt += 1;
}

int Deque::pop_front(){
    if(this->empty()) return -1;

    Node *remove = head->next;
    Node *next = remove->next;
    head->next = next;
    next->prev = head;

    int ret = remove->data;
    delete remove;
    cnt -= 1;
    return ret;
}

int Deque::pop_back(){
    if(this->empty()) return -1;

    Node *remove = tail->prev;
    Node *prev = remove->prev;
    tail->prev = prev;
    prev->next = tail;

    int ret = remove->data;
    delete remove;
    cnt -= 1;
    return ret;
}



int n;

int main(void){
    Deque *deque = new Deque();
    std::cin >> n;
    while(n--){
        std::string cmd;
        std::cin >> cmd;
        if(cmd == "push_front"){
            int x; std::cin >> x;
            deque->push_front(x);
        }else if(cmd == "push_back"){
            int x; std::cin >> x;
            deque->push_back(x);
        }else if(cmd == "pop_front"){
            std::cout << deque->pop_front() << '\n';
        }else if(cmd == "pop_back"){
            std::cout << deque->pop_back() << '\n';
        }else if(cmd == "size"){
            std::cout << deque->size() << '\n';
        }else if(cmd == "empty"){
            std::cout << (int)deque->empty() << '\n';
        }else if(cmd == "front"){
            std::cout << deque->front() << '\n';
        }else if(cmd == "back"){
            std::cout << deque->back() << '\n';
        }else{
            return 0;
        }
    }
    delete deque;
    return 0;
}
