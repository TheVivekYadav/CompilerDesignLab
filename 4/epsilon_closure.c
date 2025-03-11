#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10

int epsilon[MAX_STATES][MAX_STATES]; // ε-transition adjacency matrix
int closure[MAX_STATES][MAX_STATES]; // Stores ε-closure sets

void findEpsilonClosure(int states) {
    for (int i = 0; i < states; i++) {
        closure[i][i] = 1; // Every state is in its own ε-closure
    }

    for (int i = 0; i < states; i++) {
        for (int j = 0; j < states; j++) {
            if (epsilon[i][j]) {
                closure[i][j] = 1;
            }
        }
    }

    // Transitive closure using Floyd-Warshall algorithm
    for (int k = 0; k < states; k++) {
        for (int i = 0; i < states; i++) {
            for (int j = 0; j < states; j++) {
                if (closure[i][k] && closure[k][j]) {
                    closure[i][j] = 1;
                }
            }
        }
    }

    printf("\nε-Closure of states:\n");
    for (int i = 0; i < states; i++) {
        printf("ε-Closure(q%d): { ", i);
        for (int j = 0; j < states; j++) {
            if (closure[i][j]) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }
}

int main() {
    int states, transitions, from, to;
    
    printf("Enter number of states: ");
    scanf("%d", &states);

    printf("Enter number of ε-transitions: ");
    scanf("%d", &transitions);

    for (int i = 0; i < transitions; i++) {
        printf("Enter ε-transition (from to): ");
        scanf("%d %d", &from, &to);
        epsilon[from][to] = 1;
    }

    findEpsilonClosure(states);
    return 0;
}

