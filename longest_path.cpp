/*
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) 
such that all cells along the path are in increasing order with a difference of 1.

We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) 
with the condition that the adjacent cells have a difference of 1.

Example:

Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4
The longest path is 6-7-8-9. 

*/



#include<bits/stdc++.h>
using namespace std;
#define n 3
void input(int a[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int update(int a[n][n],int res[n][n],int i,int j)
{
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(res[i][j]!=-1)
		return res[i][j];
	if(j<n-1 && ((a[i][j]+1)==a[i][j+1]))
		return res[i][j]=1+update(a,res,i,j+1);
	if(i>0 && ((a[i][j]+1)==a[i-1][j]))
		return res[i][j]=1+update(a,res,i-1,j);
	if(i<n-1 && ((a[i][j]+1)==a[i+1][j]))
		return res[i][j]=1+update(a,res,i+1,j);
	if(j>0 && ((a[i][j]+1)==a[i][j-1]))
		return res[i][j]=1+update(a,res,i,j-1);

	return res[i][j]=1;

}
int traverse(int a[3][3])
{
	int result=1;
	int res[n][n];
	memset(res,-1,sizeof res);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(res[i][j]==-1)
			{
				update(a,res,i,j);
			}
		result=max(result,res[i][j]);
		}
	}
	return result;
}
int main()
{
	int a[n][n];
	input(a);

	cout<<traverse(a)<<endl;
}
