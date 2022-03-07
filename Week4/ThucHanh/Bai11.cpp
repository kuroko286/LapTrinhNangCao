
bool isNguyenAm(char c){
	if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o'){
		return true;
	}
	return false;
}

string pigLatin(string word){
	char c = word[0];
	int l = word.length();
	string res = "";
	if(isNguyenAm(c)){
		res = word + "way";
	}
	else{
		
		for(int i=1;i<l;i++){
			res+=word[i];
		}
		res+=word[0];
		res+="ay";
	}
	return res;
}
