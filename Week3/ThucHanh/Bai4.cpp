#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	double a[1002];
	double temp;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>temp;
	int index;
	for(index =0;index<n;index++){
		if(a[index]>=temp){
			break;
		}
	}
	for(int i=n;i>index;i--){
		a[i] = a[i-1];
	}
	a[index] = temp;
	for(int i=0;i<=n;i++){
		cout<<fixed<<setprecision(2)<<a[i]<<" ";
	}
}
