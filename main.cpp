#include <iostream>
#include <vector>
#include <cstdlib>
#define N 64

using namespace std;

//queen's position <row,column>
vector<pair<int,int>> q(N);

//chess board
int board[N][N]={};

void printPositions()
{
    for(int it=0;it<N;it++)
    {
        cout<<q[it].first<<","<<q[it].second<<endl;
    } 
}

void printBoard()
{
    for(int it=0;it<N;it++)
    {
        board[q[it].first][q[it].second]=1;
    }

    //print the board with postions included
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<"  ";
        }

        cout<<endl;
    }

    cout<<endl;
}

bool isSafe(int col)
{
    if(col==0) return true;

    for(int i=col-1;i>=0;i--)
    {
        //test if rows are different
        if(q[col].first != q[i].first)
        {
            //test diagonal
            if(abs(q[col].first-q[i].first) != abs(q[col].second-q[i].second))
            { 
                continue;
            }

            else {return false;}        
        }

        else {return false;} 
    }

    return true;
 }

bool solve(int col)
{
    
    //recursion done
    if(col==N) return true;

    
    //test each of the column
    for(int i=0;i<N;i++)
    {
        //assign current position
        q[col]={i,col};
        
        //test if queen is safe
        if(isSafe(col))
        {            
            //continue on next position (if false backtrack previous position)
            if(solve(col+1)) return true;
        }

    }

    return false;
}

int main(){

    solve(0);
 
    printBoard();
    printPositions();

}
