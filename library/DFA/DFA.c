#include "DFA.h"
#include "strings.h"
#include <malloc.h>

struct Transition {
    int from;
    int to;
    char* alphabet;
};

struct DFA {
    int nTransitions;
    Transition* transitions;
    int nAcceptStates;
    int* acceptStates;
    int start;
};

Transition* createTransitions(int number)
{
    Transition* transitions = calloc(number, sizeof(Transition));
    return transitions;
}

void addTransition(Transition* transitions, int from, int to, char* alphabet)
{
    Transition newTransition = { from, to, alphabet };
    int i = 0;
    while (transitions[i].alphabet != NULL)
        ++i;
    transitions[i] = newTransition;
}

DFA* createDFA(int nTransitions, Transition* transitions, int nAcceptStates, int* acceptStates, int start)
{
    DFA* dfa = malloc(sizeof(DFA));
    dfa->nTransitions = nTransitions;
    dfa->transitions = transitions;
    dfa->nAcceptStates = nAcceptStates;
    dfa->acceptStates = acceptStates;
    dfa->start = start;
    return dfa;
}

int move(int current, char symbol, Transition* transitions, int nTransitions, int* error)
{
    for (int i = 0; i < nTransitions; i++) {
        if (strchr(transitions[i].alphabet, symbol)) {
            if (transitions[i].from == current)
                return transitions[i].to;
            *error = 0;
        } else
            *error = ALPHABET_ERROR;
    }
    return *error;
}

bool isStringAccept(DFA* dfa, char* string, int* error)
{
    int current = dfa->start;
    int position = 0;
    while (string[position]) {
        current = move(current, string[position], dfa->transitions, dfa->nTransitions, error);
        if (current == ALPHABET_ERROR)
            return false;
        ++position;
    }
    for (int i = 0; i < dfa->nAcceptStates; i++) {
        if (current == dfa->acceptStates[i])
            return true;
    }
    return false;
}