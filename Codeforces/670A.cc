#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,1,0,0,0,0,0};
int dy[] = {0,0,0,0,0,1,1};

int main()
{
  int mini = 0,maxi = 0;
  int n ; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      mini += dy[i%7];
      maxi += dx[i%7];
    }
  cout << mini << " " << maxi << "\n";
}
