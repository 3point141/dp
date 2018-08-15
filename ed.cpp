/*Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

    Insert
    Remove
    Replace

    --> saturday
    -->sunday
    >>3
*/

/*

//recursion
#include<bits/stdc++.h>

using namespace std;

int minimum(int a,int b, int c)
{
	if(a<b && a<c)
		return a;
	if(b<a && b<c)
		return b;
	if(c<a && c<b)
		return c;
}

int mini(string a,string b,int l1, int l2)
{
	if(l1==0)
		return l2;
	if(l2==0)
		return l1;
	if(a[l1-1]==b[l2-1])
		return mini(a,b,l1-1,l2-1);
	 
	return 1 + minimum(mini(a,b,l1-1,l2),mini(a,b,l1-1,l2-1),mini(a,b,l1,l2-1));
}


int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int l1=s1.length();
	int l2=s2.length();

	cout<<mini(s1,s2,l1,l2)<<endl;
}

*/

//dynamic program

#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
	if(a<b && a<c)
		return a;
	if(b<a && b<c)
		return b;
	if(c<a && c<b)
		return c;
}
int edit(string s1,string s2,int l1, int l2)
{
	int res[l1+1][l2+1];

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0)
				res[i][j]=j;
			else if(j==0)
				res[i][j]=i;

			else if(s1[i-1]==s2[j-1])
				res[i][j]=res[i-1][j-1];
			else 
				res[i][j]=1+min(res[i-1][j],res[i-1][j-1],res[i][j-1]);
		}
	}

	return res[l1][l2];
}

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int l1=s1.length();
	int l2=s2.length();
	cout<<edit(s1,s2,l1,l2)<<endl;
}
