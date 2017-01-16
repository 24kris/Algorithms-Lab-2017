#include <stdio.h>

void matrixMultiply(int matrix1[2][2], int matrix2[2][2]);

int main()
{
    int n,j;
    int P[2][2];
    int T[2][2];
    
    P[0][0]=1;  P[0][1]=0;  P[1][0]=0;  P[1][1]=1;
    
    T[0][0]=1;  T[0][1]=1;  T[1][0]=1;  T[1][1]=0;
    printf("n:");   
    scanf("%d", &n);
    
    n= n-1;
    
    if(n+1==0||n+1==1){
    printf("%d", n+1);
    }
	
    while(n>0)
    {
        if(n%2==0)
        {
            matrixMultiply(T,T);
        }
        
        if(n%2==1)
        {
            matrixMultiply(P,T);
            matrixMultiply(T,T);
        }
        
        n=n>>1;
	j=P[0][0];
   	 printf("%d", j);
	 printf("\n");
    }
    
    //n=P[0][0];
    //printf("%d", n);
}

void matrixMultiply(int matrix1[2][2], int matrix2[2][2])
{
    int i,j, k;
    int matrix[2][2];
    for(i = 0; i < 2; ++i)
	{
		for(j = 0; j < 2; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	
	for(i = 0; i < 2; ++i)
	{
		for(j = 0; j < 2; ++j)
		{
			for(k=0; k<2; ++k)
			{
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
    for(i = 0; i < 2; ++i)
	{
		for(j = 0; j < 2; ++j)
		{
			matrix1[i][j] = matrix[i][j];
		}
	}
}
