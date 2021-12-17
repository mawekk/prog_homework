#ifndef DFA_H
#define DFA_H
#include <stdbool.h>

#define ALPHABET_ERROR -1
#define INCORRECT_STATE -2

typedef struct DFA DFA;
typedef struct Transition Transition;

Transition* createTransitions(int number);
void addTransition(Transition* transitions, int from, int to, char* alphabet);
DFA* createDFA(int nTransitions, Transition* transitions, int nAcceptStates, int* acceptStates, int start);
bool isStringAccept(DFA* dfa, char* string, int* error);
void freeDFA(DFA* dfa);

#endif // DFA_H