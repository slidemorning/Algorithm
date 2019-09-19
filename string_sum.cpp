#include <iostream>
#include <stack>
using namespace std;

string a[100001];

stack<char> string_sum(string str1, string str2){
	
	int len1 = str1.length();
	int len2 = str2.length();
	bool over = false;
	stack<char> s;
	
	if(len1 > len2){
		int diff = len1-len2;
		for(int i=0; i<diff; i++){
			str2 = '0' + str2;
		}
	}else if(len1 < len2){
		int diff = len2-len1;
		for(int i=0; i<diff; i++){
			str1 = '0' + str1;
		}
	}
	
	for(int i=len1-1; i>=0; i--){
		if(over){
			if(str1[i]-'0' + str2[i]-'0' + 1 >=  10){
				over = true;
				s.push((char)(str1[i]-'0' + str2[i]-'0' +1 -10 + '0'));
			}else{
				over = false;
				s.push((char)(str1[i]-'0' + str2[i]-'0' +1 +'0'));
			}
		}else{
			if(str1[i]-'0' + str2[i]-'0' >=  10){
				over = true;
				s.push((char)(str1[i]-'0' + str2[i]-'0' -10 + '0'));
			}else{
				over = false;
				s.push((char)(str1[i]-'0' + str2[i]-'0' +'0'));
			}
		}
	}
	
	return s;
}

int main(void){
	
	int n;
	cin >> n;
	
	a[0] = to_string(0);
	a[1] = to_string(1);
	for(int i=2; i<=n; i++){
		stack<char> s = string_sum(a[i-1], a[i-2]);
		while(!s.empty()){
			a[i] = a[i] + s.top();
			s.pop();
		}
	}
	cout << a[n] << endl;
}

// overflow at 93 idx
