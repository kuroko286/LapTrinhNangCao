#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
bool isKtdb(char c);
bool hasKtdb(string s,int l);
bool isStartNum(string s);
int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	
	if(hasKtdb(s,l) || isStartNum(s) || l<6||l>15){
		//cout<<hasKtdb(s,l) <<" "<<isStartNum(s);
		cout<<"Invalid username.";
		return 0;
	}
	else{
		cout<<"Valid username.";
		return 0;
	}
}

bool isKtdb(char c){
	if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
		return false;
	}
	return true;
}

bool hasKtdb(string s,int l){
	for(int i=0;i<l;i++){
		if(isKtdb(s[i])){
			return true;
		}
	}
	return false;
}

bool isStartNum(string s){
	char c = s[0];
	return c>='0' && c<='9';
}


