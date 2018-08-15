/*
// longest subsequence
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int maxi(string a, string b, int l1, int l2)
{
	//int l1=a.length();
	//int l2=b.length();
	if(l1==0 || l2==0)
		return 0;
	else if(a[l1-1]==b[l2-1])
		return 1+maxi(a,b,l1-1,l2-1);
	else
		return max(maxi(a,b,l1,l2-1),maxi(a,b,l1-1,l2));
}


int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int l1,l2;
	l1=a.length();
	l2=b.length();
	cout<<maxi(a,b,l1,l2)<<endl;
}
*/

//Dynamic Programming

#include<bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}
int maxi(string a,string b,int l1,int l2)
{
	int lcs[l1+1][l2+1];

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0)
				lcs[i][j]=0;
			else if(a[i]==b[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}

	return lcs[l1][l2];
}

int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int l1=a.length();
	int l2=b.length();
	cout<<maxi(a,b,l1,l2)<<endl;
}