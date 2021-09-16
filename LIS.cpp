#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
	int lis[n];
	lis[0]=1;
	for(int i=0;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				lis[i]=max(lis[i],lis[j]+1);
			}
		}
	}
	int res=lis[0];
	for(int i=0;i<n;i++)
	{
		res=max(res,lis[i]);
	}
	return res;
}
int main()
{
	int arr[]={2,4,2,7,9,2,14,33};
	cout<<lis(arr,8);

}