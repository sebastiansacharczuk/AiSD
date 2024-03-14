#include <iostream>
#include <cmath>

void Solution(int current_row, const int cols, const int rows){
    long max1 = -1, max2 = -1, i_max, j_max, tmp;

    for(int j = 0; j < cols; j++){
        tmp = P(current_row, j);
        if(tmp > max1){
            max1 = tmp;
            j_max = j; 
        }
    }
    for(int i = 0; i < rows; i++){
        tmp = P(i, j_max);
        if(tmp > max2){
            max2 = tmp;
            i_max = i; 
        }
    }
    if(max1 == max2){
        std::cout << max1;
        return;
    }
    else{
        Solution(i_max, cols, rows);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    Solution(n/2, m, n);

    return 0;
}