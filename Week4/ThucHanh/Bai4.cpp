long long int factorial(int n){
	long long int res = 1;
	for(int i=1;i<=n;i++){
		res*=i;
	}
	return res;
}
