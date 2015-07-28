#include "turingMachine.h"
using namespace Automata;

TuringMachine::TuringMachine(char blankSymbol, std::vector< std::string > transitionFunction, size_t tapeSize, std::string initialState, std::vector< std::string > finalStates, std::string tape, char head)
   : tape(tapeSize, blankSymbol), f(transitionFunction), tapeSize(tapeSize), state(initialState), finalStates(finalStates)
{
   size_t t = tapeSize - tape.size();

   for(size_t i = t/2; i  < t/2 + tape.size(); ++i)
   {
      this->tape[i] = tape[i - t/2];
   }
   this->head = head == 'R' ? t/2 + tape.size() - 1 : t/2;
}

void TuringMachine::print()
{
   Rcout << "[";
   for(size_t i=0; i<tapeSize; ++i)
      Rcout << tape[i];
   Rcout << "]";
}

bool TuringMachine::isFinalState()
{
   return find(finalStates.begin(), finalStates.end(), state) != finalStates.end();
}

void TuringMachine::execute(bool debug, size_t iterations)
{
   size_t iter = 0;
   while(!isFinalState() && iter < iterations)
   {
      TransitionFunctionResult tfr = f(tape[head], state);
      tape[head] = tfr.symbol;
      state = tfr.state;
      head += tfr.movement;
      if(head < 0 || head > tapeSize)
         Rcpp:stop("Head is not on a tape. Create bigger tape or reconsider your algorithm.");
   }
}

// [[Rcpp::export]]
SEXP turingmachine_create(char blankSymbol, std::vector< std::string > transitionFunction, size_t tapeSize, std::string initialState, std::vector< std::string > finalStates, std::string tape, char head)
{
   TuringMachine* tm = new TuringMachine(blankSymbol, transitionFunction, tapeSize, initialState, finalStates, tape, head);
   XPtr< TuringMachine > retval =  XPtr< TuringMachine >(tm, true);
   retval.attr("class") = "TuringMachine";
   return retval;
}

// [[Rcpp::export]]
void turingmachine_print(SEXP tm)
{
   XPtr< TuringMachine > turingmachine = Rcpp::as< XPtr< TuringMachine > > (tm);
   turingmachine->print();
}

// [[Rcpp::export]]
void turingmachine_execute(SEXP tm, bool debug, size_t iterations)
{
   XPtr< TuringMachine > turingmachine = Rcpp::as< XPtr< TuringMachine > > (tm);
   turingmachine->execute(debug, iterations);
}
