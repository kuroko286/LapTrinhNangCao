#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
	const int max = 1000;
	int n;
	cin>>n;
	vector<double> vectorA(n);
	double sum = 0;
	for(int i=0;i<n;i++){
		cin>>vectorA[i];
		sum+=vectorA[i];
	}
	double mean = sum/n;
	double temp = 0;
	for(int i=n-1;i>=0;i--){
		temp+=((vectorA[i]-mean)*(vectorA[i]-mean));
	}
	double res = temp/n;
	cout<<fixed<<setprecision(2)<<res;
}
