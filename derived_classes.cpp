#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

#include "derived_classes.hpp"

//Basic Types of Characters
enum {GOBLIN, REPTILE_PEOPLE, BARBARIAN, BLUE_MEN};

Goblin::Goblin():Character(){

  this->attack = Dice(2, 6);
  this->defense = Dice(1, 6);
  this->armor = 3;
  this->strength = 8;
  this->char_type = GOBLIN;
  this->name = "Goblin";

}
  

Goblin::Goblin(string name):Character(){

  this->attack = Dice(2, 6);
  this->defense = Dice(1, 6);
  this->armor = 3;
  this->strength = 8;
  this->name = name;
  this->char_type = GOBLIN;

}

int Goblin::defend(){

  /*10% chance of fulling dodging the attack*/
  if(rand()%10 == 0){
    cout << this->name << 
      " has turned invisible and dodged the attack!" << endl;
    cout << this->name << " will take no damage this turn." << endl;
    return 100; //Arbitrary large # otherwise impossible to return
  }
  else{
    return Character::defend();
  }
}
  

void Goblin::take_damage(int attacked, int defended, int attack_type){
  
  srand(time(0));
  int damage_taken;
  
  /*If attack dodged*/
  if(defended == 100){
    return;
  }
  /*30% chance to use anti-venom against Reptile People*/
  if(attack_type == REPTILE_PEOPLE){
    int anti_ven = rand()%10;
    if(anti_ven >= 0 && anti_ven <= 2){
      cout << this->name <<" has used anti-venom!" << endl;
      damage_taken = (attacked/2) - defended;
    }
    else{
      damage_taken = attacked - defended;
    }
  }
  else{
    damage_taken = attacked - defended;
  }
  if(damage_taken > 0){
    cout << "Damage taken: " << damage_taken << endl;
    this->strength -= damage_taken;
  }
}

void Goblin::print(){

  cout << "GOBLIN:" << endl
       << "Strength: " << this->strength << endl
       << "Armor: " << this->armor << endl
       << "Defense: 1 to 6" << endl
       << "Attack: 2 to 12" << endl
       << "Special powers: 10% chance to dodge attack. "
       << "30% chance to use anti-venom against all Reptile People." << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

}
  
//int damage_taken;
  

ReptilePeople::ReptilePeople(): Character(){

  this->strength = 18;
  this->name = "Reptile Man";
  this->char_type = REPTILE_PEOPLE;

}



ReptilePeople::ReptilePeople(string name): Character(){

  this->strength = 18;
  this->name = name;
  this->char_type = REPTILE_PEOPLE;

}

void ReptilePeople::print(){

  cout << "Reptile Man:" << endl
       << "Strength: " << this->strength << endl
       << "Has no direct attack or defense, but evolves into a " << endl
       << "Dragon or Poison Lizard on every turn" << endl
       << "Takes twice as much damage against other Reptiles" << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

}

int ReptilePeople::evolve(){

  int evolved = rand()%2;
  if(evolved == 0){
    cout << this->name << " has evolved into a PoisonLizard for this turn!" 
	 << endl;
  }
  else if(evolved == 1){
    cout << this->name << " has evolved into a Dragon for this turn" << endl;
  }
  return evolved;
}

int ReptilePeople::give_attack(){

  int attacked;
  int evolved = evolve();
  if(evolved == 0){ //Evolve to PoisonLizard
    PoisonLizard poison = PoisonLizard();
    poison.print();
    attacked =  poison.give_attack();
  }
  else if(evolved == 1){ //Evolve to Dragon
    Dragon drag = Dragon();
    drag.print();
    attacked = drag.give_attack();
  }
  return attacked;
}

int ReptilePeople::defend(){

  int defended;
  int evolved = evolve();
  if(evolved == 0){ //Evolve to PoisonLizard
    PoisonLizard poison = PoisonLizard();
    poison.print();
    defended =  poison.defend();
  }
  else if(evolved == 1){ //Evolve to Dragon
    Dragon drag = Dragon();
    drag.print();
    defended =  drag.defend();
  }
  return defended;
}


void ReptilePeople::take_damage(int attacked, int defended, int attack_type){

  /*Takes twice as much damage against other Reptiles*/
  if(attack_type == REPTILE_PEOPLE){
    attacked *= 2;
  }
  Character::take_damage(attacked, defended, attack_type);
}

