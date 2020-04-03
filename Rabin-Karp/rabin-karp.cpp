#include <iostream>

void check(std::string text, std::string pattern, int start){
    bool find = true;
    int pattern_size = pattern.size();
    for(int i=0; i<pattern_size; i++){
        if(text[start+i] != pattern[i]){
            find = false;
            break;
        }
    }
    if(find){
        std::cout << "Matching at " << start << "[index]\n";
    }
}

void rabin_karp(std::string text, std::string pattern){
    int text_size = text.size();
    int pattern_size = pattern.size();
    int text_hash = 0, pattern_hash = 0, power = 1;

    for(int i=0; i<=text_size-pattern_size; i++){
        if(i == 0){
            for(int j=0; j<pattern_size; j++){
                text_hash = text_hash + (int)text[pattern_size-1-j]*power;
                pattern_hash = pattern_hash + (int)pattern[pattern_size-1-j]*power;
                if(j < pattern_size - 1) power = power * 2;
            }
        }
        else{
            text_hash = 2 * (text_hash - (int)text[i-1]*power) + text[pattern_size-1+i];
        }
        if(text_hash == pattern_hash){
            check(text, pattern, i);
        }
    }
}

int main(void){
    std::string text = "acabacdabac";
    std::string pattern = "abacdab";
    rabin_karp(text, pattern);
}

