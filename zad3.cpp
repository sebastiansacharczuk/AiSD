#include <cstdio>
#include <cstring>
#define MAX_SIZE 30

bool compare(char str1[], char str2[]);

int main(){

    int t, n, p;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        scanf("%d", &p);

        char names[n][MAX_SIZE] = {0};
        int x_i[n], score[n];
        long sum = 0;

        // Reading data set of index i 
        for(int i = 0; i < n; i++){
            scanf("%s", &names[i]);
            scanf("%d", &x_i[i]);
        }

        // Select Sort
        for(int i = 0; i < n-1; i++){
            int max = i;
            for(int j = i+1; j < n; j++){

                if(x_i[max] < x_i[j])
                    max = j;

                else if(x_i[max] == x_i[j])
                    if(compare(names[max], names[j]))
                        max = j;
            }

            // Swaping elements in x_i
            int temp_x_i = x_i[i];
            x_i[i] = x_i[max];
            x_i[max] = temp_x_i;
            // Swaping elements in names
            char temp_str[MAX_SIZE];
            strcpy(temp_str, names[i]);
            strcpy(names[i], names[max]);
            strcpy(names[max], temp_str);

            sum += 1 + x_i[i] * i;
        }
        sum+= 1 + x_i[n-1] * (n-1);


        // Output for data set of index i
        for(int i = 0; i < p; i++)
            printf("%s ", names[i]);
        
        printf("\n%d\n", sum%(1000003));
        
    }

    return 0;
}

bool compare(char str1[], char str2[]) {
    for(int i = 0; str1[i] != 0 || str2[i] != 0; i++) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return 0;
    }
    return 0;
}