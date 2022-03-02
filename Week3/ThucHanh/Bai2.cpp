#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<double> a;
	double temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]<a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}		
	}
	for(int i=0;i<n;i++){
		cout<<fixed<<setprecision(2)<<a[i]<<" ";
	}
}
