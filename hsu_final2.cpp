/*********************************************************************
 * Program filename: hsu_final2.cpp
 * Author: Jason Hsu
 * Date: 3/17/14
 * Description: Simulates interaction between Doodlebugs(predator) and 
 * 		Ants(prey) in 20x20 grid. Ants move randomly and breed after
 * 		3 timesteps. Doodlebugs eat an adjacent Ant or move if none.
 * 		Doodlebugs breed every 8 timesteps and starve if they don't
 * 		eat an ant within 3 timesteps.
 * Input: User hits ENTER key to execute next timestep
 * Output: Ants printed to screen as "O" and Doodlebugs as "X". The result
 *         of each timestep is printed to the screen.
 * ******************************************************************/

#include "hsu_Organism.hpp"
#include "hsu_Ant.hpp"
#include "hsu_Doodlebug.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::random_shuffle;

/***************************************************************
 * Function: fillWithNull
 * Description: Fills 20x20 grid with null pointers
 * Parameters: 20x20 array of Organism pointers, number of rows
 * Pre-conditions: n/a
 * Post-conditions: 20x20 array is full of null pointers
 * ************************************************************/
void fillWithNull(Organism* grid[][20], int numRows);

/***************************************************************
 * Function: initializeGrid
 * Description: Initializes 20x20 grid with 100 Ants and 5 Doodlebugs
 * Parameters: 20x20 array of Organism pointers, number of rows
 * Pre-conditions: n/a
 * Post-conditions: 20x20 array filled with pointers to 100 Ants and 
 *                  5 Doodlebugs
 * ************************************************************/
void initializeGrid(Organism* grid[][20], int numRows);

/***************************************************************
 * Function: printGrid
 * Description: Prints values of 20x20 grid
 * Parameters: 20x20 array of Organism pointers, number of rows
 * Pre-conditions: n/a
 * Post-conditions: Prints to screen the 20x20 grid
 * ************************************************************/
void printGrid(Organism* grid[][20], int numRows);

/***************************************************************
 * Function: advanceTime
 * Description: Goes through 20x20 grid. Each non NULL pointer is placed in
 *              a vector randomVec. randomVec is shuffled into random order 
 *              and then iterated through. All Organisms move (if 
 *              appropriate), then all Organisms breed (if appropriate), 
 *              then all Doodlebugs starve(if appropriate). Any Organisms 
 *              that have died are then deleted.
 * Parameters: 20x20 array of Organism pointers, number of rows
 * Pre-conditions: If an element of the array is not pointing to an Ant or
 *                 Doodlebug, then it is pointing at NULL.
 * Post-conditions: The grid has gone through the next timestep.
 * ************************************************************/
void advanceTime(Organism* grid[][20], int numRows);

int main(){

     string cont;
     Organism* world[20][20];	//Create 20x20 grid of Organism pointers
   
     srand(time(NULL));		//Seed random number generator
     initializeGrid(world,20);  //Fill grid with Organisms and NULL pointers

     do{
     
	  printGrid(world, 20);
	  advanceTime(world, 20);

	  cout << "Press ENTER key to continue.  Enter 'q' to quit. ";
	  getline(cin, cont);

     }while(cont != "q" && cont != "Q");

     return 0;

}

void fillWithNull(Organism* grid[][20], int numRows){

     for(int i = 0; i < numRows; i++){
	  for(int j = 0; j < 20; j++){
	       grid[i][j] = NULL;
	  }
     }
}

void initializeGrid(Organism* grid[][20], int numRows){

     fillWithNull(grid, numRows);

     // Fill grid with 100 Ants
     for(int i = 0; i < numRows; i++){
	  for(int j = 0; j < 20; j++){

	       if(i % 2 == 0){	// Fill in rows with even index
		  if((j + 1) % 4 == 0){

		       grid[i][j] = new Ant(i, j);

		  }
	       }else{		// Fill in rows with odd index
		  if((j + 2) % 4 == 0){

		       grid[i][j] = new Ant(i, j);

		  }
	       }
	  }
     }

     // Fill grid with 5 Doodlebugs
     grid[0][0] = new Doodlebug(0,0);
     grid[19][19] = new Doodlebug(19,19);
     grid[6][5] = new Doodlebug(6,5);
     grid[8][17] = new Doodlebug(8,17);
     grid[15][12] = new Doodlebug(15,12);

}

void printGrid(Organism* grid[][20], int numRows){
     
     for(int i = 0; i < numRows; i++){

	  for(int j = 0; j < 20; j++){

	       if(grid[i][j] == NULL){
		    cout << " ";
	       }else if((*grid[i][j]).getSpecies() == "Ant"){
		    cout << "O";
	       }else if((*grid[i][j]).getSpecies() == "Doodlebug"){
		    cout << "X";
	       }
	  }

	 cout << endl;
     
     }
} 

void advanceTime(Organism* grid[][20], int numRows){

     vector<Organism*> randVec;

     //Fill vector with Organism pointers
     for(int i = 0; i < numRows; i++){
	  for(int j = 0; j < 20; j++){

	       if(grid[i][j] != NULL){
		    randVec.push_back(grid[i][j]);
	       }
	  }
     }

     //Randomly shuffle order of Organism pointers
     random_shuffle(randVec.begin(), randVec.end());

     //Iterate through vector and call move on each living Organism
     for(int i = 0; i < randVec.size(); i++){
	  
	  if(!randVec[i]->hasDied()){
	       randVec[i]->move(grid, 20);
	  }
     }

     //Randomly shuffle order of Organism pointers
     random_shuffle(randVec.begin(), randVec.end());

     //Iterate through vector and call breed on each living Organism
     for(int i = 0; i < randVec.size(); i++){

	  if(!randVec[i]->hasDied()){
	       randVec[i]->breed(grid, 20);
	  }
     }

     //Iterate through vector and call starve on Doodlebugs
     for(int i = 0; i < randVec.size(); i++){

	  if(randVec[i]->getSpecies() == "Doodlebug"){
	       randVec[i]->starve(grid, 20);
	  }
     }

     // Delete eaten Ants and starved Doodlebugs.
     // (These were already removed from the grid by
     //  Doodlebug::move and Doodlebug::starve)
     for(int i = 0; i < randVec.size(); i++){
	  
	  if(randVec[i]->hasDied()){
	       delete randVec[i];
	       randVec[i] = NULL;
	  }
     }
}
    
