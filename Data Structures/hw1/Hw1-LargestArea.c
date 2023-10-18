#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int stack[n];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && heights[i] < heights[stack[top]]) {
            int height = heights[stack[top]];
            top--;
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            maxArea = (area > maxArea) ? area : maxArea;
        }
        stack[++top] = i;

        /*for(int j = 0; j <= top; j++)
            printf("%d ", stack[j]);

        printf("\n:<\n");*/
    }

    while (top >= 0) {
        int height = heights[stack[top]];
        top--;
        int width = (top == -1) ? n : n - stack[top] - 1;
        int area = height * width;
        maxArea = (area > maxArea) ? area : maxArea;
    }

    printf("%d\n", maxArea);

    return 0;
}
