#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int row , int col , vector<string>&board,int n){
    int dupRow = row;
    int dupCol = col;

    while(row>=0 &&  col>=0){
        if(board[row][col] == 'Q')return false;
        row--;
        col--;
    }
    col = dupCol;
    row = dupRow;
    while(col>=0){
        if(board[row][col] == 'Q' )return false;
        col--;
    }
    row = dupRow;
    col = dupCol;
    while(row<n && col>=0){
        if(board[row][col] =='Q')return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col , vector<string>&board, vector<vector<string>>&ans,int n){
    if(col == n)return ans.push_back(board);
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,board, ans,n);
            board[row][col] = '.';
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<string>board(n,string (n,'.'));
    vector<vector<string>>ans;

    solve(0,board,ans,n);
    for(auto v:ans){
        for(auto s:v){
            for(auto i: s){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
