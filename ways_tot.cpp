// ways to reach a total by adding 3,5 and 10
// -->13
//  >>2

//dynamic programming

#include<bits/stdc++.h>
using namespace std;

int ways(int n)
{
	int res[n+1];
	for(int i=0;i<=n;i++)
		res[i]=0;
	res[0]=1;

	for(int i=3;i<=n;i++)
		res[i]=res[i]+res[i-3];
	for(int i=5;i<=n;i++)
		res[i]=res[i]+res[i-5];
	for(int i=10;i<=n;i++)
		res[i]=res[i]+res[i-10];

	return res[n];

}

int main()
{
	int n;
	cin>>n;
	cout<<ways(n)<<endl;
}