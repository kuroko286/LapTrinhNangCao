#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

string chooseWord();
string initWord(int l);
char getPlayerGuess();
bool isContains(vector<char> selected,char c);
string render(string word,vector<char> v);
void displayAnswer(string currWord,int badGuess,vector<char>selected);
void print(vector<char> selected);
void endLoseGame(string secretWord);
void endWinGame();
void drawHuman(int bad);
bool initGame(string word);
void drawSpace();

int main(){
	srand(time(0));
	string secretWord = chooseWord();
	int l = secretWord.length();
	string currWord = initWord(l);
	vector<char> selectedChar;
	int badGuess = 0;
	
	bool check = initGame(secretWord);
	if(!check){
		return 0;
	}
	do{
		char c = getPlayerGuess();
		
		if(secretWord.find(c)<l && !isContains(selectedChar,c)){
			cout<<"Congrat! Its true guess!"<<endl;
			selectedChar.push_back(c);
			currWord = render(secretWord,selectedChar);
			
		}
		else{
			cout<<"Oh no! It doesnt has this character!"<<endl;
			badGuess++;
			selectedChar.push_back(c);
		}
		displayAnswer(currWord,badGuess,selectedChar);
		drawSpace();
		drawHuman(badGuess);
		cout<<endl;
	}
	while(badGuess<7 && currWord!=secretWord);
	
	if(badGuess==7){
		endLoseGame(secretWord);
	}
	if(currWord==secretWord){
		endWinGame();
	}
	
	
	
}

string chooseWord(){
	string WORD_LIST[] = {
"angle", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
  "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",}; 
 
 	int len = sizeof(WORD_LIST) / sizeof(string);
 	int random = rand()%len;
 	return WORD_LIST[random-1];
}

string initWord(int l){
	string temp = "";
	for(int i=0;i<l;i++){
		temp+="_ ";
	}
	return temp;
}

char getPlayerGuess(){
	char c;
	cout<<"Enter your guess: ";
	cin>>c;
	cout<<endl;
	return c;
}

bool isContains(vector<char> selected,char c){
	if(find(selected.begin(),selected.end(),c)!=selected.end()){
		return true;
	}
	else{
		return false;
	}
}

string render(string word,vector<char> v){
	string temp = "";
	int l = word.length();
	for(int i=0;i<l;i++){
		char c = word[i];
		if(isContains(v,c)){
			string str = ""+c+' ';
			temp+=c;
			
		}
		else{
			temp+="_ ";
			
		}
	}
	return temp;
}

void displayAnswer(string currWord,int badGuess,vector<char> selected){
	cout<<"Your currWord is : "<<currWord<<endl;
	cout<<"Number of wrong guess: "<<badGuess<<"/7"<<endl;
	print(selected);
}

void print(vector<char> selected){
	cout<<"you have been selected these char: ";
	int s = selected.size();
	for(int i=0;i<s;i++){
		cout<<selected[i]<<' ';
	}
	cout<<endl;
}

void endLoseGame(string secretWord){
	cout<<"Nope bro! You losed this game!!"<<endl;
	cout<<"The secret word is "<<secretWord<<endl;
};

void endWinGame(){
	cout<<"Congratulation! You are the winner!!"<<endl;
};

void drawHuman(int bad){
	string bad7 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |            /|\\  \n"
				  "  |            / \\  \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad6 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |            /|\\  \n"
				  "  |            /   \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad5 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |            /|\\  \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad4 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |            /|  \n"
				  "  |                \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad3 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |             |  \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad2 = "  ______________    \n"
				  "  |             |   \n"
				  "  |             O   \n"
				  "  |                 \n"
				  "  |                \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad1 = "  ______________    \n"
				  "  |             |   \n"
				  "  |                \n"
				  "  |                \n"
				  "  |                \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
	string bad0 = "  ______________    \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "  |                 \n"
				  "__|__               ";
				  
	string arr[] = {bad0,bad1,bad2,bad3,bad4,bad5,bad6,bad7};
	cout<<arr[bad]<<endl;
}

bool initGame(string word){
	cout<<"This word has "<<word.length()<<" characters"<<endl;
	cout<<"Do you wanna to play this game ??? \n"
		  "Press 'y' to play or 'n' to quit game: ";
	char check;
	cin>>check;
	if(check=='y'){
		return true;
	}
	else{
		return false;
	}
}

void drawSpace(){
	for(int i=0;i<14;i++){
		cout<<endl;
	}
};

