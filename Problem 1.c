#include <stdio.h>
#include <string.h>

#define MAX 200005

int main() {
    char s[MAX];
    scanf("%s", s);
    int n = strlen(s);
    char t[2 * MAX];
    for (int i = 0; i < n; i++) {
        t[i] = s[i];
        t[i + n] = s[i];
    }
    t[2 * n] = '\0';
    int freq[26] = {0};
    int left = 0;
    int current_sum = 0, max_sum = 0;
    for (int right = 0; right < 2 * n; right++) {
        int idx = t[right] - 'a';
        while (freq[idx] > 0) {
            int left_idx = t[left] - 'a';
            freq[left_idx]--;
            current_sum -= (left_idx + 1);
            left++;
        }
        freq[idx]++;
        current_sum += (idx + 1);
        while (right - left + 1 > n) {
            int left_idx = t[left] - 'a';
            freq[left_idx]--;
            current_sum -= (left_idx + 1);
            left++;
        }
      
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    printf("%d\n", max_sum);
    return 0;
}
