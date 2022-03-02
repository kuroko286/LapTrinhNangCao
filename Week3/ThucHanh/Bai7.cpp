#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
bool isChuCai(char c);
bool isChuSo(char c);
int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	int count_cc = 0;
	int count_cs = 0;
	int count_kt = 0;
	int i=0;
	
	while(i<l){
		if(isChuCai(s[i])){
			count_cc++;
		}
		else if(isChuSo(s[i])){
			count_cs++;
		}
		else{
			count_kt++;
		}
		i++;
	}
	cout<<count_cc<<" "<<count_cs<<" "<<count_kt;
}

bool isChuCai(char c){
	if(c>='a' && c<='z' || c>='A' && c<='Z'){
		return true;
	}
	return false;
}

bool isChuSo(char c){
	if(c>='0' && c<='9'){
		return true;
	}
	return false;
}
