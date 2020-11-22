#include "lib/sparce.h"
#include "lib/array.h"




int main(){
    int **matrix;
    int m,n,i,j;

    printf("the number of rows : ");
    scanf("%d",&m);
    printf("the number of coloums : ");
    scanf("%d",&n);

    matrix=make_imatrix(m,n);
    for(i=0; i<m;i++){
        for(j=0;j<n;j++){
            printf("Matrix[%d][%d] : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    sparce_pack(matrix,m,n);
    
    return EXIT_SUCCESS;
}