#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10

void findEpsilonClosure(int state, bool epsilonTransitions[MAX_STATES][MAX_STATES], bool visited[MAX_STATES]) {
    visited[state] = true;
    for (int i = 0; i < MAX_STATES; i++) {
        if (epsilonTransitions[state][i] && !visited[i]) {
            findEpsilonClosure(i, epsilonTransitions, visited);
        }
    }
}

int main() {
    int n;  
    printf("Enter the number of states: ");
    scanf("%d", &n);

    bool epsilonTransitions[MAX_STATES][MAX_STATES] = {false};
    bool visited[MAX_STATES] = {false};

    printf("Enter e-transitions (state1 state2) and -1 to end:\n");
    int state1, state2;
    while (true) {
        scanf("%d %d", &state1, &state2);
        if (state1 == -1 || state2 == -1) break;
        epsilonTransitions[state1][state2] = true;
    }

    printf("e-closure sets:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_STATES; j++) {
            visited[j] = false;  
        }
        findEpsilonClosure(i, epsilonTransitions, visited);
        printf("Closure of state %d: ", i);
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
