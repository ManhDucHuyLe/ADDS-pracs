#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
 public:
  char makeMove() override;

  std::string getName() override;
};

#endif