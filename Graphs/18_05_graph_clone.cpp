#include <queue>
#include <iostream>

struct GraphVertex {
    int label;
    std::vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* graph) {
    if(!graph) {
        return nullptr;
    }

    std::unordered_map<GraphVertex*, GraphVertex*> vertex_map;
    std::queue<GraphVertex*> q(std::deque<GraphVertex*>(1, graph));
    vertex_map.emplace(graph, new GraphVertex({graph->label}));

    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        for(GraphVertex* e : v->edges) {
            if(!vertex_map.count(e)) {
                vertex_map.emplace(e, new GraphVertex({e->label}));
                q.emplace(e);
            }
            vertex_map[v]->edges.emplace_back(vertex_map[e]);
        }
    }
    return vertex_map[graph];
}

int main() {
    // Creating a simple graph
    GraphVertex* vertex1 = new GraphVertex({1});
    GraphVertex* vertex2 = new GraphVertex({2});
    GraphVertex* vertex3 = new GraphVertex({3});

    // Connecting the vertices
    vertex1->edges.push_back(vertex2);
    vertex2->edges.push_back(vertex1);
    vertex2->edges.push_back(vertex3);
    vertex3->edges.push_back(vertex2);

    // Cloning the graph
    GraphVertex* clonedGraph = CloneGraph(vertex1);

    // Displaying the original graph
    std::cout << "Original Graph:" << std::endl;
    std::cout << "Vertex 1: " << vertex1->label << std::endl;
    std::cout << "Vertex 2: " << vertex2->label << std::endl;
    std::cout << "Vertex 3: " << vertex3->label << std::endl;

    // Displaying the cloned graph
    std::cout << "\nCloned Graph:" << std::endl;
    std::cout << "Vertex 1: " << clonedGraph->label << std::endl;
    std::cout << "Vertex 2: " << clonedGraph->edges[0]->label << std::endl;
    std::cout << "Vertex 3: " << clonedGraph->edges[0]->edges[1]->label << std::endl;

    return 0;
}