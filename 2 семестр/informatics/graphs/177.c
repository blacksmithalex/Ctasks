#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int W[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &W[i][j]);
        }
    }
    int mdist = 3001;
    int mi = 0, mj = 0, mk = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++){
                int dist = W[i][j] + W[j][k] + W[k][i];
                if (dist < mdist) {
                    mdist = dist;
                    mi = i;
                    mj = j;
                    mk = k;
                }
            }
                
    printf("%d %d %d", mi + 1, mj + 1, mk + 1);
    return 0;
}
