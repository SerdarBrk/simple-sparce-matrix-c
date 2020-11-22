#ifndef H_SPARSE_H
#define H_SPARSE_H



void *printSparceMatrix(int **smatrix,int m ,int n){
    int i,j,amount=0; 
    printf("The Sparse Matrix :\n");

    for(i = 0; i< m;i++){
       for(j=0;j<n;j++){
           printf("\t%d",smatrix[i][j]);
           if(smatrix[i][j] !=0){
               amount++;
           }
       }
       printf("\n");
    }
    printf("Matrix is %dx%d, nz= %d\n",m,n,amount);
}

void *printReconstructedMatrix(int **matrix,int m ,int n){
    int i,j;
    zeroMatrix(matrix,m,n);
    printf("The difference of the original and reconstructed matrices:\n");

    for(i = 0; i< m;i++){
       for(j=0;j<n;j++){
           printf("\t%d",matrix[i][j]);
       }
       printf("\n");
    }
    
}

void *printVectors(int *vector,int size){
    int i; 
    for(i = 0;i<size;i++){
        printf("\t%d",vector[i]);
    }
        
    printf("\n");
}

void zeroMatrix(int **matrix,int m,int n){
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = 0;
}





void sparce_pack(int **matrix,int m,int n){
    int aiSize=0,axSize=0,apSize=1;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[j][i] != 0){
                aiSize++;
                axSize++;
            }
        }
    }

    int ai[aiSize],ax[axSize];
    aiSize=0;
    axSize=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[j][i] != 0){
               ai[aiSize]=j;
               ax[axSize]=matrix[j][i];
               axSize++;
               aiSize++;
            }
        }
    }

    for(i=0;i<aiSize-1;i++){
        if(ai[i]> ai[i+1]){
            apSize++;
        }
    }

    int ap[apSize+1];
    ap[0]=0;
    apSize=1;

    for(i=0;i<aiSize-1;i++){
        if(ai[i]>ai[i+1]){
            ap[apSize]=i+1;
            apSize++;
        }
    }
    apSize++;

    printf("%d\n",aiSize);
    ap[apSize]=i;
    
    printf("%d \n",ap[apSize]);

    
    printSparceMatrix(matrix,m,n);
    printf("Ap =");
    printVectors(&ap,apSize); 
    printf("Ai =");
    printVectors(&ai,aiSize); 
    printf("Ax =");
    printVectors(&ax,axSize); 

    printReconstructedMatrix(matrix,m,n);

    
}
#endif