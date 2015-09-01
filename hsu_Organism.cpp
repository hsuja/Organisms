/********************************************************************
 * Program filename: hsu_Organism.cpp
 * Author: Jason Hsu
 * Date: 3/17/14
 * Description: Implementation file for Organism class
 * *****************************************************************/

#include "hsu_Organism.hpp"

Organism::Organism(){

     stepsNotLucky = 0;
     moved = false;
     died = false;
     row = -1;
     col = -1;
}

Organism::Organism(int r, int c){
     
     stepsNotLucky = 0;
     moved = false;
     died = false;
     row = r;
     col = c;
}

void Organism::move(Organism* grid[][20], int numRows){

     // Intentionally undefined

}

void Organism::breed(Organism* grid[][20], int numRows){

     // Intentionally undefined

}

void Organism::starve(Organism* grid[][20], int numRows){

     // Intentionally undefined

}

string Organism::getSpecies(){

     // Intentionally undefined

}

/*
int Organism::getAge() const{
     return age;
}*/

bool Organism::hasMoved() const{
     
     return moved;

}

void Organism::setMoved(bool doneMoving){
     
     moved = doneMoving;

}

bool Organism::hasDied() const{

     return died;

}

void Organism::setDied(bool death){

     died = death;

}

