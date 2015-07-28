#ifndef __TRANSITION_FUNCTION_H
#define __TRANSITION_FUNCTION_H

#include <vector>
#include <unordered_map>
#include <vector>
#include <string>
#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

namespace Automata
{
struct TransitionFunctionResult
{
   string state;
   int movement;
   char symbol;
};

class TransitionFunction
{
    unordered_map<char, unordered_map<string, TransitionFunctionResult> > f; //najpierw znak, potem stan
public:
   TransitionFunction(std::vector< std::string > transitionFunction);
   TransitionFunctionResult operator()(char symbol, string state);
};
}

#endif
