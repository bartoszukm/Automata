#ifndef __TURING_MACHINE_H
#define __TURING_MACHINE_H

#include <vector>
#include <string>
#include <Rcpp.h>
#include "transitionFunction.h"

using namespace Rcpp;
using namespace std;

namespace Automata
{
class TuringMachine
{
   vector<char> tape;
   TransitionFunction f;
   std::string state;
   std::vector< std::string > finalStates;
   size_t tapeSize;
   size_t head;

public:
   TuringMachine(char blankSymbol, std::vector< std::string > transitionFunction, size_t tapeSize, std::string initialState, std::vector< std::string > finalStates, std::string tape);
   void print();
   void execute(bool debug, size_t iterations);
};
}

#endif
