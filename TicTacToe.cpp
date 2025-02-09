#include<bits/stdc++.h>
using namespace std;

bool check(const vector<vector<char>>Matrix,int number){
    int n=(number-1)/3,m=(number-1)%3;
    return (number >= 1 && number <= 9 && Matrix[n][m] == ' ');
}

bool win(vector<vector<char>> &Matrix) {
        for (int i = 0; i < 3; i++) {
            if (Matrix[i][0] != ' ' && Matrix[i][0] == Matrix[i][1] && Matrix[i][1] == Matrix[i][2])
                return true;
        }
    
        for (int i = 0; i < 3; i++) {
            if (Matrix[0][i] != ' ' && Matrix[0][i] == Matrix[1][i] && Matrix[1][i] == Matrix[2][i])
                return true;
        }
    
        if (Matrix[0][0] != ' ' && Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])
            return true;
    

        if (Matrix[0][2] != ' ' && Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])
            return true;
    
        return false;
}
void Display(vector<vector<char>>Matrix){
    cout << "   |   |   " << endl;
    cout << " " << Matrix[0][0] << " | " << Matrix[0][1] << " | " << Matrix[0][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Matrix[1][0] << " | " << Matrix[1][1] << " | " << Matrix[1][2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Matrix[2][0] << " | " << Matrix[2][1] << " | " << Matrix[2][2] << " " << endl;
    cout << "   |   |   " << endl;
}
int main()
{
    string Player1,Player2;
    cout<<"Enter Player1 Name = ";
    getline(cin,Player1);
    cout<<"Enter Player2 Name = ";
    getline(cin,Player2);
    vector<vector<char>> Matrix(3, vector<char>(3, ' '));
    bool player1turn=true;
    bool player2turn=false;
    int number;
    int i=0;
    while(i<9){
        if(i==0){
        Display(Matrix);
        }
        if(player1turn){
            cout<<"Press 1 to 9 any Number for X ";
            cin>>number;
            if(check(Matrix,number)){
                int n=(number-1)/3,m=(number-1)%3;
                Matrix[n][m]='X';    
                Display(Matrix);
                if(win(Matrix)){
                    cout<<Player1<<" Winner"<<endl;
                    return 0;
                }
                else{
                player2turn = true;
                player1turn = false;
                }
            }    
        }
        else if(player2turn){
            cout<<"Press 1 to 9 any Number for O ";
            cin>>number;
            if(check(Matrix,number)){
                int n=(number-1)/3,m=(number-1)%3;
                Matrix[n][m]='O';  
                Display(Matrix);
                if(win(Matrix)){
                    cout<<Player2<<" Winner"<<endl;
                    return 0;
                }
                else{
                    player2turn = false;
                    player1turn = true;
                }
            }
        }
        i++;
    }
    if(!win(Matrix)){
        cout<<"Draw Match"<<endl;
    }
    return 0;
}