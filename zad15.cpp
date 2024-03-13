#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tests, n, a, b;
    cin >> tests;

    while(tests--){
        cin >> n;
        
        vector<pair<int,int>> cameras(n);
        vector<char> placed(n, 0);

        for(int j = 0; j < n; j++){
            cin >> a >> b;
            cameras[j].first = a;
            cameras[j].second = b;
        }

        sort(cameras.begin(), cameras.end(), compare);

        
        bool result = true, placed_camera;
        for(int i = 0; i < n; i++){
            placed_camera = false;
            for(int j = cameras[i].first; j <= cameras[i].second; j++){
                if(placed[j] == 0){
                    placed_camera = true;
                    placed[j] = 1;
                    break;
                }  
            }
            if(!placed_camera){
                result = false;
                break;
            }
        }
        if(result)
            cout << "TAK\n";
        else
            cout << "NIE\n"; 
    
    }

}
