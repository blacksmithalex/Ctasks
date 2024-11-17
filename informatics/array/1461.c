#include <stdio.h>
void shift(int *a, int l, int r, int N) {
    while (r < N) {
        a[l] = a[r];
        l++;
        r++;
    }
    while (l < N) {
        a[l] = -1;
        l++;
    }
}

int main()
{
    int N;
    int removed_balls = 0;
    scanf("%d", &N);
    int nums[N];
    for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
    if (N == 1) {
        printf("%d", 0);
    } else {
        int l = 0;
        int r = 1;
        while (r < N && nums[r] != -1) {
            if (nums[r] == nums[r - 1]) {
                while (r < N && nums[r] == nums[r - 1]) {
                    r++;
                }
                if (r - l > 2) {
                    removed_balls += (r - l);
                    shift(nums, l, r, N);
                    l = 0;
                    r = 1;
                } else {
                    l = r - 1;
                }
            } else {
                l++;
                r++;
            }
        }
        printf("%d", removed_balls);
    return 0;
    }
}