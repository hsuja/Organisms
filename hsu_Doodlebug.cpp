/*************************************************************************
 * Program filename: hsu_Doodlebug.cpp
 * Author: Jason Hsu
 * Date: 3/17/14
 * Description: Implementation file for Doodlebug class
 * **********************************************************************/

#include "hsu_Doodlebug.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;

Doodlebug::Doodlebug() : Organism(){

     species = "Doodlebug";
     stepsNotEaten = 0;

}

Doodlebug::Doodlebug(int r, int c) : Organism(r,c){
     
     species = "Doodlebug";
     stepsNotEaten = 0;

}
    
void Doodlebug::move(Organism* grid[][20], int numRows){

     int rowUp = row - 1;
     int rowDown = row + 1;
     int colLeft = col - 1;
     int colRight = col + 1;

     // Eat Ant to left
     if(colLeft >= 0 && 
	grid[row][colLeft] != NULL && 
	(*grid[row][colLeft]).getSpecies() == "Ant"){
	  
	  grid[row][colLeft]->setDied(true);
	  grid[row][colLeft] = grid[row][col];
	  grid[row][col] = NULL;
	  col = colLeft;
	  moved = true;
	  stepsNotEaten = 0;
 
     // Eat Ant above
     }else if(rowUp >= 0 && 
	      grid[rowUp][col] != NULL && 
	      (*grid[rowUp][col]).getSpecies() == "Ant"){
	  
	  grid[rowUp][col]->setDied(true);
	  grid[rowUp][col] = grid[row][col];
	  grid[row][col] = NULL;
	  row = rowUp;
	  moved = true;
	  stepsNotEaten = 0;

     // Eat Ant to right	  
     }else if(colRight < 20 && 
	      grid[row][colRight] != NULL && 
	      (*grid[row][colRight]).getSpecies() == "Ant"){
	  
	  grid[row][colRight]->setDied(true);
	  grid[row][colRight] = grid[row][col];
	  grid[row][col] = NULL;
	  col = colRight;
	  moved = true;
	  stepsNotEaten = 0;

     // Eat Ant below
     }else if(rowDown < 20 && 
 	      grid[rowDown][col] != NULL && 
	      (*grid[rowDown][col]).getSpecies() == "Ant"){
	  
	  grid[rowDown][col]->setDied(true);
	  grid[rowDown][col] = grid[row][col];
	  grid[row][col] = NULL;
	  row = rowDown;
	  moved = true;
	  stepsNotEaten = 0;

     // Move randomly without eating
     }else{
     
	  int direction = rand() % 4;
	  // 0: left
	  // 1: up
	  // 2: right
	  // 3: down

	  switch(direction){
	       
	       // Move left
	       case 0:
		    if(colLeft >= 0 && grid[row][colLeft] == NULL){
			 
			 grid[row][colLeft] = grid[row][col];
			 grid[row][col] = NULL;
			 col = colLeft;
			 moved = true;
		    
		    }
		    break;
	
	       // Move up	    
	       case 1:
		    if(rowUp >= 0 && grid[rowUp][col] == NULL){
			 
			 grid[rowUp][col] = grid[row][col];
			 grid[row][col] = NULL;
			 row = rowUp;
			 moved = true;
		    
		    }
		    break;

	       // Move right
	       case 2:
		    if(colRight < 20 && grid[row][colRight] == NULL){
			 
			 grid[row][colRight] = grid[row][col];
			 grid[row][col] = NULL;
			 col = colRight;
			 moved = true;
		    
		    }
		    break;

               // Move down
	       case 3:
		    if(rowDown < 20 && grid[rowDown][col] == NULL){
			 
			 grid[rowDown][col] = grid[row][col];
			 grid[row][col] = NULL;
			 row = rowDown;
			 moved = true;
		    
		    }
		    break;

	       default:
		    cout << "ERROR: INVALID DIRECTION. Exit program.\n";
		    exit(1);
	  }

	  stepsNotEaten++;

     }

}

void Doodlebug::breed(Organism* grid[][20], int numRows){

     if(stepsNotLucky == 8){
	  
	  int rowUp = row - 1;
	  int rowDown = row + 1;
	  int colLeft = col - 1;
	  int colRight = col + 1;

	  // Breed to the left
	  if(colLeft >= 0 && grid[row][colLeft] == NULL){
	       
	       grid[row][colLeft] = new Doodlebug(row, colLeft);
	       stepsNotLucky = 0;
	  
	  // Breed above
	  }else if(rowUp >= 0 && grid[rowUp][col] == NULL){
	       
	       grid[rowUp][col] = new Doodlebug(rowUp, col);
	       stepsNotLucky = 0;

	  // Breed to the right
	  }else if(colRight < 20 && grid[row][colRight] == NULL){
	       
	       grid[row][colRight] = new Doodlebug(row, colRight);
	       stepsNotLucky = 0;

	  // Breed below     
	  }else if(rowDown < 20 && grid[rowDown][col] == NULL){
	       
	       grid[rowDown][col] = new Doodlebug(rowDown, col);
	       stepsNotLucky = 0;
	  
	  }

     }else{

	  stepsNotLucky++;

     }

}

void Doodlebug::starve(Organism* grid[][20], int numRows){

     if(stepsNotEaten == 3){

	  died = true;
	  grid[row][col] = NULL;

     }
}

string Doodlebug::getSpecies(){

     return species;

}
