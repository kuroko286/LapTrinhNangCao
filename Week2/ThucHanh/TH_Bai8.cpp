#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int count = 0;
	do{
		count++;
		n/=10;
	}while(n!=0);
	cout<<count;
}
