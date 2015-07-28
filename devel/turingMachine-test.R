tm <- turingmachine_create(blankSymbol = '?',
                           transitionFunction = c("0,q0,0,q0,L",
                                                  "1,q0,1,q1,L",
                                                  "0,q1,0,q1,L",
                                                  "1,q1,1,q0,L",
                                                  "?,q0,0,q2,L",
                                                  "?,q1,1,q2,L"
                                                  ), tapeSize = 30, initialState = "q0", finalStates = "q2", tape = "10011", head='R')
turingmachine_print(tm)
turingmachine_execute(tm, FALSE, 8)
turingmachine_print(tm)
