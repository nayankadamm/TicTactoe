#include<iostream>
#include "../include/tictactoe.h"
using namespace std;
void tictactoe::printboard(vector<vector<char> >board)
{   
    try
    {
       cout << endl;
    cout << "    0  "
            << " 1  "
         << " 2  " << endl;
    cout << "  +---+---+---+" << endl;
    cout << "0 | ";
    for (int i = 0; i < 3; i++) {
        cout << board[0][i] << " | ";  
    }
    cout << endl;
    cout << "  +---+---+---+" << endl;
    cout << "1 | ";
    for (int i = 0; i < 3; i++) {
        cout << board[1][i] << " | ";     
    }
    cout << endl;
    cout << "  +---+---+---+" << endl;
    cout << "2 | ";
    for (int i = 0; i < 3; i++) {
        cout << board[2][i] << " | ";        
    }
    cout << endl;
    cout << "  +---+---+---+" << endl;
    cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}
bool tictactoe::win(vector<vector<char> >board,char symbol){
    try
    {
       
     for(int i=0;i<3;i++){

        if((board[i][0]==symbol)&&(board[i][1]==symbol)&&(board[i][2]==symbol))
            return true;
        if((board[0][i]==symbol)&&(board[1][i]==symbol)&&(board[2][i]==symbol))
            return true;
    }
    if((board[0][0]==symbol)&&(board[1][1]==symbol)&&(board[2][2]==symbol))
        return true;
    if((board[0][2]==symbol)&&(board[1][1]==symbol)&&(board[2][0]==symbol))
        return true;
    return false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}
void tictactoe::computermove(vector<vector<char> >&board,char symbol)
{
    try
    {
        int x,y;
    do{
        x=rand()%3;
        y=rand()%3;
    }while(board[x][y]!=' ');
    board[x][y]=symbol;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}
void tictactoe::event(){
    try
    {
        int flag=0;
        cout<<"1:Play with computer"<<endl;
    cout<<"2:Play with another player"<<endl;
    int choice;
    cin>>choice;   
    vector<vector<char> >board(3,vector<char>(3,' '));
    printboard(board);
    int x,y;
    char symbol;
    int count=0;
    while(count<9){
        if(count%2==0)
            symbol='X';
        else
            symbol='O';
        if(choice==1){
            if(count%2==0){
                cout<<"Enter the position where you want to place your ' "<<symbol<<" '"<<endl;
                cin>>x>>y;
                if(board[x][y]!=' '){
                    cout<<"Invalid move"<<endl;
                    continue;
                }
                board[x][y]=symbol;
            }
            else{
                computermove(board,symbol);
            }
        }
        else{
            cout<<"Enter the position where you want to place your ' "<<symbol<<" '"<<endl;
            cin>>x>>y;
            if(board[x][y]!=' '){
                cout<<"Invalid move"<<endl;
                continue;
            }
            board[x][y]=symbol;
        }
        printboard(board);
        if(win(board,symbol)){
            cout<<"Player "<<symbol<<" has won"<<endl;
            flag=1;
            break;
        }
        count++;
    }
    if(flag==0){
        cout<<"Match Draw"<<endl;
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }       
}

