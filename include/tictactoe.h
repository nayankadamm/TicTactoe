#include<iostream>
using namespace std;
class tictactoe
{
    public:
    void printboard(vector<vector<char> >board);
    bool win(vector<vector<char> >board,char symbol);
    void computermove(vector<vector<char> >&board,char symbol);
    void event();
};