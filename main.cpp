#include <iostream>
using namespace std;
char X,O;
char slot[3][3] = {{'1','2','3',},{'4','5','6'},{'7','8','9'}}, turn = 'X';
string Player1 , Player2 ;
int row,column;
bool draw=false;

void ticBoard(){

system("cls");

cout<< "\n\n\t\t\t\t\t  T i c   T a c   T o e   G a m e\n"; 
cout<< "\n\nPlayer Name[Input Letter] : "<<endl;
cout<< "\n"<<Player1<<"[X]"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t"<<Player2<<"[O]";
cout<< "\n\nTic Board : "<<endl;

cout<< "\t\t\t\t\t\t     |     |     \n";
cout<< "\t\t\t\t\t\t  "<<slot[0][0]<<"  |  "<<slot[0][1]<<"  |  "<<slot[0][2]<<"  \n";
cout<< "\t\t\t\t\t\t_____|_____|_____\n";
cout<< "\t\t\t\t\t\t     |     |     \n";
cout<< "\t\t\t\t\t\t  "<<slot[1][0]<<"  |  "<<slot[1][1]<<"  |  "<<slot[1][2]<<"  \n";
cout<< "\t\t\t\t\t\t_____|_____|_____\n";
cout<< "\t\t\t\t\t\t     |     |     \n";
cout<< "\t\t\t\t\t\t  "<<slot[2][0]<<"  |  "<<slot[2][1]<<"  |  "<<slot[2][2]<<"  \n";
cout<< "\t\t\t\t\t\t     |     |     \n";

return;

}

void playerTurn(){
    int choice;

    if(turn == 'X'){
        cout<< "\n\t"<<Player1<<"[X]'s Turn :  ";
    }
    if(turn == 'O'){
        cout<< "\n\t"<<Player2<<"[O]'s Turn :  ";
    }
cin>>choice;

switch (choice)
{
case 1:
    row =0,column =0;
    break;
case 2:
    row =0,column =1;
    break;
case 3:
    row =0,column =2;
    break;
case 4:
    row =1,column =0;
    break;
case 5:
    row =1,column =1;
    break;
case 6:
    row =1,column =2;
    break;
case 7:
    row =2,column =0;
    break;
case 8:
    row =2,column =1;
    break;
case 9:
    row =2,column =2;
    break;
default:
cout<<"Seems Like You're in a bit of Hurry, INVALID ENTRY!!!";
    break;
     
}
if(turn == 'X' && slot[row][column]!='X' && slot[row][column]!='O'){
    slot[row][column]='X';
    turn = 'O';
}
else if(turn == 'O' && slot[row][column]!='X' && slot[row][column]!='O'){
    slot[row][column]='O';
    turn = 'X';
}
else{
    cout<<"\nBox Is ALREADY FILLED!!\nPlease Choose Your SLOT CAREFULLY\n";
    playerTurn();
}
ticBoard();
}

bool gameOver(){

//checking win
for(int i=0;i<3;i++){     //column checking
    if(slot[i][0] == slot[i][1] && slot[i][0] == slot[i][2]){
        return false;
    }
}
    


for(int j=0;j<3;j++){      //row checking
    if(slot[0][j] == slot[1][j] && slot[0][j] == slot[2][j]){
        return false;
    }
}
    
   //diagonal checking
    if(slot[0][0] == slot[1][1] && slot[0][0] == slot[2][2] || slot[0][2] == slot[1][1] && slot[0][2] == slot[2][0]){
        return false;
    }



//game keeps running
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(slot[i][j]!='X' && slot[i][j]!='O'){
            return true;
        }
    }
}
    
    
draw=true;
return false;
}



int main(){

cout<< "\n\n\t\t\t  W e l c o m e   T o   T i c   T a c   T o e   G a m e\n"; 
cout<< "\nEnter the name of First Player : ";
cin>>Player1;
cout<< "\n\t\t\t  Gear Up "<<Player1<<", Your Letter is 'X'"<<endl;
cout<< "\nEnter the name of Second Player : ";
cin>>Player2;
cout<< "\n\t\t\t  Gear Up "<<Player2<<", Your Letter is 'O'"<<endl;
string null;
cout<<"\n\t\t\t  Type 'start' To Continue..."<<endl;
cin>>null;

while (gameOver()){


ticBoard();
playerTurn();
gameOver();

}

if(turn == 'X' && draw==false){
    cout << Player2 << " WINS, CONGRATULATIONS!!!\n";
}

else if(turn == 'O' && draw==false){
    cout << Player1 << " WINS, CONGRATULATIONS!!!\n";
}

else{
    cout << "TOUGH ONE AYYE :/\nIT'S A DRAW!!!";
}

return 0;
}
