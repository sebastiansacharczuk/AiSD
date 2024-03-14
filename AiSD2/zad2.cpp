#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int v, e, src, dest;
    double weight;
    std::cin >> v >> e;
    std::vector<std::pair<double, int >> adj[v];

    for(int i = 0; i < e; i++){
        std::cin >> src >> dest >> weight;
        adj[dest].push_back({weight, src});
        adj[src].push_back({weight, dest}); // weight as first arg for easier priority queue usage
    }

    

    double result = 1.0;
    bool visited[100000] = {false};
    std::pair<double, int> curr;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::less<std::pair<double, int>>> pq;
    int size;
    pq.push({1.0, 0});
    while(!pq.empty()){
        curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        v--;
        result *= curr.first;
        // cout << result << ' ';
        // cout << curr.second << ' ';
        if(v == 0)
            break;
        size = adj[curr.second].size();
        for(int i = 0; i < size; i++){
            pq.push({adj[curr.second][i].first, adj[curr.second][i].second});
        }

    }
    
    std::cout << std::fixed << std::setprecision(5) << result;
    
    return 0;
}