// Reference : https://modoocode.com/224
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void printMap(std::map<K , V>& m){
    for(auto itr = m.begin(); itr != m.end(); itr++){
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

template <typename K, typename V>
void searchAndPrint(std::map<K, V>& m, K key){
    auto itr = m.find(key);
    if(itr != m.end()){
        std::cout << key << " --> " << itr->second << std::endl;
    }else{
        std::cout << "Not exist " << key << std::endl;
    }
}

int main(void){
    std::map<std::string, double> student_score;

    student_score.insert(std::make_pair("park", 4.01));
    student_score.insert(std::make_pair("lee", 3.56));
    student_score.insert(std::make_pair("lim", 3.88));
    student_score.insert(std::make_pair("jeong", 2.76));
    student_score.insert(std::make_pair("kim", 3.51));

    student_score["choi"] = 4.22;
    student_score["jang"] = 3.22;
    /*
        해당 key 가 이미 존재하고 있을때
        [] operator : {map}[{key}] = {value}; -> update
        insert()    : {map}.insert({key, value}) -> ignore (Do not allow duplication...)
    */

    printMap(student_score);

    std::cout << "=======================" << std::endl;

    std::cout << "Score of park :: " << student_score["park"] << std::endl;
    std::cout << "Score of slidemorning :: " << student_score["slidemorning"] << std::endl;
    /*
        [] operator : 없는 key에 대해 참조할때, key가 없다면 default constructor 를 호출하여
        원소를 추가함. 
        -> find() 함수를 이용하여 key가 존재하는지 먼저 확인하는것이 안전
    */

   std::cout << "=======================" << std::endl;

   searchAndPrint(student_score, std::string("lim"));
   searchAndPrint(student_score, std::string("colin"));
}

    