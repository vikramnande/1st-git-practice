#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair

bool issafe(int x,int y,int n,int m,vector<vector<int> > &adj,vector<vector<bool> > &vis)
{
    if(x>=0 && x<n && y>=0 && y<=m && (adj[x][y]==1 || adj[x][y]==9) && !vis[x][y])
        return true;

    return false;
}

void solve(int x,int y,int n,int m,vector<vector<int> > &adj,vector<vector<bool> > &vis)
{
    if(!issafe(x,y,n,m,adj,vis))
        return;
    vis[x][y]=true;

    solve(x+1,y,n,m,adj,vis);
    solve(x-1,y,n,m,adj,vis);
    solve(x,y+1,n,m,adj,vis);
    solve(x,y-1,n,m,adj,vis);
}

int main()
{
    int n,m,i1,j1;
    cin>>n>>m;
    vector<vector<int> > adj(n,vector<int>(m,0));
    vector<vector<bool> > vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]==9)
            {
                i1=i;
                j1=j;
            }
        }
    }
    cout<<"New generation"<<endl;
    solve(0,0,n,m,adj,vis);
    if(vis[i1][j1])
        cout<<1<<endl;
    else
        cout<<0<<endl;

    return 0;
}
