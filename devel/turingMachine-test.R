tm <- turingmachine_create(blankSymbol = '?', transitionFunction = c("asd", "dsa"), tapeSize = 30, initialState = "q0", finalStates = "qf", tape = "abcd")
turingmachine_print(tm)
