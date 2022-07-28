#include<bits/stdc++.h>
#include <iomanip>
#include<set>
using namespace std;
 //MACROS
#define ll long long int
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define bs binary_search
#define umap unordered_map
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define all(v) (v).begin(),(v).end()
#define scan2d(dp,n,compo) for(int i=0;i<n;i++){for(int j=0;j<compo;j++)cin>>dp[i][j];}
#define scan1d(dp,n) for(int i=0;i<n;i++)cin>>dp[i];
#define print2d(dp,n,compo) for(int i=0;i<n;i++){for(int j=0;j<compo;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
#define print1d(dp,n) for(int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<"\n";



bool isSafe(int i ,int j ,int n ,vector<vector<ll>>&grid,ll N){    //

for(int k =0;k<N;k++){

    if(grid[k][j]==n || grid[i][k]==n){

        return false;
    }
}

int subgrade=(sqrt(N));
int row_subgrade=i-(i%subgrade);
int coloumn_subgrade=j-(j%subgrade);

for(int a =0 ;a<subgrade;a++){

    for(int  b=0 ;b<subgrade;b++){
        if(grid[a+row_subgrade][b+coloumn_subgrade]==n){

            return false;
        }

    }
}
return true;

}

bool gridSolve(vector<vector<ll>>&grid,ll N){

int i,j,key=0;
for( i =0 ;i<N;i++){
    for( j =0 ;j<N;j++){
        if(grid[i][j]==0){
           key=-1;
            break;
        }


    }
    if(key==-1){
    break;
}

}
if(i==N &&j==N){
    return true;
}

for(int n=1;n<=N;n++)
{

    if(isSafe(i ,j ,n,grid, N)){

        grid[i][j]=n;
        if(gridSolve(grid, N))
            return true;

        grid[i][j]=0;
    }
}
return false;
}


int print_grid(vector<vector<ll>>&grid,ll N){

for(int i =0 ;i<N;i++){

    for(int j =0 ;j<N;j++){

        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
}

}

int main(){

cout<<"Enter number of Suduko grid"<<endl;
ll t;

cin>>t;

while(t--){
ll N;
cout<<"Enter size of Grid"<<endl;
cin>>N;
vector<vector<ll>>grid;
for(int i =0 ;i<N;i++){
        vector<ll>V;
    for(int j =0;j<N;j++){
        ll a;
        cin>>a;
        V.push_back(a);

    }
    grid.push_back(V);

}



if(gridSolve(grid,N)==true){

    cout<<"Yes! Suduko is solvable"<<endl;
    print_grid(grid,N);
}
else{

    cout<<"No! Suduko is not solvable"<<endl;}

}

return 0;
}