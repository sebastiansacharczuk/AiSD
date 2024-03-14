#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
struct Edge{
    int number; 
    long weight;
    Edge(int d, long w){
        number = d;
        weight = w;
    }
};


struct Compare{
    bool operator()(Edge& e1, Edge& e2){
        return e1.weight > e2.weight;
    }
};


using namespace std;

void solution(vector<Edge> adj[], vector<long> delays[], int vertices, int source){
    vector<bool>visited(vertices);
    vector<long>shortest_dist(vertices, LONG_MAX);
    
    shortest_dist[source] = 0;
    priority_queue<Edge, vector<Edge>, Compare> pq;
    pq.push(Edge(source, shortest_dist[source]));
    
    while(!pq.empty()){

        Edge prev = pq.top();
        pq.pop();

        if(visited[prev.number]) continue;

        visited[prev.number] = true;
        
        for(int i = 0; i < adj[prev.number].size(); i++){
            int curr_nr = adj[prev.number][i].number;

            if(visited[curr_nr] == false){
                if(shortest_dist[prev.number] + adj[prev.number][i].weight < shortest_dist[curr_nr]){
                    shortest_dist[curr_nr] = shortest_dist[prev.number] + adj[prev.number][i].weight;

                    while (find(delays[curr_nr].begin(), delays[curr_nr].end(), shortest_dist[curr_nr]) != delays[curr_nr].end()) {
                        shortest_dist[curr_nr]++;
                    }   
                }
                pq.push(Edge(curr_nr, shortest_dist[curr_nr]));
            }
        }
    }
    cout << shortest_dist[0] << ' ';
}


int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int datasets, vertices, source;
    long connections;
    cin >> datasets;
    while(datasets--){
        cin >> vertices >> connections >> source;
        vector<Edge> adj[vertices];
        vector<long> delays[vertices];
        int s, d;
        long w;
        for(int i = 0; i < connections; i++){
            cin >> s >> d >> w;

            adj[s].push_back(Edge(d, w));
            adj[d].push_back(Edge(s, w));
        }
        
        long k, tmp;
        for(int i = 0; i < vertices; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> tmp;
                delays[i].push_back(tmp);
            }
        }
        solution(adj, delays, vertices, source);
        
    }

    return 0;
}