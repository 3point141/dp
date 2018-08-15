/*
Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

Input:  n = 3
Output: 4
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

Input:  n = 4
Output: 7

*/

/*
#include<bits/stdc++.h>
using namespace std;

int ways(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	
	return ways(n-1)+ways(n-2)+ways(n-3);
}

int main()
{
	int n;
	cin>>n;
	cout<<ways(n)<<endl;
}

*/
#include<bits/stdc++.h>
using namespace std;

int ways(int n)
{
	int res[n+1];
	for(int i=0;i<=n;i++)
		res[i]=0;
	res[0]=1;res[1]=1;res[2]=2;
	for(int i=3;i<=n;i++)
		res[i]=res[i-1]+res[i-2]+res[i-3];

	return res[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<ways(n)<<endl;
}