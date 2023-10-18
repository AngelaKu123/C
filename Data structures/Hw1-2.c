#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    // remove '\n' in input buffer
    getchar();

    char original[n][2 * n + 2];

    for (int i = 0; i < n; i++) {
        fgets(original[i], sizeof(original[i]), stdin);
        // Remove '\n'
        int len = strlen(original[i]);
        if (len > 0 && (original[i][len - 1] == '\n' || original[i][len - 1] == '\r'))
            original[i][len - 1] = '\0';
    }
    // matrix printf test
    /*for (int i = 0; i < n; i++)
        printf("%d| %s\n", i, original[i]);*/

    // step 1 : count mines for each 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j += 2) {
            if (original[i][j] == '0') {
                int mines = 0;
                // 1. left and upper
                if ((i - 1 >= 0) && (j - 2 >= 0) && (original[i - 1][j - 2] == '*'))
                    mines++;
                // 2. upper
                if ((i - 1 >= 0) && (original[i - 1][j] == '*'))
                    mines++;
                // 3. right and upper
                if ((i - 1 >= 0) && (j + 2 < 2 * n - 1) && (original[i - 1][j + 2] == '*'))
                    mines++;
                // 4. right
                if ((j + 2 < 2 * n - 1) && (original[i][j + 2] == '*'))
                    mines++;
                // 5. right and lower
                if ((i + 1 < n) && (j + 2 < 2 * n - 1) && (original[i + 1][j + 2] == '*'))
                    mines++;
                // 6. lower
                if ((i + 1 < n) && (original[i + 1][j] == '*'))
                    mines++;
                // 7. left and lower
                if ((i + 1 < n) && (j - 2 >= 0) && (original[i + 1][j - 2] == '*'))
                    mines++;
                // 8. left
                if ((j - 2 >= 0) && (original[i][j - 2] == '*'))
                    mines++;

                original[i][j] = '0' + mines;
            }
        }
        printf("%s\n", original[i]);
    }
    printf("\n");

    // step 2 : transpose
    char transposed[n][2 * n + 2];
    for (int i = 0; i < n; i++)
        strcpy(transposed[i], original[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j += 2) {
            if (transposed[i][j] == '@') {
                // a21 <-> a12
                char temp;
                temp = transposed[i][j - 2];
                transposed[i][j - 2] = transposed[i - 1][j];
                transposed[i - 1][j] = temp;
                // a31 <-> a13
                temp = transposed[i + 1][j - 2];
                transposed[i + 1][j - 2] = transposed[i - 1][j + 2];
                transposed[i - 1][j + 2] = temp;
                // a32 <-> a23
                temp = transposed[i + 1][j];
                transposed[i + 1][j] = transposed[i][j + 2];
                transposed[i][j + 2] = temp;
            }
        }
    }

    // Copy the transposed matrix back to the original matrix
    for (int i = 0; i < n; i++)
        printf("%s\n", transposed[i]);    
    
    printf("\n");

    // step 3 : check whether the mines-counting is correct
    char check[n][2 * n + 2];
    for (int i = 0; i < n; i++) 
        strcpy(check[i], transposed[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j += 2) {
            if (transposed[i][j] >= '0' && transposed[i][j] <= '9') {
                int tran_mines = 0;
                // use step 1 to count new mines
                // 1. left and upper
                if ((i - 1 >= 0) && (j - 2 >= 0) && (transposed[i - 1][j - 2] == '*'))
                    tran_mines++;
                // 2. upper
                if ((i - 1 >= 0) && (transposed[i - 1][j] == '*'))
                    tran_mines++;
                // 3. right and upper
                if ((i - 1 >= 0) && (j + 2 < 2 * n - 1) && (transposed[i - 1][j + 2] == '*'))
                    tran_mines++;
                // 4. right
                if ((j + 2 < 2 * n - 1) && (transposed[i][j + 2] == '*'))
                    tran_mines++;
                // 5. right and lower
                if ((i + 1 < n) && (j + 2 < 2 * n - 1) && (transposed[i + 1][j + 2] == '*'))
                    tran_mines++;
                // 6. lower
                if ((i + 1 < n) && (transposed[i + 1][j] == '*'))
                    tran_mines++;
                // 7. left and lower
                if ((i + 1 < n) && (j - 2 >= 0) && (transposed[i + 1][j - 2] == '*'))
                    tran_mines++;
                // 8. left
                if ((j - 2 >= 0) && (transposed[i][j - 2] == '*'))
                    tran_mines++;

                transposed[i][j] = '0' + tran_mines;
            }
        }
    }
    /*for (int i = 0; i < n; i++)
        printf("%s | %s\n", check[i], transposed[i]);*/

    int equal = 1;
    for (int i = 0; i < n; i++) {
        if (strcmp(check[i], transposed[i]) != 0)
            equal = 0;
    }
        
    if (equal == 0)
        printf("Wrong\n");
    else
        printf("Correct\n");
        
    return 0;
}
