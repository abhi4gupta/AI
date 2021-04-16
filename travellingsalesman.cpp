#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int travelProblem(vector<vector<int>> &gr,int s){
	vector<int> v;
	for(int i=0;i<gr.size();i++) if(i!=s) v.pb(i);
      int ans=INT_MAX;

    do{
    	int cpw=0;
        int prv=s;
    	for(auto it:v) {cpw+=gr[prv][it];prv=it;}
    	cpw+=gr[prv][s];
        ans=min(ans,cpw);
       }while(next_permutation(v.begin(),v.end())); 
       return ans;
}
signed main(){
	 #ifndef ONLINE_JUDGE
   freopen("D:/input.txt","r",stdin);
   freopen("D:/output.txt","w",stdout);
   #endif
    vector<vector<int>> gr= {
    	               { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 }
                   };
   cout<<travelProblem(gr,0);

}