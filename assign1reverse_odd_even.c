#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("n:");   
    scanf("%d", &n);
    
    if(n==0){
    printf("%d", n);
    return 0;
    }	
    
    int i=(int)((log((double)n))/log(2));
    printf("%d", i);
    i -=1;
    long int n0=0; //Fk=n0  Fk+1=n1 Fk+2=n2 F2k=n3 F2k+1=n4 F2k+2=n5
    long int n1=1;
    long int n2,n3,n4,n5;
 //   long int F0=0;

    for(i;i>=0;i--)
    {
       // n=2*n1+b[i];
        n3=n0*(2*n1-n0);
        n4=n1*n1+n0*n0;
        n0=n3;
        n1=n4;
        if(((n>>(i))%2)!=0){
            //n5=n4+n3;
            n0=n4;
            n1=n4+n3;//n1=n5;
        }
        printf("%ld", n0);
        printf("\n");
    }
     return 0;
}
