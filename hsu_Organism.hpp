/**********************************************************************
 * Program filename: hsu_Organism.hpp
 * Author: Jason Hsu
 * Date: 3/17/14
 * Description: Header file for Organism class
 * *******************************************************************/

#ifndef HSU_ORGANISM_HPP
#define HSU_ORGANISM_HPP

#include <string>

using std::string;

class Organism{

     public:

	  // Default constructor
	  Organism();

	  // Constructor
	  Organism(int r, int c);

	  // Virtual move function undefined
	  virtual void move(Organism* grid[][20], int numRows);

	  // Virtual breed function undefined
	  virtual void breed(Organism* grid[][20], int numRows);

	  // Virtual starve function undefined
	  virtual void starve(Organism* grid[][20], int numRows);

	  // Virtual getSpecies function undefined
	  virtual string getSpecies();

	  /************************************************************
	   * Function name: hasMoved
	   * Description: Tells whether an Organism has moved in a timestep
	   * Parameters: n/a
	   * Pre-condition: none
	   * Post-condition: Returns true if Organism has moved. Otherwise
	   * 		     returns false.
	   * **********************************************************/
	  bool hasMoved() const;

	  /************************************************************
	   * Function name: setMoved
	   * Description: Sets the moved member variable to true or false
	   * Parameters: bool
	   * Pre-condition: none
	   * Post-condition: Sets member variable moved to true or false
	   * **********************************************************/
	  void setMoved(bool doneMoving);

	  /************************************************************
	   * Function name: hasDied
	   * Description: Tells whether an Organism has died in a timestep
	   * Parameters: n/a
	   * Pre-condition: none
	   * Post-condition: Returns true if Organism has died. Otherwise
	   * 		     returns false.
	   * **********************************************************/
	  bool hasDied() const;

	  /************************************************************
	   * Function name: setDied
	   * Description: Sets the died member variable to true or false
	   * Parameters: bool
	   * Pre-condition: none
	   * Post-condition: Sets member variable died to true or false
	   * **********************************************************/
	  void setDied(bool death);

     protected:

	  int stepsNotLucky; //# timesteps without breeding
	  bool moved; // whether Organism has moved within a timestep
	  bool died; // whether Organism has died
	  int row; // row position in grid
	  int col; // column position in grid

};

#endif
