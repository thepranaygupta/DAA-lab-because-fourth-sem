#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display(int*x,int n)
{
     int i;
     printf("\n One solution is: \n");
     for(i=1;i<=n;i++)
     {
        printf("%d ",x[i]);
     }
}

int place(int k,int i,int*x)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
       if((x[j]==i)||(fabs(x[j]-i)==fabs(j-k)))
          return 0;
    }
    return 1;
}

void nQueens(int k,int n,int* x)
{
    int i;
    for(i=1;i<=n;i++)
    {
       if(place(k,i,x))
       {
          x[k]=i;//kth queen will be placed at ith column in the kth row
          if(k==n)//current permutation of n numbers gives a safe state
          {
             display(x,n);
          }
          else
          {
              nQueens(k+1,n,x);
          }
       }  
           
    } 
}


int main()
{
    int n,i,*final_position;
    printf("Enter the No. of queens: ");
    scanf("%d",&n);
    final_position=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++)
    {
       final_position[i]=0;
    }
    nQueens(1,n,final_position);
    getch();
    return 0;
}
