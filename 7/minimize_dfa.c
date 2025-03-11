#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int dfa[MAX_STATES][MAX_SYMBOLS];
int finalState[MAX_STATES];
int minDFA[MAX_STATES][MAX_SYMBOLS];

void minimizeDFA(int states, int symbols) {
    int partition[MAX_STATES] = {0}; // Grouping equivalent states

    for (int i = 0; i < states; i++) {
        partition[i] = finalState[i];
    }

    int changed;
    do {
        changed = 0;
        for (int i = 0; i < states; i++) {
            for (int j = 0; j < states; j++) {
                if (partition[i] == partition[j]) {
                    if (dfa[i][0] != dfa[j][0] || dfa[i][1] != dfa[j][1]) {
                        partition[j] = ++states;
                        changed = 1;
                    }
                }
            }
        }
    } while (changed);

    printf("Minimized DFA Table:\n");
    for (int i = 0; i < states; i++) {
        printf("q%d -> { %d, %d }\n", i, dfa[i][0], dfa[i][1]);
    }
}

int main() {
    // Load DFA manually or via input
    minimizeDFA(5, 2);
    return 0;
}

