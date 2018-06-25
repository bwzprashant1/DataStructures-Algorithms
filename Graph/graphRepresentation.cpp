

#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1000];//adj size should be =n+1;

int main() {
	int n,m;//n nodes m edges;
	cin >> n>>m;
	int m1=m;
	while(m1--)
	  {
	      int x,y;
	      cin>>x>>y;
	      adj[x].push_back(y);//undirected graph; 
	      adj[y].push_back(x);//creating adjecency list;
	  }
	  int q;
	  cin>>q;
	  while(q--)//q queries;
	  {          
	    int x,y;//check there exist an edge b/w node x & y;
	      cin>>x>>y;
	      bool flag=false;
	      for(int i=0;i<adj[x].size();i++)
	      {
	        if(adj[x][i]==y)
	        {
	            cout<< "YES"<<endl;
	            flag=true;
	            break;
	        }
	      }
	      if(flag==false)
	      cout<<"NO"<<endl;
	  }
return 0;
}


