#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	int i=0;
	while(i<l && s[i]==' '){
		cout<<s[i];
		i++;
	}
	while(i<l){
		if(i==0){
			cout<<s[i];
		}
		else if(s[i]==' ' && s[i-1]==' '){
			
		}
		else{
			cout<<s[i];
		}
		i++;
	}
}


