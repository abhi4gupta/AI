#include<bits/stdc++.h>
using namespace std;
const int N=3;
struct state{
	state* prev;
	int puzz[N][N];
	int x,y,cost,level;
};

void givepuzzle(int puzz[3][3]){
        for(int i=0;i<3;i++){
         	for(int j=0;j<3;j++) cout<<puzz[i][j]<<" "; 
         		cout<<endl;
        }
        cout<<endl;
}
int findCst(int puzz1[N][N], int puzz2[N][N]) 
{ 
	int ans=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(puzz1[i][j]!=0&&puzz1[i][j]!=puzz2[i][j])
				ans++;
    return ans;
}
state* newState(int puzz[N][N], int x, int y, int nX, int nY, int level, state* prv){
	state * st = new state;
	st->prev=prv;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			st->puzz[i][j]=puzz[i][j];
	swap(st->puzz[x][y],st->puzz[nX][nY]);
	st->cost=INT_MAX;
	st->level=level;
	st->x = nX; 
    st->y = nY; 
    return st;
}

struct comprtr { 
    bool operator()(const state* p1, const state* p2) const
    { 
        return (p1->cost + p1->level) > (p2->cost + p2->level); 
    } 
};

int isValid(int x, int y) { 
    return (x >= 0 && x < N && y >= 0 && y < N); 
}
void printAllstep(state* root){
	if(root==NULL) return;
	printAllstep(root->prev);
	givepuzzle(root->puzz);
}
void puzzle8problem(int src[N][N],int x, int y, int des[N][N]){
	priority_queue<state*, vector<state*>, comprtr> pq;
    state * root = newState(src,x,y,x,y,0,NULL);
    root->cost=findCst(src,des);
    pq.push(root);
    while(!pq.empty()){
    	state * u= pq.top();
    	pq.pop();
    	if(u->cost==0){
              printAllstep(u);
              return;
    	}
    	else{
    		int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    		for(int i=0;i<4;i++){
    			if(isValid(u->x+dr[i][0],u->y+dr[i][1])){
    				state * nextState = newState(u->puzz,u->x,u->y,u->x+dr[i][0],u->y+dr[i][1],u->level+1,u);
    				nextState->cost = findCst(nextState->puzz,des);
    				pq.push(nextState); 
    			}
    		}
    	}
    }
}

signed main(){

     #ifndef ONLINE_JUDGE
     freopen("D:/input.txt","r",stdin);
   freopen("D:/output.txt","w",stdout);
   #endif
     int start[N][N] = 
    { {1, 2, 3}, {5, 6, 0}, {7, 8, 4} 
    }; 
  
    int final[N][N] = 
    { {1, 2, 3}, {5, 8, 6}, {0, 7, 4} 
    }; 
     int ix=1,iy=2;
     
     puzzle8problem(start,ix,iy,final);
}