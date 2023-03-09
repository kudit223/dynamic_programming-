/*Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n
 coins. Each coin has a positive integer value. Your task is to produce a sum of money x
 using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7}
 and the desired sum is 11
, an optimal solution is 5+5+1
 which requires 3
 coins.

Input

The first input line has two integers n
 and x
: the number of coins and the desired sum of money.

The second line has n
 distinct integers c1,c2,…,cn
: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1
.

Constraints
1≤n≤100

1≤x≤106

1≤ci≤106

Example

Input:
3 11
1 5 7

Output:
3*/

//approach

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>v,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    dp[i][0]=0;
    for(int j=1;j<sum+1;j++)
    dp[0][j]=INT_MAX-1;
    for(int j=1;j<sum+1;j++)
    {
        if(j%v[0]==0)
        dp[1][j]=j/v[0];
        else
        dp[1][j]=INT_MAX-1;
    }
    
    for(int i=2;i<n+1;i++)
    for(int j=1;j<sum+1;j++)
    {
        if(v[i-1]>j)
        dp[i][j]=dp[i-1][j];
        else
        dp[i][j]=min(dp[i-1][j],1+dp[i][j-v[i-1]]);
    }
    return dp[n][sum];
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    if(solve(v,n,x)>INT_MAX-2)
    cout<<-1;
    else
    cout<<solve(v,n,x);

}
