#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	int n;
	cin>>T>>n;
	vector<int> max(n);
	vector<int> min(n);
	vector<int> n_max,n_min;
	for(int i=1;i<n+1;++i)
		max[i]=min[i]=i;

	char tmp;
	while(max.size()!=1 && min.size()!=1)
	{
		for(int i=1;i<max.size();i+=2)
		{
			cout<<"? "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>tmp;
			if(tmp=='>')
			{
				n_max.push_back(max[i]);
				n_min.push_back(i+1);
			}
			if(tmp=='<')
			{
				n_max.push_back(i+1);
				n_min.push_back(i);
			}
			if(tmp=='=')
			{
				n_max.push_back(i+1);
				n_min.push_back(i);
			}
		}
		if(max.size()&1==1)
		{
			n_max.push_back(max[max.size()-1]);
			n_min.push_back(min[min.size()-1]);
		}

		







		
		max=n_max;
		min=n_min;
		n_max.clear();
		n_min.clear();


		cout<<"LOOK "<<max.size()<<endl;
		cout<<"LOOK "<<min.size()<<endl;
	}
	cout<<"! "<<min[0]<<" "<<max[0]<<endl;
}
