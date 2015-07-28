#include "transitionFunction.h"

using namespace Automata;

TransitionFunction::TransitionFunction(std::vector< std::string > transitionFunction)
{
   //dla kazdego napisu z transitionFunction:
   //wez jego wejsciowy znak. Sprawdz, czy juz istnieje mapa dla tego znaku. Stworz w razie gdyby nie
   //wez jego wejsciowy stan. Sprawdz, czy niczego nie ma. Nie powinno byc. Tam wrzuc TransitionFunctionResult, w ktorym jest state, symbol i movement
}

TransitionFunctionResult TransitionFunction::operator()(char symbol, string state)
{
   auto stateMap = f.find(symbol);
   if(stateMap != f.end())
   {
      auto tfr = stateMap->second.find(state);
      return tfr->second;
   }
   else
   {
      Rcpp:stop("there is no transition");
   }
}
