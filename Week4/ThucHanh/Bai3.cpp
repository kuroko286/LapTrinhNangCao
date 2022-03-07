void printArrow(int n, bool left){
	if(left){
		for(int i=n;i>1;i--){
			for(int j=i-1;j>=1;j--){
				cout<<" ";
			}
			for(int j=i;j>0;j--){
				cout<<"*";
			}
			cout<<endl;
		}
		cout<<"*";
		cout<<endl;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				cout<<" ";
			}
			for(int j=i;j>0;j--){
				cout<<"*";
			}
			if(i!=n){
				cout<<endl;
			}
		}
	}
	else{
		for(int i=n;i>1;i--){
			for(int j=0;j<n-i;j++){
				cout<<"  ";
			}
			for(int j=i;j>0;j--){
				cout<<"*";
			}
			cout<<endl;
		}
		for(int i=0;i<2*n-2;i++){
			cout<<" ";
		}
		cout<<"*"<<endl;
		
		for(int i=2;i<=n;i++){
			for(int j=0;j<n-i;j++){
				cout<<"  ";
			}
			for(int j=i;j>0;j--){
				cout<<"*";
			}
			if(i!=n){
				cout<<endl;
			}
		}
	}
}
