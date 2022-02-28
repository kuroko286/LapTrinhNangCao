#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int high,low;
	cin>>low>>high;
	int shigh = sqrt(high);
	int slow = sqrt(low);
	for(int i=slow;i<=shigh;i++){
		int temp = i*i;
		//cout<<temp<<" ";
		if(temp>=low && temp<=high){
			cout<<temp<<" ";
		}
	}
}
