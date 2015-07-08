#ifndef PFISTERL_DERIVED_CLASSES_HPP
#define PFISTERL_DERIVED_CLASSES_HPP

#include "character.hpp"

class Goblin: public Character{

public:

  Goblin();

  Goblin(string name);
  //Creates a Goblin with;
  //Strength: 8, Armor: 3
  //AttackDice: 2, 6 sided
  //DefenseDice: 1, 6 sided

  virtual ~Goblin(){};
  
  int defend();
  /*10% chance to dodge attack, otherwise defends as normal*/

  void print();
  /*Prints details of Class*/

  void take_damage(int attacked, int defended, int attack_type);
  /*30% chance to only take 50% attack from all ReptilePeople
    otherwise takes damage as normal*/

};


class ReptilePeople : public Character{

public:

  ReptilePeople();

  ReptilePeople(string name);
  //Creates a ReptilePeople with:
  //Strength: 18

  virtual ~ReptilePeople(){};

  int evolve();
  //Returns either 0 or 1. If 0 evolves to a PoisonLizard
  //If 1 evolves to a Dragon

  int give_attack();
  //Evolves to either a Dragon or PoisonLizard and executes that attack
  int defend();
  //Evolves to either a Dragon or PoisonLizard and executes that defense

  void take_damage(int attacked, int defended, int attack_type);
  //Takes 50% damage against REPTILE_PEOPLE

  void print();
  //Prints details of class
  
};

class Dragon : public ReptilePeople{

public:
  
  Dragon();
  //Evolves directly from ReptilePeople
  //Armor: 12
  //AttackDice: 3, 6 sided
  //DefenseDice: 1, 6 sided
  
  virtual ~Dragon(){};
  
  int defend();
  //Executes normal character attack using dice
  int give_attack();
  //Executes normal character attack using dice
  void print();
  //Prints details of class
};

class PoisonLizard : public ReptilePeople{

public:
  PoisonLizard();
  //Evovles directly from ReptilePeople
  //No Armor
  //AttackDice: 1, 6 sided
  //DefenseDice: 3, 6 sided

  virtual ~PoisonLizard(){};
  int defend();
  //Executes normal character attack using dice
  int give_attack();
  //Executes normal character attack using dice

  void print();
  //Prints detials of class
};


class Barbarian: public Character{

public:
  
  Barbarian();

  Barbarian(string name);
  //Creates a Barbarian with:
  //12 Strength, 0 Armor
  //2 6sided Attack Dice, 2 6sided Defense Dice

  virtual ~Barbarian(){};

  bool turn_to_rock();
  //Returns true if will turn to RockBarbarian this turn
  int give_attack();
  //If turn_to_rock() is true, executes RockBarbarian attack, otherwise regular
  int defend();
  //If turn_to_rock() is true, executes RockBarbarian defense, otherwise regular

  void print();
  //Prints details of class


};

class RockBarbarian: public Barbarian{

public:
  RockBarbarian();
  //Evovles directly from Barbarian
  //Armor: 10
  //Defense: 2, 6 sided dice
  //Attack: 1, 10 sided dice + guarenteed 5 attack
  
  virtual ~RockBarbarian(){};

  int give_attack();
  //Rolls a dice for 1 to 10 damage, then adds 5.
  int defend();
  //Rolls a dice for 2 to 12 defense
  
  void print();
  //Prints details of class
};

class BlueMen : public Character{

public:

  BlueMen();

  BlueMen(string name);
  //Creates a BlueMen with:
  //Strength: 12, Armor:3
  //AttackDice: 2, 10 sided
  //DefenseDice: 3, 6 sided

  virtual ~BlueMen(){};

  void print();
  //Prints details of the class

};

#endif
