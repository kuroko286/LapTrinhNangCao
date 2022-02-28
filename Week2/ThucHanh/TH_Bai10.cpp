#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
	const int max = 1000;
	int n;
	cin>>n;
	vector<double> vectorA(n),vectorB(n);
	double res = 0;
	for(int i=0;i<n;i++){
		cin>>vectorA[i];
	}
	for(int i=0;i<n;i++){
		cin>>vectorB[i];
	}
	for(int i=n-1;i>=0;i--){
		res+=vectorA[i]*vectorB[i];
	}
	cout<<fixed<<setprecision(2)<<res;
}
