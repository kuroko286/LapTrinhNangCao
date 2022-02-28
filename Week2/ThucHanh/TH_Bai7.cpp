#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double oldSum;
	double sum = 1;
	int x;
	cin>>x;
	
	int i = 1;
	//int mu = x;
	//int giaithua = 1;
	double temp = 1;
	while(sum - oldSum > 0.001){
		oldSum = sum;
		temp = temp *x/i;
		//cout<<temp<<" "<<i<<endl;
		sum+=temp;
		//mu*=x;
		//giaithua*=(++i);
		i++;
	}
	cout<<fixed<<setprecision(4)<<sum;
}
