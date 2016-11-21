#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;
typedef pair<par,int> parr;

struct ordenar
{
	bool operator ()(pair<par,int> a, pair<par,int> b)
	{
		if(a.first.first==b.first.first)
			return a.first.second>b.first.second;
			
		return a.first.first<b.first.first;
	}
};

int main()
{
	int n,p,s;
	cin>>n>>p>>s;
	vector<parr> m(n);
	vector<int> pp;
	vector<int> ss;

	for(int i=0;i<n;++i)
	{
		cin>>m[i].first.first;
		m[i].second=i+1;
	}
	for(int i=0;i<n;++i)
		cin>>m[i].first.second;
	
	sort(m.begin(),m.end(),ordenar());
	
	int sum=0;
	for(int i=n-p;i<n;++i)
	{
		sum+=m[i].first.first;
		pp.push_back(m[i].second);
	}
	for(int i=0;i<s;++i)
	{
		sum+=m[i].first.second;
		ss.push_back(m[i].second);
	}
	cout<<sum<<endl;
	for(int i=0;i<p;++i)
		cout<<pp[i]<<" ";
	cout<<endl;
	for(int i=0;i<s;++i)
		cout<<ss[i]<<" ";
	cout<<endl;
	


	/*
	for(int i=0;i<n;++i)
		cout<<m[i].first<<" ";
	cout<<endl;
	for(int i=0;i<n;++i)
		cout<<m[i].second<<" ";
	*/
		
}
