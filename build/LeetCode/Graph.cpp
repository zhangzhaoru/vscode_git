//图的表示与构造
#include <stdio.h>
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct GraphNode {
    int label;
    vector<GraphNode *> neighbors;
    GraphNode(int x) : label(x){};
};

void DFS(GraphNode *node, int visit[]) {
    visit[node->label] = 1;
    cout << node->label;
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (visit[node->neighbors[i]->label] == 0) {
            DFS(node->neighbors[i], visit);
        }
    }
}

void BFS(GraphNode *node,int visit[]){
    std::queue<GraphNode *> Q;
    Q.push(node);
    visit[node->label] = 1;
    while(!Q.empty()){
        GraphNode *node = Q.front();
        Q.pop();
        cout<<node->label;
        for(int i = 0;i<node->neighbors.size();i++){
            if(visit[node->neighbors[i]->label]==0){
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label]==1;
            }
        }
    }
}

int main() {
    const int MaxN = 5;
    //顶点个数
    GraphNode *Graph[MaxN];
    for (int i = 0; i < MaxN; i++) {
        Graph[i] = new GraphNode(i);
    }
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);
    int visit[MaxN] = {0};
    for (int i = 0; i < MaxN; i++) {
        if (visit[i] == 0) {
            cout << "From Label (" << Graph[i]->label << " ) : ";
            BFS(Graph[i], visit);
            cout << endl;
        }
    }
    for (int i = 0; i < MaxN; i++) {
        delete Graph[i];
    }
    return 0;
}