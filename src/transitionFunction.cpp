#include "transitionFunction.h"

using namespace Automata;

TransitionFunction::TransitionFunction(std::vector< std::string > transitionFunction)
{
   //dla kazdego napisu z transitionFunction:
   //wez jego wejsciowy znak. Sprawdz, czy juz istnieje mapa dla tego znaku. Stworz w razie gdyby nie
   //wez jego wejsciowy stan. Sprawdz, czy niczego nie ma. Nie powinno byc. Tam wrzuc TransitionFunctionResult, w ktorym jest state, symbol i movement
   for(string s : transitionFunction)
   {
      int begin = 0;
      int i = 0;
      int whatNow = 0;
      char symbolIn;
      char symbolOut;
      string stateIn;
      string stateOut;
      char movement;
      TransitionFunctionResult tfr;

      size_t comma = s.find(",");
      symbolIn = s.substr(begin, comma-begin)[0];
      begin = comma+1;
      comma = s.find(",", comma+1);
      stateIn = s.substr(begin, comma-begin);
      begin = comma+1;
      comma = s.find(",", comma+1);
      symbolOut = s.substr(begin, comma-begin)[0];
      begin = comma+1;
      comma = s.find(",", comma+1);
      stateOut = s.substr(begin, comma-begin);
      movement = s.substr(comma+1)[0];

      tfr.state = stateOut;
      tfr.movement = movement == 'L' ? -1 : 1;
      tfr.symbol = symbolOut;

      Rcout << stateIn << " " << symbolIn << endl;
      Rcout << tfr.state << " " << movement << " " << tfr.movement << " " << tfr.symbol << endl;

      if(f.find(symbolIn) == f.end())
      {
         f[symbolIn] = unordered_map<string, TransitionFunctionResult>();
      }
      f[symbolIn][stateIn] = tfr;
   }
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
