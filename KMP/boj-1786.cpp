// https://www.acmicpc.net/problem/1786
#include <iostream>
#include <vector>

std::vector<int> make(std::string pattern){
    int psize = pattern.size();
    std::vector<int> ps(psize, 0);
    int j=0; // prefix index 
    for(int i=1; i<psize; i++){ // suffix index
        while(j > 0 && pattern[i] != pattern[j]){
            j = ps[j-1];
        }
        if(pattern[i] == pattern[j]){
            ps[i] = ++j;
        }    
    }
    return ps;
}

std::vector<int> kmp(std::string text, std::string pattern){
    std::vector<int> ps = make(pattern);
    std::vector<int> ret;
    int j = 0; // pattern index
    for(int i=0; i<text.size(); i++){
        while(j > 0 && text[i] != pattern[j]){
            j = ps[j-1];
        }
        if(text[i] == pattern[j]){
            if(j == pattern.size() - 1){
                ret.push_back(i-pattern.size()+1);
                j = ps[j]; // **caution
            }
            else{
                j++;
            }
        }
    }
    return ret;
}

int main(void){
    std::string text, pattern;
    std::getline(std::cin, text);
    std::getline(std::cin, pattern);
    std::vector<int> res = kmp(text, pattern);
    std::cout << res.size() << '\n';
    for(int i=0; i<res.size(); i++){
        std::cout << res[i]+1 << '\n';
    }
    return 0;
}