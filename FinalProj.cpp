/*Laura Pfister: CS162, Final Project
  Two players each pick a team of Monsters. They can choose from:
  1. Goblin, 2.Barbarian, 3. ReptilePeople, 4. BlueMen
  Each player picks the same quantity of Monsters.
  The Monsters on each team fight each other, in order picked. Winners go back
  into the queue to fight again. The Battle ends when one player runs out of
  Monsters. The First, Second and Third place winners are printed out*/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stack>
using std::stack;

#include <queue>
using std::queue;

#include "character.hpp"
#include "derived_classes.hpp"

#include <climits>
#include <string>

int get_int(int min = 0, int max = INT_MAX);
//Default arguments of min = 0 and max = INT_MAX
//Optional arguments of minimum and maximum integer allowed to be picked
//Asks user for an integer
//Returns the integer if it is an integer in the allowed range.

queue<Character*> add_fighters(int fight_num);
//Requires an integer greater than 2 and less than 10
//Adds fight_num quantity of Characters to a queue and returns that queue
//Characters are picked using pick_character function

Character* pick_character(string initials);
//Requires a string, to modify a unique name for each monster
//Given a menu of Characters, 1.Goblin, 2.Barbarian, 3. ReptilePeople 4.BlueMen
//User picks a corresponding number, function returns that Character

stack<Character*> battle(queue<Character*> player1List, 
			 queue <Character*> player2List); 
//Requires two queue of type Character, queue should be the same size.
//Executes a round of play between the front character of each list 
//adds loser of fight to losers stack, until both queue are empty
//Returns stack of losers

template <typename T1, typename T2>
void play_round(T1& attacker, T2& defender);
//One round of a game, the attacker attacks,
//defender defends, and defender takes damage
//T1 and T2 must be subclass of Character

template <typename T1, typename T2>
void play_game(T1& player1, T2& player2);
//Executes a full game between player1 and player2, until one
//player runs out of strength
//T1 and T2 must be subclass of Character

void winners(stack<Character*> losers);
//Prints first, second, third place winners, given a stack of type Character*

int main(){

  cout << "Welcome to the Battle!" << endl;
  
  cout << "How many monsters on each team?" << endl;
  int monst_num = get_int(2, 10);

  cout << "Player 1, please pick your team." << endl;
  queue<Character*> player1 = add_fighters(monst_num);

  cout << "Player 2, please pick your team." << endl;
  queue<Character*> player2 = add_fighters(monst_num);

  stack<Character*> losers = battle(player1, player2);

  winners(losers);

  return 0;
}

queue<Character*> add_fighters(int fight_num){

  cout << "Please enter your initials" << endl;
  string pinits;
  getline(cin, pinits);

  char monster = '1';
  string new_ints;

  queue<Character*> fighters;

  while(fight_num > 0){

    //Create unique ID for monster
    new_ints = pinits + " Monster" + monster + " ";

    Character* next = pick_character(new_ints);
   
    fighters.push(next);
    
    fight_num--;
    monster++;
  }

  return fighters;

}

Character* pick_character(string initials){;
  
  Character* player;

  //Choice Menu, Also provides Character Stats.
  cout << "What Monster do you want to add to your fighting list?" <<endl;
  cout << "1. Goblin" << endl
       << "2. Barbarian" << endl
       << "3. Reptile People" << endl
       << "4. Blue Men" << endl;
  
  int characterNum = get_int(1,4);

  //Constructs Character of player choice
  switch(characterNum){
  case 1:
    player = new Goblin;
    break;
  case 2:
    player = new Barbarian;
    break;
  case 3:
    player = new ReptilePeople;
    break;
  case 4:
    player = new BlueMen;
    break;
  }
 
  player->set_name(initials + player->get_name());
  return player;
}

int get_int(int min, int max){
  
  int int_ans;
  string str_ans;

  getline(cin, str_ans);

  if(!cin){    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Please enter an integer!" << endl;
    return get_int(min, max);
  }

  if(str_ans == ""){
    cout << "You didn't enter a number!" << endl;
    return get_int(min, max);
  }
  
  for(int i = 0; i < (int)str_ans.length(); i++){
    if(!isdigit(str_ans[i])){
      cout << "That isn't a number!" << endl;
      return get_int(min, max);
    }
  }

  int_ans = stoi(str_ans);
  
  if(int_ans < min || int_ans > max){
    cout << "Please enter a number in the valid range!" << endl;
    return get_int(min, max);
  }
  
  return int_ans;
} 

stack<Character*> battle(queue<Character*> player1List, 
			 queue <Character*> player2List){

  stack<Character*> losers;

  while(!player1List.empty() && !player2List.empty()){
    
    if(player1List.empty()){
      cout << "Player1List empty!" << endl;
    }
    if(player2List.empty()){
      cout << "Player2List empty!" << endl;
    }

    Character* one = player1List.front();
    player1List.pop();
    Character* two = player2List.front();
    player2List.pop();

    play_game(one, two);

    if(one->get_strength() > two->get_strength()){

      losers.push(two);
      player1List.push(one);
    }
    else{
      losers.push(one);
      player2List.push(two);
    }
  }
    
  while(!player1List.empty()){

    Character* character = player1List.front();
    player1List.pop();
    losers.push(character);
  }
  while(!player2List.empty()){

    Character* character = player2List.front();
    player2List.pop();
    losers.push(character);
  }

  return losers;
}


template <typename T1, typename T2>
void play_round(T1& attacker, T2& defender){

  int attacked = attacker->give_attack();
  int defended = defender->defend();

  defender->take_damage(attacked, defended, attacker->get_type());
}

template <typename T1, typename T2>
void play_game(T1& player1, T2& player2){

  int round = 1;
  int attacker = 1; //Used to determine attacker and defender for round
  string unused; //Used for "Press enter key"

  cout << "Player 1: " << player1->get_name() << endl;
  player1->print();
  cout << "Player 2:  " << player2->get_name() << endl;
  player2->print();
  
  cout <<"Press ENTER to start the game!" << endl;
  getline(cin, unused);

  while(player1->get_strength() > 0 && player2->get_strength() > 0){
    
    cout << "Round " << round << endl;

     
    if(attacker == 1){
      play_round(player1, player2);
      attacker = 2;
    }
    else if(attacker == 2){
      play_round(player2, player1);
      attacker = 1;
    }
    
    cout << "END OF ROUND " << round << endl;
     cout << player1->get_name() <<"'s Strength: " << player1->get_strength() << endl;
    cout << player2->get_name() <<"' s Strength: " << player2->get_strength() << endl;

    round++;

    cout << "Press ENTER to go to continue." << endl;
    getline(cin, unused);
  }

  cout << "MATCH OVER" << endl;
  cout << "WINNER: ";
  if(player1->get_strength() > player2->get_strength()){
    
    cout << player1->get_name() << endl;
  }
  else{
    cout << player2->get_name() << endl;
  }
  
}

void winners(stack<Character*> losers){

  cout << "BATTLES OVER" << endl;

  if(losers.size() < 3){
    cout << "Not enough monsters" << endl;
    return;
  }

  Character* first = losers.top();
  losers.pop();
  Character* second = losers.top();
  losers.pop();
  Character* third = losers.top();
  cout << "FIRST PLACE: " << first->get_name() << endl;
  cout << "SECOND PLACE: " << second->get_name() << endl;
  cout << "THIRD PLACE: " << third->get_name() << endl;

  delete first;
  delete second;
  
  while(!losers.empty()){

    Character* helper = losers.top();
    losers.pop();
    delete helper;
  }  
}
  
