void reverse(float array[],int size){
	for(int i=0;i<size/2;i++){
		float temp = array[i];
		array[i] = array[size-1-i];
		array[size-1-i] = temp;
	}
};
void sort(float array[], int size, bool isAscending){
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]>array[j]){
				float temp = array[i];
				array[i] = array[j];
				array[j] = temp; 
			}
		}
	} 
	if(!isAscending){
		reverse(array,size);
	}
}
