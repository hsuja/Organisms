/***********************************************************************
 * Program filename: hsu_Ant.hpp
 * Author: Jason Hsu
 * Date: 2/23/14
 * Description: Header file for Ant class
 * ********************************************************************/

#ifndef HSU_ANT_HPP
#define HSU_ANT_HPP

#include "hsu_Organism.hpp"
#include <string>

using std::string;

class Ant : public Organism{

     public:

	  // Constructors
	  Ant();
	  Ant(int r, int c);

	  /************************************************************
	   * Function: move
	   * Description: Has ant move randomly up, down, left, or right if
	   *              space available. Otherwise Ant stays in position.
	   * Parameters: 20x20 grid of Organism pointers, number of rows
	   * Pre-condition: If element in grid is empty, it is NULL 
	   * Post-condition: Ant moves to new position or stays
	   * **********************************************************/
	  void move(Organism* grid[][20], int numRows);
	  
	  /************************************************************
	   * Function: breed
	   * Description: Ant creates a new adjacent Ant if survived 3 
	   *              timesteps. Ant prefers to create new Ant to left
	   *              and working clockwise. If no space, then doesn't 
	   *              breed. Ant must survive another 3 timesteps to 
	   *              breed again if offspring produced.
	   * Parameters: 20x20 grid of Organism pointers, number of rows
	   * Pre-condition: If element in grid is empty, it is NULL 
	   * Post-condition: Ant creates adjacent Ant or does not
	   * **********************************************************/
	  void breed(Organism* grid[][20], int numRows);

	  /***********************************************************
	   * Function: getSpecies
	   * Description: Returns "Ant"
	   * Parameters: none
	   * Pre-condition: none
	   * Post-conditino: Returns "Ant"
	   * *********************************************************/
	  string getSpecies();


     protected:

	  string species; // holds the species: Ant

};

#endif
