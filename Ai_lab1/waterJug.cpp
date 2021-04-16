#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct state{
	int i;
	int j;
	state(int x,int y) : i(x), j(y) {}
};

bool isValid(state st,int a,int b){
     return ((st.i<=a)&&(st.i>=0)&&(st.j<=b)&&(st.j>=0));
}
void printroute(vector<state> st){

	for(auto it:st) cout<<it.i<<" "<<it.j<<endl;
}
struct comprtr { 
    bool operator()(const state p1, const state p2) const
    { 
    	if(p1.i==p2.i) return p1.j<p2.j;
        return p1.i<p2.i; 
    } 
};
bool WaterJugProblem(int jugA, int jugB, int  target){

	      queue<state> pq;

	      bool ispossible=false;
          
          map<state,int,comprtr> vis;

          vector<state> route;

          pq.push({0,0});

          while(!pq.empty()){
                 
                state u = pq.front();

                pq.pop();

                if(vis[u]==1)   continue;

                if(!isValid(u,jugA,jugB)) continue;

                route.pb(u);

                vis[u]=1;


                	

                	if(u.i==target){

                		ispossible=true;

                		if(u.j){

                			route.pb({u.i,0});
                		}
                        printroute(route);
                        return ispossible;
                	}
                	else if(u.j==target){
                		ispossible=true;

                		if(u.i){

                			route.pb({0,u.j});
                		}
                		printroute(route);

                		return ispossible;
                	}

                   pq.push({u.i,jugB});
                   pq.push({jugA,u.j});

                   for(int k=0;k<=max(jugA,jugB);k++){

                           if(u.i+k==jugA||u.j-k==0){
                           	   pq.push({u.i+k,u.j-k});
                           }
                           if(u.i-k==0||u.j+k==jugB){
                           	   pq.push({u.i-k,u.j+k});
                           }

                   }
                    pq.push({ jugA, 0 }); 
                    pq.push({ 0, jugB });
                
        }
        return ispossible;

}
signed main(){

     #ifndef ONLINE_JUDGE
     freopen("D:/input.txt","r",stdin);
   freopen("D:/output.txt","w",stdout);
   #endif

        int jugA=5;
        int jugB=3;
        int target=2;
        if(!WaterJugProblem(jugA,jugB,target)){
        	cout<<"oops No path found";
        }
 

 }
