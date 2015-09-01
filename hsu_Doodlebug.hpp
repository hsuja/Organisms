/***********************************************************************
 * Program filename: hsu_Doodlbug.hpp
 * Author: Jason Hsu
 * Date: 2/23/14
 * Description: Header file for Doodlebug class
 * ********************************************************************/

#ifndef HSU_DOODLEBUG_HPP
#define HSU_DOODLEBUG_HPP

#include "hsu_Organism.hpp"
#include <string>

using std::string;

class Doodlebug : public Organism{

     public:
          
	  // Constructors
	  Doodlebug();
	  Doodlebug(int r, int c);

	  /************************************************************
	   * Function: move
	   * Description: Has Doodlebug move to an adjacent cell with an ant
	   * 		  and eat the ant. It has a preference to eat from
	   * 		  the left and move clockwise. If no adjacent ant, 
	   * 		  then Doodlebug moves randomly up, down, left, or 
	   * 		  right if space available. Otherwise Doodlebug 
	   * 		  stays in position.
	   * Parameters: 20x20 grid of Organism pointers, number of rows
	   * Pre-condition: If element in grid is empty, it is NULL 
	   * Post-condition: Doodlebug moves to new position or stays.
	   *                 Adjacent Ant may be eaten.
	   * **********************************************************/
	  void move(Organism* grid[][20], int numRows);

	  /************************************************************
	   * Function: breed
	   * Description: Doodlebug creates a new adjacent Doodlebug if 
	   * 		  survived 8 timesteps. Doodlebug prefers to create 
	   * 		  new Doodlebug to left and working clockwise. If 
	   * 		  no space, then doesn't breed. Doodlebug must 
	   * 		  survive another 8 timesteps to breed again if
	   * 		  offspring was produced.
	   * Parameters: 20x20 grid of Organism pointers, number of rows
	   * Pre-condition: If element in grid is empty, it is NULL 
	   * Post-condition: Creates adjacent Doodlebug or does not
	   * **********************************************************/
	  void breed(Organism* grid[][20], int numRows);

	  /************************************************************
	   * Function: starve
	   * Description: Doodlebug dies if it has not eaten within 3
	   *  		  timesteps.
	   * Parameters: 20x20 grid of Organism pointers, number of rows
	   * Pre-condition: If element in grid is empty, it is NULL 
	   * Post-condition: Doodlebug removed from grid if it hasn't 
	   * 		     eaten within 3 timesteps
	   * **********************************************************/
	  void starve(Organism* grid[][20], int numRows);

	  /***********************************************************
	   * Function: getSpecies
	   * Description: Returns "Doodlebug"
	   * Parameters: none
	   * Pre-condition: none
	   * Post-conditino: Returns "Doodlebug"
	   * *********************************************************/
	  string getSpecies();

     protected:

	  string species; 
	  int stepsNotEaten; // # timesteps Doodlebug has not eaten
	  
};

#endif
