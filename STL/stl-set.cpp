// https://modoocode.com/224
#include <iostream>
#include <set>

/*
    1. set vs. multiset
    Set (Do not allow duplication) vs Multi-Set(Allow duplication)

    2. balanced bst structure
    insert : log(N)
    remove : log(N)
    find   : log(N)

    3. set vs. map
    set : key 만 보관. 해당 key가 있는지 없는지 (True of False) 
    map : key, value를 보관 (map으로 set을 구현 가능 메모리)
    memory : map > set
*/

template <typename T>
void printSet(std::set<T>& s){
    std::cout << "[ ";
    for(typename std::set<T>::iterator itr = s.begin(); itr != s.end(); itr++){
        std::cout << *itr << " ";
    }
    std::cout << " ] " << std::endl;
}

int main(void){
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    // 크기 순서대로 정렬되어 출력
    std::cout << "print set ..." << std::endl;
    printSet(s);

    std::cout << "exist 20 ? :: ";
    auto itr = s.find(20);
    if(itr != s.end()){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    std::cout << "exist 25 ? :: ";
    itr = s.find(25);
    if(itr != s.end()){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}