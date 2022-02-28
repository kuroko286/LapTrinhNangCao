#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int initRandNum(int min = 1,int max = 100){
	return min + rand() % (max - min +1);
};

int getPlayerNum(){
	int guess;
	cout<<"Please enter your number: ";
	cin>>guess;
	cout<<guess<<endl;
	return guess;
};

void printAnswer(int rand,int guess){
	if(guess == rand){
		cout<<"Congratulate! You win!!!"<<endl;
	}
	else if(guess<rand){
		cout<<"Your number is too small"<<endl;
	}
	else{
		cout<<"Your number is too big"<<endl;
	}
};

int main(){
	srand(time(0));
	int randNum = initRandNum();
	int guess;
	do{
		guess = getPlayerNum();
		printAnswer(randNum,guess);
	}while(guess!=randNum);
	return 0;
} 
