#include <iostream>
#include "dev.h"

using namespace std;
string board[9]={" "," "," "," "," "," "," "," "," "};
int player=1;
int dieukien=0;

void showgame()
{
    cout<<"Nhấn Enter để bắt đầu.";
    getchar();
    cout<<"\n";
    cout<<"TicTacToe Game"<<endl;
    cout<<"Player 1: X\nPlayer 2: O"<<endl;
    cout<<"\n\n";
    cout<<"     |     |      "<<endl;
    cout<<"  1  |  2  |  3   "<<endl;
    cout<<"_____|_____|______"<<endl;
    cout<<"     |     |      "<<endl;
    cout<<"  4  |  5  |  6   "<<endl;
    cout<<"_____|_____|______"<<endl;
    cout<<"     |     |      "<<endl;
    cout<<"  7  |  8  |  9   "<<endl;
    cout<<"     |     |      "<<endl;
}

bool checkwinner()
{
    bool winner = false;
    if((board[0]==board[1])&&(board[1]==board[2])&&(board[0]!=" "))
    {
        winner=true;
    }
    else if((board[3]==board[4])&&(board[4]==board[5])&&(board[4]!=" "))
    {
        winner=true;
    }
    else if((board[6]==board[7])&&(board[7]==board[8])&&(board[6]!=" "))
    {
        winner=true;
    }
    else if((board[0]==board[3])&&(board[3]==board[6])&&(board[0]!=" "))
    {
        winner=true;
    }
    else if((board[1]==board[4])&&(board[4]==board[7])&&(board[1]!=" "))
    {
        winner=true;
    }
    else if((board[2]==board[5])&&(board[5]==board[8])&&(board[2]!=" "))
    {
        winner=true;
    }
    else if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]!=" "))
    {
        winner=true;
    }
    else if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]!=" "))
    {
        winner=true;
    }
    else{
        winner=false;
    }
    return winner;
}

bool spacesfull()
{
    bool spaces= true;
    for(int i=0;i<9;i++)
    {
        if(board[i]==" ")
        {
            spaces=false;
        }
    }
    return spaces;
}

void drawboard()
{
    cout<<"     |     |      "<<endl;
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  "<<endl;
    cout<<"_____|_____|______"<<endl;
    cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  "<<endl;
    cout<<"_____|_____|______"<<endl;
    cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  "<<endl;
    cout<<"     |     |      "<<endl;
}

void playerturn()
{
    cout<<"Player "<<player<<" chọn vị trí đánh:";
    cin>>dieukien;
    while(board[dieukien-1]!=" ")
    {
        cout<<"Vui lòng chọn vị trí khác .";
        cin>>dieukien;
        cout<<"\n";
    }
}

void updateboard()
{
    if(player==1)
    {
        board[dieukien-1]="X";
    }
    else
    {
        board[dieukien-1]="O";
    }
}

void changeplayer()
{
    if(player==1)
    {
        player++;
    }
    else{
        player--;
    }
}

void taketurn()
{
    while(!checkwinner()&&!spacesfull())
    {
        playerturn();
        updateboard();
        changeplayer();
        cout<<"\33c";
        drawboard();
    }
}

void endgame()
{
    if(checkwinner())
    {
        cout<<"There is a winner."<<endl;
    }
    else if(spacesfull())
    {
        cout<<"TIE,Play Again!"<<endl;
    }
}