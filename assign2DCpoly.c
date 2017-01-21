#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793238462643383

void honer(int n, complex A[], complex H[], int h[]);
void fft(int n, complex A[], complex F[], int f[]);

int main()
{   time_t t;
    int i,n=1,d;
    int f[1],h[1];
    f[0]=1;
    h[0]=1;
   
    printf("d:");
    scanf("%d", &d);
    
    for(d;d>0;d=d-1){
        n=n*3;
    }
   
    complex A[n],F[n], H[n];
    
    srand((unsigned) time(&t));
    for(i=0;i<n;i++){
        A[i]=(20.0*rand()/RAND_MAX)-10;
    }
    fft(n, A, F, f);
    honer(n, A, H, h);
    /*for(i=0;i<n;i++){
       printf("%lf + %lfi\n",creal(A[i]),cimag(A[i]));
        printf("\n");
        printf("\n");
       
}*/	
    for(i=0;i<n;i++){
       printf("F[%d] = %lf + %lfi\n", i, creal(F[i]), cimag(F[i]));
        printf("H[%d] = %lf + %lfi\n", i, creal(H[i]), cimag(H[i]));
        printf("\n");
       
}
printf("fft count :%d   honer count :%d\n", f[0], h[0]);
}

void fft(int n, complex A[], complex F[], int f[]){
    if(n==1){
        F[0]=A[0];
        return ;
    }
    complex A0[n/3], A1[n/3], A2[n/3], A0F[n/3], A1F[n/3], A2F[n/3];
    int j=0,k=0, shift=n/3; complex omega, omegak, omega1;
    for(j;j<n/3;j++){f[0]+=1;
        A0[j]=A[k];
        k+=1;
        A1[j]=A[k];
        k+=1;
        A2[j]=A[k];
        k+=1;
    }
    complex omega2;
    fft(n/3, A0, A0F, f);
    fft(n/3, A1, A1F, f);
    fft(n/3, A2, A2F, f);
    omegak=1;
    omega=cos(2.0*(float)PI/(float)n)+sin(2.0*(float)PI/(float)n)*I;
    omega1=cos(2.0*(float)PI/(float)3)+sin(2.0*(float)PI/(float)3)*I;
    omega2=cos(4.0*(float)PI/(float)3)+sin(4.0*(float)PI/(float)3)*I;
    //printf("%lf + %lfi %d\n",creal(omegak),cimag(omegak), n);
    for(k=0;k<n/3;k++)
    {F[k]=A0F[k]+omegak*A1F[k]+omegak*omegak*A2F[k];
    //omegak=omegak*omega1;
    F[k+shift]=A0F[k]+omegak*omega1*A1F[k]+omegak*omega1*omegak*omega1*A2F[k];
    //omegak=omegak*omega1;
    F[k+shift+shift]=A0F[k]+omegak*omega2*A1F[k]+omegak*omegak*omega2*omega2*A2F[k];
    omegak=omegak*omega;
	f[0]+=1;
    }
}

void honer(int n, complex A[], complex H[], int h[]){
    int i,j;
    
    complex omega, omegak;
    omegak=1;
    omega=cos(2.0*(float)PI/(float)n)+sin(2.0*(float)PI/(float)n)*I;
    for(i=0;i<n;i++){h[0]+=1;
            H[i]=0;
        for(j=n-1;j>=0;j--)
        {h[0]+=1;
            H[i]=H[i]*omegak+A[j];
        }
        omegak=omegak*omega;
        //printf("%lf + %lfi %d\n",creal(omegak),cimag(omegak), n);
    }
    
}


