#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	if(a+b<=c || b+c<=a || c+a<=b){
		cout<<"invalid";
	}
	else{
		float p = (float)((a+b+c)/2);
		float temp = p * (p-a) * (p-b) * (p-c);
		float dientich = sqrt(temp);
		cout<<fixed<<setprecision(2)<<dientich;
	}
	return 0;
} 
