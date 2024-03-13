#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


struct Vehicle{
    std::string name;
    long value;
};

bool compare(const Vehicle &a, const Vehicle &b);

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Vehicle> cars;

    double p;
    unsigned int d;
    std::string name;
    for(int i = 0; i < 3; i++){
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> p >> d;

        cars.push_back({name, long(p * 100000 / (d * 7.97964622))});
    }
    std::sort(cars.begin(), cars.end(), compare);

    long val = cars[2].value;
    for(int i = 3; i < n; i++){
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> p >> d;
        if(val >= long(p * 100000 / (d * 7.97964622))){
            cars.push_back({name, long(p * 100000 / (d * 7.97964622))});
            std::sort(cars.begin(), cars.end(), compare);
            val = cars[2].value;
            cars.resize(3);
        }
        
    }

    std::sort(cars.begin(), cars.end(), compare);

    std::cout << cars[0].name << '\n' << cars[0].value << '\n'
              << cars[1].name << '\n' << cars[1].value << '\n'
              << cars[2].name << '\n' << cars[2].value; 

    return 0;
}

bool compare(const Vehicle &a, const Vehicle &b) {
    if(a.value == b.value)
        return a.name < b.name;
    return a.value < b.value;
}
