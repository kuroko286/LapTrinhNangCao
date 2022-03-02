#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		if(i==0 || a[i]!=a[i-1]){
			cout<<a[i]<<" ";
		}
	}
}
