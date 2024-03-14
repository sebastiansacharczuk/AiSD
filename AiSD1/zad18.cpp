#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    int a, b;
};

void Solution(int n, Product products[]){
    long group_arr[n] = {0}, counter_arr[n];
    Product sorted[n];

    // 1 Wedlug modulo

    for(int i = 0; i < n; i++)
        group_arr[products[i].a]++;

    counter_arr[0] = group_arr[0];
    for(int i = 1; i < n; i++)
        counter_arr[i] = counter_arr[i - 1] + group_arr[i];
    
    for(int i = n-1; i >= 0; i--)
        sorted[--counter_arr[products[i].a]] = products[i];

    // for(int i = 0; i < n; i++){
    //     cout << sorted[i].name << ' ';
    // }

    // 2 Wedlug dzielenia

    for(int i = 0; i < n; i++)
        group_arr[i] = 0;

    for(int i = 0; i < n; i++)
        group_arr[products[i].b]++;
    // cout << '\n';
    // for(int i = 0; i < n; i++)
    //     cout << group_arr[i] << ' ';

    counter_arr[0] = group_arr[0];
    for(int i = 1; i < n; i++)
        counter_arr[i] = counter_arr[i - 1] + group_arr[i];
    // cout << '\n';
    // for(int i = 0; i < n; i++)
    //     cout << counter_arr[i] << ' ';

    for(int i = n-1; i >= 0; i--)
        products[--counter_arr[sorted[i].b]] = sorted[i];


    // result
    //cout << "\n";
    for(int i = 0; i < n; i++)
        cout << products[i].name << ' ';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    long tmp;
    cin >> n;
    Product arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].name;
        cin >> tmp;
        arr[i].a = tmp % n;
        arr[i].b = tmp / n;
    }

    Solution(n, arr);

    return 0;
}