Dragon::Dragon(): ReptilePeople(){

  this->attack = Dice(3, 10);
  this->defense = Dice(1, 6);
  this->armor = 12;
}

int Dragon::give_attack(){

  return Character::give_attack();
}

int Dragon::defend(){
  
  return Character::defend();
}

void Dragon::print(){

  cout << "DRAGON:" << endl
       << "Armor: " << this->armor << endl
       << "Defense: 1 to 6" << endl
       << "Attack: 3 to 30" << endl
       << "Evolves back to Reptile Person after defending or attacking."
       << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

PoisonLizard::PoisonLizard() : ReptilePeople(){

  this->attack = Dice(1, 6);
  this->defense = Dice(3, 6);
  this->armor = 0;
}

int PoisonLizard::give_attack(){

  return Character::give_attack();
}

int PoisonLizard::defend(){

  return Character::defend();
}

void PoisonLizard::print(){

  cout << "Poison Lizard:" << endl
       << "No Armor" << endl
       << "Defense: 3 to 18" << endl
       << "Attack: 1 to 6" << endl
       << "Evolves back to Reptile Person after defending or attacking."
       << endl;
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

Barbarian::Barbarian():Character(){

  this->attack = Dice(2, 6);
  this->defense = Dice(2, 6);
  this->armor = 0;
  this->strength = 12;
  this->name = "Barbarian";
  this->char_type = BARBARIAN;

}


Barbarian::Barbarian(string name):Character(){

  this->attack = Dice(2, 6);
  this->defense = Dice(2, 6);
  this->armor = 0;
  this->strength = 12;
  this->name = name;
  this->char_type = BARBARIAN;

}

bool Barbarian::turn_to_rock(){
  
  if(rand()%2 == 1){
    cout << this->name << " has turned into a Rock Barbarian for this turn!"
	 << endl;
    return true;
  }
  return false;

}
 
int Barbarian::give_attack(){

  int attack_damage;
  /*50% chance to turn to Rock Barbarian*/
  bool rock = turn_to_rock();
  if(rock){
    RockBarbarian rock = RockBarbarian();
    rock.print();
    attack_damage = rock.give_attack();
  }
  else{
    attack_damage = Character::give_attack();
  }
  return attack_damage;
}

int Barbarian::defend(){

  int defended;
  bool rock = turn_to_rock();
  if(rock){
    RockBarbarian rock = RockBarbarian();
    rock.print();
    defended = rock.defend();
  }
  else{
    defended = Character::defend();
  }
  return defended;
}

void Barbarian::print(){

  cout << "BARBARIAN:" << endl
       << "No Armor" << endl
       << "Strength: " << this->strength << endl
       << "Defense: 2 to 12" << endl
       << "Attack: 2 to 12" << endl
       << "50% chance to turn into a Rock Barbarian on every turn."
       << endl;

  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

RockBarbarian::RockBarbarian() : Barbarian(){

  this->attack = Dice(1, 10);
  this->defense = Dice(1, 6);
  this->armor = 10;
}

int RockBarbarian::give_attack(){
  
  //cout << "Rock Barbarian attack" << endl;
  int rolled = this->attack.roll_dice();
  return rolled + 5;
}

int RockBarbarian::defend(){
  return Character::defend();
}

void RockBarbarian::print(){

  cout << "ROCK BARBARIAN:" << endl
       << "Armor:" << this->armor << endl
       << "Defense: 2 to 12" << endl
       << "Attack: 5 to 15" << endl
       << "Turns back into a regular Barbarian after attacking or defending."
       << endl;

  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

BlueMen::BlueMen():Character(){

  this->attack = Dice(2, 10);
  this->defense = Dice(3, 6);
  this->armor = 3;
  this->strength = 12;
  this->name = "Blue Man";
  this->char_type = BLUE_MEN;
}

BlueMen::BlueMen(string name):Character(){

  this->attack = Dice(2, 10);
  this->defense = Dice(3, 6);
  this->armor = 3;
  this->strength = 12;
  this->name = name;
  this->char_type = BLUE_MEN;
}

void BlueMen::print(){

  cout << "BLUE MAN:" << endl
       << "Armor:" << this->armor << endl
       << "Strength: " << this->strength << endl
       << "Defense: 3 to 18" << endl
       << "Attack: 2 to 20" << endl;

  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}
