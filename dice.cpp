//Definitions for Dice class, used in Character class as member variables

#include "dice.hpp"

/*Constructs a Dice Object with one die of max 6 pips*/
Dice::Dice(){

  this->num_dice = 0;
  this->sides = 0;
  srand(time(0));
}

/*Constructs a Dice object with num_dice die of max sides pips*/
Dice::Dice(int num_dice, int sides){

  this->num_dice = num_dice;
  this->sides = sides;
}

/*Rolls all dice in Dice object, and returns a value between
  1 * num_dice and num_dice*sides */
int Dice::roll_dice(){

  int rolled = 0;
  
  for(int i = 0; i < this->num_dice; i++){
    
    rolled += (rand()%sides + 1);
  }

  return rolled;
}
   
