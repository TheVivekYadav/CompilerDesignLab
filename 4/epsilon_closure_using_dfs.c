#include <stdio.h>

#define MAX_STATES 12

int epsilon[MAX_STATES][MAX_STATES]; // ε-transition adjacency matrix
int closure[MAX_STATES][MAX_STATES]; // ε-closure matrix

void findEpsilonClosure(int states) {
    // Step 1: Initialize closure matrix
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < states; j++) {
            closure[i][j] = epsilon[i][j]; // Copy adjacency matrix
        }
        closure[i][i] = 1; // Each state includes itself
    }

    // Step 2: Compute transitive closure using Floyd-Warshall
    for (int k = 0; k < states; k++) {
        for (int i = 0; i < states; i++) {
            for (int j = 0; j < states; j++) {
                if (closure[i][k] && closure[k][j]) {
                    closure[i][j] = 1;
                }
            }
        }
    }

    // Step 3: Print ε-closures
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

    // Initialize epsilon-transition matrix
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < states; j++) {
            epsilon[i][j] = 0;
        }
    }

    // Read ε-transitions
    for (int i = 0; i < transitions; i++) {
        printf("Enter ε-transition (from to): ");
        scanf("%d %d", &from, &to);
        epsilon[from][to] = 1;
    }

    findEpsilonClosure(states);
    return 0;
}

