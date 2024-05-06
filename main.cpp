#include <iostream>

#include "Computer.h"
#include "Human.h"
#include "Player.h"
#include "Referee.h"

int main() {
  Player* human = new Human();
  Player* computer = new Computer();
  Referee referee;

  Player* winner = referee.refGame(human, computer);

  if (winner == nullptr) {
    std::cout << "It's a tie!" << std::endl;
  } else {
    std::cout << winner->getName() << " wins!" << std::endl;
  }

  delete human;
  delete computer;

  return 0;
}