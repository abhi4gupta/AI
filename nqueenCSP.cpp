/* N-queen Problem with all huerestic discussed
1. minimum remaining value/most constrained
2. least constraint value
3. AC-3 consistency
submitted by iit2018187 (Abhishek Kumar Gupta)

.......if you need interactive and stepwise solution undo the comments.......
*/

#include<bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>
vector<set<int>> domains;
vector<int> vis;
vector<int> q;
int n;
int itrtn=0;
printDomain(){
	for(int i=0;i<n;i++){
	if(!vis[i]){
		cout<<"Domain of variable "<<i<<" --> ";
		for(auto it: domains[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	  }
	}
}
printQueen(){
	for(int i=0;i<n;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
int MinRemainValue(){

    set<ipair> st;
    for(int i=0;i<n;i++){
    	if(domains[i].size()&&!vis[i]){
    		st.insert({domains[i].size(),i});
    	}
    }
    if(st.size()){
    	auto it=*st.begin();
    	if(it.first)
    	return it.second;
        return -1;
    }
    return -1;
}
bool iscompatible(int var,int val){
     for(int i=0;i<n;i++){
     	if(q[i]!=-1&&i!=var){
     		if(q[i]==val) return false;
     		else if(abs(i-var)==abs(val-q[i])) return false;
     	}
     }
     return true;
}
int cost(int var,int val){
    int cst=0;
	vector<ipair> dir= { {-1,-1},{-1,1},{1,-1},{1,1},{1,0},{-1,0}};
	for(int j=0;j<dir.size();j++){
		auto it=dir[j];
		int row=var,col=val;
		row+=it.first;
		col+=it.second;
		while(row>=0&&row<n&&col>=0&&col<n){
			bool lk=true;
			for(int i=0;i<n;i++){
               if(q[i]!=-1){
               	 if(i==row){lk=false;break;}
     		     else if(q[i]==col) {lk=false;break;}
     		     else if(abs(i-row)==abs(col-q[i])) {lk=false; break;}
     	       }
			}
			if(lk) {
			cst++;}
			row+=it.first;
			col+=it.second;
		}
	}
    return cst;
}
vector<int> leastConstraint(int var){
    set<ipair> st;
    vector<int> v;
    auto list=domains[var];
    for(auto it: list){
    	int ct=cost(var,it);
       st.insert({ct,it});
    }
    for(auto it:st) v.push_back(it.second);
    return v;
}
bool AC3(vector<ipair> &tmp,int var,int val){
    for(int i=0;i<n;i++){
    
    	if(i!=var&&!vis[i]){
        for(auto it=domains[i].begin();it!=domains[i].end();){
        		bool kk=false;
        	    int p=*it;
            	if((*it)==val) {
            		kk=true;
            		tmp.push_back({i,(*it)});          		  
            	    it=domains[i].erase(it);					 
            		if(domains[i].empty()) {
					return false; }
					if(it==domains[i].end()) break;
                }
            	if(abs(i-var)==abs((*it)-val)){
            		kk=true;
            		tmp.push_back({i,*it});
            	    it=domains[i].erase(it);
            		if(domains[i].empty()){	
					 return false;}
					if(it==domains[i].end()) break;
            	}
            	if(!kk) ++it;
                
            }
        }
    }
    return true;
}
bool backtrack(){
	//cout<<"\n --------no of iteration "<<itrtn++<<"---------"<<endl;
	bool t=true;
	for(int i=0;i<n;i++){
		if(q[i]==-1){ t=false;break;}
	}
	if(t) return true;
	int var=MinRemainValue();
	if(var==-1) return false;
	//	 cout<<" Minimum Remaining Values of all variable \n";
    //	 printDomain();
	//cout<<"selected Variable\n"<<var<<endl;
    vector<int> lis = leastConstraint(var);
    //cout<<"order of values\n";
    //for(auto it:lis) cout<<it<<" ";cout<<endl;

	for(auto val:lis){
		if(iscompatible(var,val)&&!vis[var]){
			vis[var]=1;
		  int tmp=q[var];
          q[var]=val;
          //cout<<"Arrangement of Queens\n";
          //printQueen();
          vector<pair<int,int>> temp;
          if(AC3(temp,var,val)){
            //cout<<"selected val \n"<<val<<endl;
            //cout<<"domain After applying AC3\n";
            //printDomain();
          	if(backtrack()) return true;
          }
          q[var]=-1;
          vis[var]=0;
          for(auto it:temp){
            domains[it.first].insert(it.second);
          }   
       }
        
	}

	return false;
}
void solveNQueen(int n){
	for(int i=0;i<n;i++){
		set<int> st;
		for(int j=0;j<n;j++){
             st.insert(j);
		}
		domains.push_back(st);
		q.push_back(-1);
		vis.push_back(0);
	}
	if(backtrack()){
         for(int i=0;i<n;i++){
         	for(int j=0;j<n;j++){
         		if(q[i]==j) cout<<1<<" ";
         		else cout<<0<<" ";
         	}
         	cout<<endl;
         }
	}
	else cout<<"no solution\n";

}
signed main(){
	#ifndef ONLINE_JUDGE
    freopen("D:/input.txt","r",stdin);
    freopen("D:/output.txt","w",stdout);
    #endif
    n=10;
//    cout<<" ENTER THE SIZE OF CHESS\n";
//    cin>>n;
    solveNQueen(n);
}
