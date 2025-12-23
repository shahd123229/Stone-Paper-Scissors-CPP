
#include <iostream>
#include<cstdlib>
using namespace std;

enum Choices { Stone=1, Paper=2, Scissors=3};

struct Results
{
 int Round;
 int PlyChoice;
 int CompChoice;
 int PlyWins;
 int CompWins;
 int Draws;
 string Round_Winner;
 string Winner;

};


int random(int from, int to)
{
	return rand()%(to-from+1)+from;
}

void Reset_Game(Results &Game)
{
    system("color 0F");
	Game.PlyWins=0;
	Game.CompWins=0;
	Game.Draws=0;
}





int N_Round(Results &Game)
{

do{
	cout<<"How Many Round To Play 1:10?\n";
	cin>>Game.Round;
}while(Game.Round<1 || Game.Round>10);

return Game.Round;
}

string Check_Choice(int choice){

	 switch (choice)
	 {
	 	case Choices::Stone:
	 	return "Stone";

	 	case Choices::Paper:
	 	return "Paper";

	 	case Choices::Scissors:
	 	return "Scissors";
	 }
}



void Round_Winner(Results &Game)
{
	 if(Game.PlyChoice==Game.CompChoice)
	 {
	 	Game.Draws++;
	 	system("color 6F");
	 	Game.Round_Winner="No Winner";
	 }
	 else if((Game.CompChoice==1 && Game.PlyChoice==3) || (Game.CompChoice==2 && Game.PlyChoice==1) || (Game.CompChoice==3 && Game.PlyChoice==2 ))
      {
      	Game.CompWins++;
      	 system("color 4F");
      	 cout<<"\a";
      	 Game.Round_Winner="Computer";
      }

      	 else
      	 {
      	Game.PlyWins++;
      	 system("color 2F");
      	 Game.Round_Winner="Player";
      	 }
}


void Game_Results(Results Game)
{
	if(Game.PlyWins>Game.CompWins)
	Game.Winner="Player";

	else if(Game.PlyWins<Game.CompWins)
		Game.Winner="Computer";

		else
			Game.Winner="No Winner";


	cout<<"\n\n				___________________________________________________";
	cout<<"\n\n				++++++++ G a m e  O v e r ++++++++				";
	cout<<"\n\n				______________________________________________________\n\n";

	cout<<"\n\n				________________ [Game Results] ____________________\n\n";

	cout<<"				Game Rounds : "<<Game.Round<<endl;
	cout<<"				Player Won Times : "<<Game.PlyWins<<endl;
	cout<<"				Computer Won Times : "<<Game.CompWins<<endl;
	cout<<"				Draw Times : "<<Game.Draws<<endl;
	cout<<"				Final Winner : "<<Game.Winner;

	cout<<"\n\n				_______________________________________________________\n\n";
}



void Round_Results(Results &Game, int round_n)
{
          Round_Winner(Game);

	cout<<"\n\n____________________Round["<<round_n<<"]____________________\n\n";
	cout<<"Player Choice : "<<Check_Choice(Game.PlyChoice)<<endl;
	cout<<"Computer Choice : "<<Check_Choice(Game.CompChoice)<<endl;
	cout<<"winner : "<<Game.Round_Winner;
	cout<<"\n\n________________________________________________\n\n";
}




void Start_Round(Results &Game)
{

	for(int i=1; i<=Game.Round; i++)
	{

     cout<<"Round ["<<i<<"] Begins : \n\n";
     cout<<"Your choice : [1]:stone  [2]:paper  [3]:scissors ?\n";
     cin>>Game.PlyChoice;
     Game.CompChoice=random(1,3);
     Round_Results(Game, i);
	}}




bool Again()
{

	char Answer;

	cout<<"\n				Do You Want To Play Again Y/N?\n";
	cin>>Answer;
	if(Answer=='y' || Answer=='Y')
	  return true;
	  else
	  return false;
}





void StartGame(Results Game)
{

do{
      system("cls");

      Reset_Game(Game);

      Game.Round=N_Round(Game);

	Start_Round(Game);

	Game_Results(Game);


}while(Again());


cout<<endl<<endl<<"\t\tSEE YOU SOON\n";



}


int main()
{

Results Game;

StartGame(Game);

return 0;
}
