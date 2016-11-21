#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int x[10];
	string tmp;
	cin>>n;
	cin>>tmp;
	for(int i=0;i<n;++i)
		x[i]=tmp[i]-'0';
	int mn=10,mx=0,l=3,r=-1;

	for(int i=0;i<n;++i)
	{
		if(x[i])
		{
			mx=max(mx,int(ceil(x[i]/3)));
			mn=min(mn,int(ceil(x[i]/3)));
			l=min(l,x[i]%3);
			r=max(r,x[i]%3);
		}
	}

	cout<<mx<<" "<<mn<<" "<<l<<" "<<r<<endl;
		
	return 0;	     
}
