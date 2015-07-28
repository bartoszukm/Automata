#include <vector>

using namespace std;
using namespace rcpp;
namespace TuringMachine
{
class TuringMachine
{
    vector<char> tape;
    TransitionFunction f;
    string state;
    vector<char> finalStates;
    size_t tapeSize;
    size_t head;
public:
   TuringMachine(char blankSymbol, CharacterVector transitionFunction, size_t tapeSize, CharacterVector initialState, CharacterVector finalStates, CharacterVector tape)
      : tape(tapeSize, blankSymbol), f(transitionFunction), tapeSize(tapeSize), state(initialState), finalStates(finalStates)
   {
      //wez rozmiar tape
      //n = tape.size() - tapeSize
      //
      for(size_t i = 0
   }
  
   void print()
   {
      Rcout << "[";
      for(size_t i=0; i<tapeSize; ++i)
         Rcout << tape[i] << i < tapeSize - 1 ? " " : "";
      Rcout << "]";
   }
  
   void execute(bool debug, size_t iterations)
   {
      size_t iter = 0;
      while(state != finalStates && iter < iterations)
      {
         TransitionFunctionResult tfr = f(tape[head], state);
         tape[head] = tfr.symbol;
         state = tfr.state;
         head += tfr.movement;
         if(head < 0 || head > tapeSize)
            Rcpp:stop("Head is not on a tape. Create bigger tape or reconsider your algorithm.");
      }
   }
};
}