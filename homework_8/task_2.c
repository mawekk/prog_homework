#include "../library/DFA/DFA.h"
#include "stdio.h"

int main()
{
    char* digits = "0123456789";
    char* signs = "+-";
    int nTransitions = 15;
    Transition* transitions = createTransitions(nTransitions);
    addTransition(transitions, 0, 1, digits);
    addTransition(transitions, 0, 2, ".");
    addTransition(transitions, 0, 3, signs);
    addTransition(transitions, 3, 1, digits);
    addTransition(transitions, 3, 2, ".");
    addTransition(transitions, 1, 2, ".");
    addTransition(transitions, 1, 5, "E");
    addTransition(transitions, 1, 1, digits);
    addTransition(transitions, 2, 4, digits);
    addTransition(transitions, 4, 4, digits);
    addTransition(transitions, 4, 5, "E");
    addTransition(transitions, 5, 6, signs);
    addTransition(transitions, 5, 7, digits);
    addTransition(transitions, 6, 7, digits);
    addTransition(transitions, 7, 7, digits);

    int nAcceptStates = 3;
    int acceptStates[] = { 1, 4, 7 };
    DFA* dfa = createDFA(nTransitions, transitions, nAcceptStates, acceptStates, 0);

    char string[256];
    int error = 0;
    printf("Enter the string\n");
    scanf("%s", string);
    if (isStringAccept(dfa, string, &error))
        printf("This is a number! :)\n");
    else
        printf("This isn't a number :(\n");

    freeDFA(dfa);
    return error;
}