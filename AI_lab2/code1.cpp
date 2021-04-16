/*Implement the dijkstra's algorithm on a graph. The vertices have "string" names (e.g. CC1, CC2, LT, etc.). 
The edges along with the weights also have a "string" name (e.g. ringRoad, linkRoad, etc). 
The shortest path from the source to all vertices should be printed as a string of vertex and edge names on 
the shortest path (e.g. CC1 linkRoad CC2, ringRoad, LT, etc). 
Implement the solution using both a heap as a data structure and an array as a priority queue as a data structure. */
#include<bits/stdc++.h> 
#define int long long
using namespace std; 
# define INF 1e18 
typedef pair<int, int> iPair; 
 
void addEdge(int u, int v, int wt,vector <pair<int, int> > adj[]) 
{ 
    adj[v].push_back(make_pair(u, wt)); 
    adj[u].push_back(make_pair(v, wt)); 
   
} 

void dijpriority( int V, int src,vector <pair<int, int> > adj[],vector<int> &dist,vector<int> &par) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    {  
        int u = pq.top().second; 
        pq.pop(); 
        for (auto x : adj[u]) 
        {
            int v = x.first; 
            int weight = x.second;  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
                par[v]=u;
            } 
           
        } 
    }  
} 
signed main(){
   #ifndef ONLINE_JUDGE
   freopen("D:/input.txt","r",stdin);
   freopen("D:/output.txt","w",stdout);
  #endif
    int n ,m;
    cout<<"no of vertex and edges"<<endl;
    cin>>n>>m;
    vector<int> dist(n+1, INF);
    vector <pair<int, int> > adj[n+1];
    vector<int> par(n+1,0);
    map<int, string> mpVtoS;
    map<string,int>  mpStoV;
    map<int,map<int,string>> mk;
    
    cout<<" enter source destination edge name and weight respectively"<<endl;
    int k=0;
    for(int i=0;i<m;i++){
           string src,des,edgename;
           int weight;
           cin>>src>>des>>edgename>>weight;
           if(!mpStoV.count(src)){
              mpStoV[src]=k;
              mpVtoS[k++]=src;
           }
           if(!mpStoV.count(des)){
             mpStoV[des]=k;
             mpVtoS[k++]=des;
           }
        mk[mpStoV[src]][mpStoV[des]]=edgename;
        mk[mpStoV[des]][mpStoV[src]]=edgename;
        addEdge(mpStoV[src],mpStoV[des],weight,adj);
    }
    cout<<"enter source name"<<endl;
    string source;
    cin>>source;
    par[mpStoV[source]]=-1;
    dijpriority(n,mpStoV[source],adj,dist,par);
    cout<<"list of source name\n";
    for(int i=0;i<n;i++) cout<<mpVtoS[i]<<endl;
    for(int i=0;i<n;i++){
        if(i!=mpStoV[source]){
            cout<<"path of "<< mpVtoS[i]<<endl;
            int pt=i;
            while(pt!=-1){
                if(par[pt]==-1) 
                cout<<mpVtoS[pt];
                else
                cout<<mpVtoS[pt]<<" -- "<<mk[pt][par[pt]]<<" --> ";
                pt=par[pt];
            }
            cout<<endl;
        }
    }
    

}
