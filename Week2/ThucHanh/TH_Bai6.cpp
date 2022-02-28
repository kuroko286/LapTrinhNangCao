#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int temp;
	for(int i=-n;i<=n;i++){
		for(int j=-n;j<=n;j++){
			if(i+j<=n && i-j<=n && -i+j<=n && -i-j<=n){
				cout<<"* ";
			}
			else{
				cout<<". ";
			}
		}
		cout<<endl;
		
	}
}
