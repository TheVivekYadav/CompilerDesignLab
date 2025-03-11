#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int epsilonClosure[MAX_STATES][MAX_STATES];
int transition[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
int newTransition[MAX_STATES][MAX_SYMBOLS][MAX_STATES];

void removeEpsilon(int states, int symbols) {
    for (int state = 0; state < states; state++) {
        for (int sym = 0; sym < symbols; sym++) {
            for (int epsState = 0; epsState < states; epsState++) {
                if (epsilonClosure[state][epsState]) {
                    for (int k = 0; k < states; k++) {
                        if (transition[epsState][sym][k]) {
                            newTransition[state][sym][k] = 1;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int states, symbols, transitions, from, to, symbol;
    
    printf("Enter number of states: ");
    scanf("%d", &states);

    printf("Enter number of input symbols: ");
    scanf("%d", &symbols);

    printf("Enter number of transitions: ");
    scanf("%d", &transitions);

    for (int i = 0; i < transitions; i++) {
        printf("Enter transition (from symbol to): ");
        scanf("%d %d %d", &from, &symbol, &to);
        transition[from][symbol][to] = 1;
    }

    removeEpsilon(states, symbols);

    printf("NFA after removing ε-transitions:\n");
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < symbols; j++) {
            printf("δ(q%d, %c) -> { ", i, 'a' + j);
            for (int k = 0; k < states; k++) {
                if (newTransition[i][j][k]) {
                    printf("q%d ", k);
                }
            }
            printf("}\n");
        }
    }

    return 0;
}

