#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int total,leg;
	cin>>total>>leg;
	int ga = (4*total - leg)/2;
	int cho = (total - ga);
	if(2*ga + 4* cho !=leg || cho <0 || ga<0){
		cout<<"invalid";
		return 0;
	}
	else{
		cout<<"chicken = "<<ga<<", dog = "<<cho;
	}
}
