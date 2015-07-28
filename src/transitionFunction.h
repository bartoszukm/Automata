#include <vector>
#include <unordered_map>

using namespace std;
using namespace rcpp;

namespace TuringMachine
{
struct TransitionFunctionResult
{
   string state;
   char movement;
   char symbol;
};

class TransitionFunction
{
    unordered_map<string, unordered_map<string, TransitionFunctionResult> > f; //najpierw znak, potem stan
public:
   TransitionFunction(CharacterVector transitionFunction)
   {
      //dla kazdego napisu z transitionFunction:
      //wez jego wejsciowy znak. Sprawdz, czy juz istnieje mapa dla tego znaku. Stworz w razie gdyby nie
      //wez jego wejsciowy stan. Sprawdz, czy niczego nie ma. Nie powinno byc. Tam wrzuc TransitionFunctionResult, w ktorym jest state, symbol i movement
   }
   
   TransitionFunctionResult operator(char symbol, string state)
   {
      auto stateMap = f.find(symbol);
      if(stateMap != f.end())
      {
         auto tfr = stateMap.find(state);
         return tfr;
      }
      else
      {
            Rcpp:stop("there is no transition");
      }
   }
};
}