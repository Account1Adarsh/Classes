#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

class Unionfind{
    private:
        vector<int> p,rank,setSize;
        int numSets;
    public:
        //initilization
        Unionfind(int N){
            //creating N sigelton sets
            p.assign(N,0);
            //at beggning everyone is their own parent
            for(int i=0;i<N;i++) p[i]=i;
            //height of all trees is zero
            rank.assign(N,0);
            //each set size is 1;
            setSize.assign(N,1);
            //number of sets
            numSets=N;
        }

        int findset(int i){
            if(p[i]==i) return i;
            //path compression in else statement
            else return p[i]=findset(p[i]);
        }
        bool isSameSet(int i, int j){
            return findset(i)==findset(j);
        }

        void unionSet(int i,int j){
            if(isSameSet(i,j)) return;
            int x=findset(i);
            int y=findset(j);

            if(rank[x]>rank[y]) swap(x,y);

            if(rank[x]==rank[y]) rank[y]++;
            p[x]=y;
            setSize[y]+=setSize[x];
            numSets--;
        }
        int setofSize(int i){
            return setSize[findset(i)];
        }
        int numDisjointSets(){
            return numSets;
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
