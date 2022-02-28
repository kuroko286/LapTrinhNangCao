#include<iostream>
#include<iomanip> 
using namespace std;
int main(){
	float a,b;
	cin>>a;
	b = 1.8 * a + 32; 
	cout<<fixed<<setprecision(2)<<b;
	return 0;
} 
