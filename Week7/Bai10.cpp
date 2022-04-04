void rFilter(char *s) {
    int l = strlen(s);
    int i = l-1;
    while(!(s[i]>='a'&&s[i]<='z' || s[i]>='A' && s[i]<='Z') ){
        s[i] = '_';
        i--;
    }
    
}
