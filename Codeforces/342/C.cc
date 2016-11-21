#include <bits/stdc++.h>
#define MAXN 502
using namespace std;
int matrix[MAXN][MAXN];

void fill(int idx1,int idx2,int n,int &begin)
{
  for(int i =0 ;i < n; ++i)
    for(int j = idx1 ; j < idx2 ; ++j)
      matrix[i][j] = begin++;
}

int giveSum(int k,int n)
{
  int ans=0;
  for(int i = 0 ;i < n ; ++i)
    ans += matrix[i][k];
  return ans;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k,id ; cin >> n >> k;
  --k;
  id = 1;
  fill(0,k,n,id);
  fill(k,n,n,id);
  cout << giveSum(k,n) << "\n";
  for(int i = 0;i < n ; ++i)
    {
      for(int j = 0 ;j < n ; ++j)
	cout << matrix[i][j] << " ";
      cout << "\n";
    }
  return 0;
}
