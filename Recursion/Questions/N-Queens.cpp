// Problem Link - https://leetcode.com/problems/n-queens/

class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool valid(int row,int col,int n, vector<string> &board){
        
        int x=row,y=col;
        
        // upper left diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')    return 0;
            row--;
            col--;
        }
           
        row = x;
        col = y;
        
        // left row
        while(col>=0){
            if(board[row][col]=='Q')    return 0;
            col--;
        }
        
        col = y;
        
        // lower left diagonal
        while(row<n && col>=0){
            if(board[row][col]=='Q')    return 0;
            row++;
            col--;
        }
        
        return 1;
    }
    
    void helper(int col,int n, vector<string> board){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            
            if(valid(i,col,n,board)){
                board[i][col] = 'Q';
            
                helper(col+1,n,board);

                board[i][col] = '.';
            }
                
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i] = s;
        
        helper(0,n,board);
        
        return ans;
    }
};

// Optimised Solution

class Solution {
public:
    vector<vector<string>> ans;
    
    void helper(int col,int n,vector<string> board,vector<int> &leftrow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            
            if(leftrow[i]==0 && lowerDiagonal[i+col]==0 && upperDiagonal[n-1-i+col]==0){
                board[i][col] = 'Q';
                leftrow[i] = 1;
                lowerDiagonal[i+col] = 1;
                upperDiagonal[n-1-i+col] = 1;
                
                helper(col+1,n,board,leftrow,upperDiagonal,lowerDiagonal);
                
                board[i][col] = '.';
                leftrow[i] = 0;
                lowerDiagonal[i+col] = 0;
                upperDiagonal[n-1-i+col] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i] = s;
        
        vector<int> leftrow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        helper(0,n,board,leftrow,upperDiagonal,lowerDiagonal);
        
        return ans;
    }
};
