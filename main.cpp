#include <iostream>

using namespace std;
char square[9] = {'0','1','2','3','4','5','6','7','8'};
int checkwin()
{
    for(int i=0;i<=6;i+=3){
        if(square[i]==square[i+1] && square[i+1]==square[i+2]){
            return square[i]=='X' ? 1: 2;
        }
    }
    for(int i=0;i<=2;i++){
        if(square[i]==square[i+3] && square[i+3]==square[i+6]){
            return square[i]=='X' ? 1: 2;
        }
    }
    if(square[0]==square[4] && square[4]==square[8]){
        return square[0]=='X'? 1 : 2;
    }
    if(square[2]==square[4] && square[4]==square[6]){
        return square[4]=='X'? 1 : 2;
    }
    return 0;
}

void mark(int player, int box)
{
 if (player == 1 )
 {

  square[box] = 'X';
 }
 else
  square[box] = 'Y';
}

void display()
{
  for(int i=0;i<9;i++)
  {
   cout<< square[i] << "\t" ;
    if (i == 2  i== 5  i==8)
     cout<<"\n"; 
}
}
int main()
{
  int player1 = 1, player2 =2 ;
  
  int box, result = 0, flag = 0;
  bool started=false;
  for(int i=1;i<5;i++)
 {
     if(!started){
         display();
         started=true;
     }
  cout<< "\n Player " << player1 << " Enter the Box \n";
  cin>> box;
  while(box <0 || box >8){
      cout<<"Invalid. Enter again \n";
      cin>>box;
  }
  mark( player1, box);
  display();

  result =checkwin(); 
  if (result == 1 )
  { cout<<"\n Congratualtions! player " << player1 << " has Won ";
   flag = 1;   
   break;
  }
  else
  if (result == 2 )
  { cout<<"\n Congratualtions! player " << player2 << " has Won ";
   flag = 1;   
   break;
  }

  cout<< "\n Player " << player2 << "Enter the Box \n";
  cin>> box;
  while(box <0 || box >8){
      cout<<"Invalid. Enter again \n";
      cin>>box;
  }
  mark ( player2, box);
  display();
  
  result =checkwin(); 
  if (result == 1 )
  { cout<<"\n Congratualtions! player " << player1 << " has Won ";
   flag = 1;
   break;
  }
  else
  if (result == 2 )
  { cout<<"\n Congratualtions! player " << player2 << " has Won ";
   flag = 1;
   break;
  }
}
  if (flag == 0 )
  cout<<" \n Sorry, The game is a draw ";
 
 return 0;
}
