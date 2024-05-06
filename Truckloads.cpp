#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
  int s1, s2;
  if (numCrates <= loadSize) {
    return 1;
  } else if (numCrates % 2 == 1) {
    s1 = (numCrates / 2) + 1;
    s2 = (numCrates / 2) + 0;
  } else {
    s1 = numCrates / 2;
    s2 = numCrates / 2;
  }
  int trucks = numTrucks(s1, loadSize) + numTrucks(s2, loadSize);
  return trucks;
}
