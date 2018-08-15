/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the 
given set with sum equal to given sum.

Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

*/

/*
// recursion

#include<bits/stdc++.h>
using namespace std;

bool check(int a[],int n,int sum)
{
	if(n==0)
		return false;
	if(sum==0 && n!=0)
		return true;
	if(a[n-1]>sum)
		return check(a,n-1,sum);

	return check(a,n-1,sum)||check(a,n-1,sum-a[n-1]);
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  	cin>>a[i];
  int sum;
  cin>>sum;

  cout<<check(a,n,sum)<<endl;
}
*/

//dynamic program

#include<bits/stdc++.h>
using namespace std;

int check(int a[],int n, int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<a[i-1])
				dp[i][j]=dp[i-1][j];
			if(j>=a[i-1])
				dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
		}
	}
return dp[n][sum];
}


int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  	cin>>a[i];
  int sum;
  cin>>sum;

  cout<<check(a,n,sum)<<endl;
}