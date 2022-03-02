#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool isZues(string s,int i);

int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	int i;
	for(i=0;i<=l-4;i++){
		if(isZues(s,i)){
			s[i+1]='e';
			s[i+2]='u';
			i+=4;
		}
	}
	cout<<s;
}

bool isZues(string s,int i){
	string temp = "";
	for(int j=0;j<4;j++){
		temp+=s[i+j];
	}
	return temp=="Zues";
};
