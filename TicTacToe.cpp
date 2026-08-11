#include <iostream>
#include <string>

using namespace std;
class TicTacToe{
public:
    TicTacToe(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << board[i][j];
                if(j < 2){
                    cout << '|';
                }
            }
            cout << endl;
            if(i < 2){
                cout << "-----" << endl;
            }
        }
    }

    void makeMove(char player){
        int r = -1;
        int c = -1;
    
        cout << "Current player is: " << player << endl;
        cout << "Choose the coordinate point: ";
        while(true){
            cin >> r >> c;
        
            if(r < 0 || r > 2 || c < 0 || c > 2){
                cout << "Invalid coordinates!" << endl;
            }
            else if(board[r][c] != ' '){
                cout << "Current tile is occupied!" << endl;
            }
            else{
                board[r][c] = player;
                break;
            }
        }
    }

    bool isWin(){

        //checking for horizontal and vertical
        for(int i = 0; i < 3; i++){
            //horizontal
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' '){
                cout << board[i][0] << " wins!" << endl;
                displayBoard();
                cout << endl;
                return true;
            } //vertical
            else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' && board[1][i] != ' ' && board[2][i] != ' '){
                cout << board[0][i] << " wins!" << endl;
                displayBoard(); 
                cout << endl;
                return true;
            } //diag
            else if((board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])){
                cout << board[1][1] << " wins!" << endl;
                displayBoard();
                cout << endl;
                return true;
            }
        }
        return false;
    }

    bool isDraw(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == ' '){
                    return false;
                }
            }
        }
    
        cout << "It's a draw!" << endl; 
        displayBoard();
        cout << endl;
        return true;
    }
private:
    char board[3][3];
};








int main(){
    TicTacToe game;
    char currPlayer = 'X';
    while(true){
        game.displayBoard();
        game.makeMove(currPlayer);
        if(game.isWin()){
            break;
        }

        if(game.isDraw()){
            break;
        }

        currPlayer = (currPlayer == 'X') ? 'O' : 'X';
    }
}