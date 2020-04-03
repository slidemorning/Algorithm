#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPi(std::string pattern){
    int m = pattern.size();
    int j = 0;
    std::vector<int> pi(m, 0);
    for(int i=1; i<m; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

std::vector<int> kmp(std::string text, std::string pattern){
    std::vector<int> ret;
    auto pi = getPi(pattern);
    int n = text.size();
    int m = pattern.size();
    int j = 0;
    for(int i=0; i<n; i++){
        while(j > 0 && pattern[j] != text[i]){
            j = pi[j-1];
        }
        if(text[i] == pattern[j]){
            if(j == m-1){
                ret.push_back(i-m+1);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ret;
}

int main(void){
    std::string text = "acabacdabac";
    std::string pattern = "abacdab";
    std::vector<int> res = kmp(text, pattern);
    for(int i=0; i<res.size(); i++){
        std::cout << "Matching at " << res[i] << "[index]\n";
    }
    return 0;
}