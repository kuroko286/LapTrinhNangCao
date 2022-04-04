int** inputMatrix(int nRows, int nCols){
    int** arr = new int*[nRows];
    for(int i=0;i<nRows;i++){
        arr[i] = new int[nCols];
    }
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            cin>>arr[i][j];
        }
        
    }
    return arr;
}
void printMatrix(int** matrix, int nRows, int nCols){
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
