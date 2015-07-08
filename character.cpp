//Definitions for Character class. All functions inherited by Goblin, 
//Barbarian, ReptilePeople, and BlueMen classes

#include "character.hpp"

//Returns int representing attack_damage
int Character::give_attack(){

  int rolled = this->attack.roll_dice();
  cout << this->name << " has dealt " << rolled << " damage!" << endl;
  return rolled;
}

//Returns int representing total defense, including armored defense
int Character::defend(){

  int rolled =  this->defense.roll_dice();
  cout << this->armor << " damage deflected with armor!" << endl;
  cout << rolled << " damage defended!" << endl;
  rolled += this->armor;
  cout << this->name << " blocked " << rolled << " this turn!" << endl;
  return rolled;
}

//Removes strength based on attacked and damaged
void Character::take_damage(int attacked, int defended, int attack_type){
  
  int damage_taken = attacked - defended;
  
  if(damage_taken > 0){
    cout << "Damage taken: " << damage_taken << endl;
    this->strength -= damage_taken;
  }
}

int Character::get_strength() const{
  
  if(this->strength > 0){
    return this->strength;
  }
  else{
    return 0;
  }
}

int Character::get_armor() const{

  return this->armor;
}

string Character::get_name(){

  return this->name;
}

void Character::set_name(string name){

  this->name = name;
}

int Character::get_type() const{

  return this->char_type;
}

ostream& operator<<(ostream& outs, const Character& monster){

  outs << monster.name;
  return outs;
}
