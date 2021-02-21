#include <iostream>
#include <conio.h> 

using namespace std;

class TicTacToe{
	private:
		char board[3][3];
		char mark;
		int turn;
		int won;
		int input;
	public:
		TicTacToe():board{'1','2','3','4','5','6','7','8','9'}{
			turn = 1;
			mark = 'O';
			won = 0;
			input = 0;
		}
		int GetResult(){
			return won;
		}
		void Play(){
			for(int i=0; i<9; i++){
				system("cls");
				PrintBoard();
				
				Input();
				
				int validInput = AddMark();
				if( !validInput ){
					i--;
					continue;
				}
				
				Result(i);
				if(won != 0)	break;
				
				turn = !turn;
			}	
		}
		void Result(int i){
			if(Check()){
				system("cls");
				PrintBoard();
				if(turn){
					cout<<endl<<"*** Player 1 - You Won ***";
					won = 1;
					return;
				}
				else {
					cout<<endl<<"*** Player 2 - You Won ***";
					won = 2;
					return;
				}
			}
			if( i==8 ){
				system("cls");
				PrintBoard();
				cout<<endl<<"*** Match Draw ***";
				won = 3;
				return;
			}
			won = 0;
		}
		void Input(){
			cin>>input;
			while(input<0 || input >9){
				cout<<"Invalid input. Please re-enter: ";
				cin>>input;
			}
			if(turn) mark = 'O';
			else mark = 'X';
		}
		void PrintBoard(){
			cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
			cout<<"-----------"<<endl;
			cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
			cout<<"-----------"<<endl;
			cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
			
			if(turn) cout<<"O - Player 1: ";
			else cout<<"X - Player 2: ";
		}
		int AddMark(){
			for(int i=0, k=1; i<3; i++){
				for(int j=0; j<3; j++, k++){
					if(k == input){
						if(board[i][j]!='O' && board[i][j]!='X'){
							board[i][j] = mark;
							return 1;
						}
						else return 0;
					}
				}
			}
		}
		int Check(){
			//rows
			if( board[0][0]==mark && board[0][1]==mark &&board[0][2]==mark )
				return 1;
			if( board[1][0]==mark && board[1][1]==mark &&board[1][2]==mark )
				return 1;
			if( board[2][0]==mark && board[2][1]==mark &&board[2][2]==mark )
				return 1;
				
			//columns
			if( board[0][0]==mark && board[1][0]==mark &&board[2][0]==mark )
				return 1;
			if( board[0][1]==mark && board[1][1]==mark &&board[2][1]==mark )
				return 1;
			if( board[0][2]==mark && board[1][2]==mark &&board[2][2]==mark )
				return 1;
			
			//diagonals
			if( board[0][0]==mark && board[1][1]==mark &&board[2][2]==mark )
				return 1;
			if( board[0][2]==mark && board[1][1]==mark &&board[2][0]==mark )
				return 1;
		}
		void Reset(){
			board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3'; 
			board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6'; 
			board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9'; 
			turn = 1;
			mark = 'O';
			won = 0;
			input = 0;
		}
};

int main(){
	TicTacToe t;
	char replay;
	do{
		t.Play();
		t.Reset();
		
		cout<<endl<<endl<<"Do you want to play again (Y/N): ";
		replay = getche();
	}while(replay=='y'||replay=='Y');
		
	getch();
	return 0;
}
 
