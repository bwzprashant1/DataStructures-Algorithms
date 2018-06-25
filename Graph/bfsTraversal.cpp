
/*bfs traversal and find 
   nodes at a level l to source*/
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100000];//for adjecency list;
int level[1000];  //keep track of level at which a particular node is present;
bool vis[1000];  //keep track of visited nodes;
int bfs(int s,int l)
{
    int cnt=0;//count the nodes at level l;
    queue<int> q;
    q.push(s);
    level[s]=0;//mark level of source as 0;
    vis[s]=true;//mark source as visited;
    int z=0;  //keep track of z<l;
    while(!q.empty())
    {
        int p=q.front();//pop the queue front();
        q.pop();
        for(int i=0;i<adj[p].size();i++)//visit the adjesency list of just popped element;
        {
            if(vis[adj[p][i]]==false)//if the node is not visited 
            {                        //mark it as visited
                q.push(adj[p][i]);   //and push it to the queue;
                
                level[adj[p][i]]=level[p]+1;//increase the level of child node 
                z=level[p]+1;               //by 1 to their parent;
                if(level[adj[p][i]]==l-1)
                  cnt++;                 //count the node at l th level;
                vis[adj[p][i]]=true;
                
            }
        }
        if(z>=l)    //if z is greater than l th level,we need not to visit further node
         break;     //and just break the loop;
    }
    return cnt;                      //return count of  nodes at level l;
}

int main() {
	int n;  //n nodes
	cin >> n;
	int n1=n-1;//for fully connected graph n-1 edges;
	while(n1--)
	{
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);  //adjacency list creation b/w node x & y;
	    adj[y].push_back(x);
	    
	}
	int lev;
	cin>>lev;
	int result=bfs(1,lev);  //pass the source and level at which you need to count node;
	cout<<result;
	return 0;	
}