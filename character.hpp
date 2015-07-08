/*Declaration for Character class. Base class for Blue Men, Reptile People,
  Goblin and Barbarian. Full Definition in character.cpp*/

#ifndef PFISTERL_CHARACTER_HPP
#define PFISTERL_CHARACTER_HPP

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

#include "dice.hpp"

class Character
{

public:

  virtual ~Character(){};

  virtual int give_attack();
  //Rolls attack dice to determine damage dealt.

  int defend();
  //Rolls defense dice to determine damage defended.

  virtual void take_damage(int attacked, int defended, int attack_type);
  //Calculates and applies damage taken.

  virtual int get_strength() const;
  //Returns an int representing strength

  int get_armor() const;
  //Returns an int representing armor

  string get_name();
  //Returns a string of player name.
  
  void set_name(string name);
  //Sets this->name to name
  
  virtual int get_type() const;
  //Returns int representing type of character

  virtual void print() = 0;
  //Pure virtual function: prints details of specific Character

  friend ostream& operator<<(ostream& outs, const Character& monster);

protected:
  Dice attack;
  Dice defense;
  int armor;
  int strength;
  string name; //Player Name
  int char_type;

};

#endif
