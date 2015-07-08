/*Contains Declaration for class Dice, used in Character class type to
  determine defense, attack dealt*/

#ifndef PFISTERL_DICE_HPP
#define PFISTERL_DICE_HPP

#include <cstdlib>
#include <ctime>

class Dice
{

public:
  Dice();
  Dice(int num_dice, int sides);
  int roll_dice();
  //Returns a random int based on num_dice and sides
  ~Dice(){/*Intentionally Blank*/}

private:
  int num_dice;
  int sides;

};

#endif
