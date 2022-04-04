int** transpose(int** matrix, int nRows, int nCols){
    int** res = new int*[nCols];
    for(int i=0;i<nCols;i++){
        res[i] = new int[nRows];
    }
    for(int i=0;i<nCols;i++){
        for(int j=0;j<nRows;j++){
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}
