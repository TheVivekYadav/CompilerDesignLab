#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int transition[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
int dfa[MAX_STATES][MAX_SYMBOLS];

void convertNFAtoDFA(int states, int symbols) {
    int newStates[MAX_STATES], newStateCount = 1;

    for (int i = 0; i < states; i++) {
        for (int j = 0; j < symbols; j++) {
            int combinedState = 0;
            for (int k = 0; k < states; k++) {
                if (transition[i][j][k]) {
                    combinedState |= (1 << k);
                }
            }
            dfa[i][j] = combinedState;
        }
    }

    printf("DFA Transition Table:\n");
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < symbols; j++) {
            printf("δ(q%d, %c) -> q%d\n", i, 'a' + j, dfa[i][j]);
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

    convertNFAtoDFA(states, symbols);
    return 0;
}

