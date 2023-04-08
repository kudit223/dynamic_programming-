//target sum
//time complexity:O(n^2)
//space complexity:O(n+n^2)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>v,int n,int target)
{
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=v[i];
	if((sum+target)%2!=0)
	return 0;
	else
	{
		sum=(sum+target)/2;
		int dp[n+1][sum+1];
		for(int i=0;i<n+1;i++)
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			dp[i][j]=0;
			if(j==0)
			dp[i][j]=1;
		}
		for(int i=1;i<n+1;i++)
		for(int j=1;j<sum+1;j++)
		{
			if(v[i-1]>j)
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
		}
		return dp[n][sum];
	}
}

int main()
{
	int n,target;
	cin>>n>>target;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	cout<<solve(v,n,target);
}
