//Coded by G Sagar
#include<stdio.h>
void radix(int[],int);
void radix(int a[],int n)
{
	int max,digits=0,i,j,k,count[10],bucket[10][n],div=1,pos,steps;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
		while(max>0)
		{
			digits ++; max=max/10;
		}
		for(steps=1;steps<=digits;steps++)
		{
			for(i=0;i<10;i++)
			{
				count[i]=0;
			}
		
			for(i=0;i<n;i++)
			{
				pos=(a[i]/div)%10;
				bucket[pos][count[pos]++]=a[i];
			} k=0;
			for(i=0;i<10;i++)
			{
				for(j=0;j<count[i];j++)
				{
					a[k]=bucket[i][j];
					k++;
				}
			} div=div*10;
		}
}
int main()
{
	int arr[50],n,i;
	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d values:",n);
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);	
	}
	radix(arr,n);
	printf("sorted array: ");
	for(i=0;i<n;i++)
	{
	printf("%d ",arr[i]);	
	}printf("\n ");
	return 0;
}
