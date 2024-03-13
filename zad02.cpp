#include<iostream>
#include<string>
// 97-122 65-90

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    int arr[26] = {0};
    
    char c;
    for(int i = 0; i < 2000000; i++){
        std::cin.get(c);
        if(c == '^')
            break;

        if(c > 96 && c < 123)
            arr[c-97]++;
        
        else if(c > 64 && c < 91)
            arr[c-65]++;
        
    }
    int max_val = -1, min_val = 2000000;
    char max_char, min_char;
    for(int i = 0; i < 26; i++){
        if(max_val < arr[i]){
            max_val = arr[i];
            max_char = i + 97;
        }
        if(min_val > arr[i] && arr[i] > 0){
            min_val = arr[i];
            min_char = i + 97;
        }
    }

    std::cout << max_char << ' ' << min_char;
    return 0;
}