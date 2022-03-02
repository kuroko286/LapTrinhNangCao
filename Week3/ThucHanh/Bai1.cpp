#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a,b;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		b.push_back(temp);
	}
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}
