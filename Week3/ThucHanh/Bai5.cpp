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
	int left=0;
	int right = n-1;
	while(left<right){
		if(a[left]!=a[right]){
			cout<<"Asymmetric array.";
			return 0;
		}
		left++;right--;
	}
	cout<<"Symmetric array.";
}
