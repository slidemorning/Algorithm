#include <iostream>
#include <algorithm>
#include <deque>

std::string stringSum(std::string& x, std::string& y){
    
    std::deque<char> deq;
    
    int xlen = x.length(); 
    int ylen = y.length();
    
    bool carry = false;

    if(xlen == ylen){
        for(int i=xlen-1; i>=0; i--){
            int numX = (int)x[i]-'0';
            int numY = (int)y[i]-'0';
            int sum = numX + numY;
            if(carry) sum += 1;
            carry = false;
            if(sum >= 10) carry = true;
            sum = sum % 10;
            deq.push_front((char)(sum+'0'));
        }
        if(carry){
            deq.push_front('1');
        }
    }else{
        int idx = xlen - 1;
        for(int i=ylen-1; i>=0; i--){
            int numX = (int)x[idx--]-'0';
            int numY = (int)y[i]-'0';
            int sum = numX + numY;
            if(carry) sum += 1;
            carry = false;
            if(sum >= 10) carry = true;
            sum = sum % 10;
            deq.push_front((char)(sum+'0'));
        }
        for(int i=idx; i>=0; i--){
            int numX = x[i]-'0';
            if(carry) numX += 1;
            carry = false;
            if(numX >= 10) carry = true;
            numX = numX % 10;
            deq.push_front((char)(numX+'0'));
        }
        if(carry) deq.push_front('1');
    }

    std::string ret;
    while(!deq.empty()){
        ret += deq.front();
        deq.pop_front();
    }
    return ret;
}

int main(void){
    std::string x, y;
    std::cin >> x >> y;
    if(x.length() < y.length()){
        std::cout << stringSum(y, x) << '\n';
    }
    else{
        std::cout << stringSum(x, y) << '\n';
    }
    return 0;    
}