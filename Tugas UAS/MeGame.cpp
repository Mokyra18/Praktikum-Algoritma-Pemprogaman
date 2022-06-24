
#include <iostream> //in and output libary 
#include <cmath> // math libary for rand 
#include <time.h> // time libary for time(NULL)
#include <stdlib.h>

using namespace std;

struct character
	{
		int posX ; 
		int posY ; 
		char symbol;
		int hp;
	}player;// struct for the player 

struct enemies
	{
		int posX;
		int posY;
		char enemy_symbol;
	};// struct for the enemies 

void player_hit()
	{
		player.posX = 1;
		player.posY =1;
		player.hp --;
	}// function for when the player hits an enemy

int main ()
{
	
	enemies enemy_horizontal = {13, 9, 'H'}; //placing enemy_horizontal at location [9][13] and gives it the sign H
	enemies enemy_vertical = { 11 , 9, 'V'};
	enemies enemy_jump = {1, 15, 'J'};


	const char HEIGHT = 18, WIDTH = 18; // the maze width and height 
	bool update = false; // boolean to control when the map needs to be updated 
	char move_key = 'd';

	player.posX = 1;
	player.posY = 1;
	player.symbol = 'O';

	player.hp = 3; // players different attributes 


	unsigned char maze[WIDTH][HEIGHT] = 
	{
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#',' ','#',' ','#','#',
		'#',' ',' ','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ', 
		'#',' ',' ','#',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',
		'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',
		'#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','#',
		'#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',
		'#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#',
		'#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ','#','#',
		'#',' ','#',' ',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#','#', 
		'#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#',
		'#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ','#','#','#',' ','#',
		'#',' ','#',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#',
		'#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#','#',' ',' ','#','#','#','#',' ','#',' ',' ','#','#',' ','#','#',
		'#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ','#','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	};
	cout << "press (d) (a) (w) or (s) and then return to start the game\n";
	cout << "presse (Q) then return to quit the game\n";

	
	
	while (move_key !='q') // as long as move_key is not q then this loop will run and thereby everysingle little thing, which is happening in the maze
{
	
srand(time(NULL)); // random seed based on some time thingy 
int random_move = rand() %2 +1  ; // random number between 1 and 2 

cin >> move_key; 
update = true;	// map updates 

	if (update == true) // if map is updated, then the enemies will be printed onto the map and the player 
						// the maze will be created by a nested for loop, but the x and y are at the wrong places in order to create the map I have "painted" with #
						// the health will be outputted, so the gamer can see the life of the "player"
						// update stopped
	{
	system("CLS");

	maze[enemy_horizontal.posX][enemy_horizontal.posY] = enemy_horizontal.enemy_symbol;
	maze[enemy_vertical.posX][enemy_vertical.posY] = enemy_vertical.enemy_symbol;
	maze[enemy_jump.posX][enemy_jump.posY] = enemy_jump.enemy_symbol;
	
	maze[player.posX][player.posY] = player.symbol;	
		

	for(int y=0;y<HEIGHT;y++)
	{
		cout << endl;
	for(int x=0;x<WIDTH;x++)
	{
		cout << maze[x][y];
	}
	}
	cout << endl << endl << "    health: " << player.hp << endl << "________\n \n";
	update = false;
	}
	
	switch (move_key) // different key pressed in order to move the player and to see if the player collides with a # or an enemy 
					// it will be printed out the "player's" location, because the game are asynchron
					// it will also be printed if the player hits a wall 
	{
		case 'w':
			update = true;
		if (maze[player.posX][player.posY -1] != '#')
		{
			maze[player.posX][player.posY] = ' '; 
			player.posY --;

			if ( maze[player.posX ][player.posY ] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY ] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY ] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
	   }
		else 
			cout << "  you hit a wall";
		break;
	
		case 's':
			update = true;
		if (maze[player.posX][player.posY +1] != '#')
		{
			maze[player.posX][player.posY] = ' ';
			player.posY ++;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  you hit a wall";
		break;

		case 'a':
			update = true;
		if (maze[player.posX -1][player.posY] != '#')
		{
			maze[player.posX][player.posY] = ' '; 
			player.posX --;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  you hit a wall";
		
		break;

		case 'd':
			update = true;
			if ( maze[player.posX +1][player.posY] != '#')
		{	
			maze[player.posX][player.posY] = ' '; 
			player.posX ++;

			if ( maze[player.posX ][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
				maze[player.posX ][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
			{
				player_hit();
			}
			
			cout << player.posX << " " << player.posY << endl;
		}
		else 
			cout << "  you hit a wall";
		break;
	}

		switch (random_move) // the horizontal moving enemy H moves in a random pattern do to the rand() function and thereby making him unpredictable.
		{
		case 1:

	
	if 
			(maze[enemy_horizontal.posX +1][enemy_horizontal.posY] != '#')
	{
		maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
		enemy_horizontal.posX ++;
	}
	
	break;


		case 2:	
	if 
		(maze[enemy_horizontal.posX -1][enemy_horizontal.posY] != '#')
	{
		maze[enemy_horizontal.posX][enemy_horizontal.posY] = ' ';
		enemy_horizontal.posX --;
	}

	break;
	}

		if (maze[enemy_vertical.posX][enemy_vertical.posY +1] != '#')// the vertical moving enemy he returns to his stsarting point if he híts a wall, seeing that he only moves in one simple pattern (downwards) he is predictable.
	{
		maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
		enemy_vertical.posY ++;
	}
	else if 
		(maze[enemy_vertical.posX][enemy_vertical.posY -5] != '#')
	{
		maze[enemy_vertical.posX][enemy_vertical.posY] = ' ';
		enemy_vertical.posY -=6;
	}


	if (maze[enemy_jump.posX +2][enemy_jump.posY] != '#')// this enemy jumps every seconf tile over, so you have to be aware of where he is and the location there have been printed out in order to avoid him.
														// he also returns to his starting point when he can't get any further do to #                                                                           
	{
		maze[enemy_jump.posX][enemy_jump.posY] = ' ';
		enemy_jump.posX += 2;
	}
	else if 
		(maze[enemy_jump.posX -14][enemy_jump.posY] != '#')
	{
		maze[enemy_jump.posX][enemy_jump.posY] = ' ';
		enemy_jump.posX -= 14;
	}

	if (player.hp == 0)// when the player rund out of hp the ganmes stops and print out you have lost the game.
	{                    
		move_key = 'q';
		cout <<" you have lost the game \n";
	}

	if (player.posY == 17)// when the player reach the bottom line he winsd the game 
	{
		cout << "\n congrats!!! you have won the game\n"; 
	}

}// while loop ends here. 
	return 0;

}
