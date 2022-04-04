void reverse(char *s) {
    int l = strlen(s);
    for(int i=0;i<l/2;i++){
        char t = s[i];
        s[i] = s[l-1-i];
        s[l-1-i] = t;
    }
    
}
