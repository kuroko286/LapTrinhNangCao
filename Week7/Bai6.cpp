bool checkTangDan(int* arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2){
    int lenRes = lenArr1 + lenArr2;
    int* res = new int[lenRes];
    int i= 0;
    int j=0;
    int k=0;
    if(checkTangDan(firstArr,lenArr1)){
        
        while(i<lenArr1 && j<lenArr2){
            if(firstArr[i]<secondArr[j]){
                res[k] = firstArr[i];
                i++;
            }
            else{
                res[k] = secondArr[j];
                j++;
            }    
            k++;
        }
        while(i<lenArr1){
            res[k] = firstArr[i];
            i++;k++;
        }
        while(j<lenArr2){
            res[k] = secondArr[j];
            j++;k++;
        }
    }
    else{
        while(i<lenArr1 && j<lenArr2){
            if(firstArr[i]>secondArr[j]){
                res[k] = firstArr[i];
                i++;
            }
            else{
                res[k] = secondArr[j];
                j++;
            }    
            k++;
        }
        while(i<lenArr1){
            res[k] = firstArr[i];
            i++;k++;
        }
        while(j<lenArr2){
            res[k] = secondArr[j];
            j++;k++;
        }
    }
    return res;
}

