#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	int count = 0;
	int i=0;
	while(s[i]==' '){
		i++;
	}
	while(i<l){
		if(i==0){
			count++;
			i++;
		}
		else{
			if(s[i]!=' ' && s[i-1]==' '){
				count++;
			}
			i++;
		}
	}
	cout<<count;
}
