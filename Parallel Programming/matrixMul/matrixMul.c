#include<stdio.h>    
#include<stdlib.h> 
#include<omp.h>
#include<string.h>
int main(){
    // Create three matrix
    int a[400][400],b[400][400],mul[400][400],r,c,i,j,k;
    // Init final matrix with all zeros
    // memset(mul, 0, sizeof mul);
    // Randomizing
    r = 100;
    c = 100;
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            a[i][j] = rand() % 100; 
        }    
    }

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            b[i][j] = rand() % 100;    
        }    
    }    
          
    // For collapse(2) as two nested for loops are present
    #pragma omp for collapse(2)
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {   
            mul[i][j] = 0;
            for(k=0;k<c;k++)    
            {    
                mul[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }

    //for printing result    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            printf("%d\t",mul[i][j]);    
        }    
        printf("\n");    
    }

    return 0;  
} 