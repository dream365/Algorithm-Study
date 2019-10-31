#include <stdio.h>

typedef struct {
    int src;
    int dst;
} Edge;

typedef struct {
    int V;
    int E;
    Edge* edge;
} Graph;

// 0
// | \
// 1--2 is cycle

// 3
// |
// 2
// |
// 1
// |
// 0 is not cycle

int findRoot(int* parent, int v) {
    if(parent[v] == -1)
        return v;
    else
        return findRoot(parent, parent[v]);
}

void doUnion(int* parent, int src, int dst) {
    int srcRoot = findRoot(parent, src);
    int dstRoot = findRoot(parent, dst);

    parent[src] = dst;
}

bool checkCycle(Graph* graph) {
    int* parent = new int[graph->V];

    for(int i = 0; i < graph->V; i++) {
        parent[i] = -1;
    }

    for(int i = 0; i < graph->E; i++) {
        int srcRoot = findRoot(parent, graph->edge[i].src);
        int dstRoot = findRoot(parent, graph->edge[i].dst);

        if(srcRoot == dstRoot)
            return true;

        doUnion(parent, graph->edge[i].src, graph->edge[i].dst);
    }

    return false;
}

int main() {
    Graph* cycleGraph = new Graph;
    Graph* noneCycleGraph = new Graph;

    //make cycle graph
    cycleGraph->V = 3;
    cycleGraph->E = 3;
    cycleGraph->edge = new Edge[cycleGraph->E];

    cycleGraph->edge[0].src = 0;
    cycleGraph->edge[0].dst = 1;
    cycleGraph->edge[1].src = 1;
    cycleGraph->edge[1].dst = 2;
    cycleGraph->edge[2].src = 0;
    cycleGraph->edge[2].dst = 2;

    //make none cycle graph
    noneCycleGraph->V = 4;
    noneCycleGraph->E = 3;
    noneCycleGraph->edge = new Edge[noneCycleGraph->E];

    noneCycleGraph->edge[0].src = 0;
    noneCycleGraph->edge[0].dst = 1;
    noneCycleGraph->edge[1].src = 1;
    noneCycleGraph->edge[1].dst = 2;
    noneCycleGraph->edge[2].src = 2;
    noneCycleGraph->edge[2].dst = 3;

    printf("cycleGraph %s\n", checkCycle(cycleGraph) ? "has cycle" : "doesn't have cycle");
    printf("noneCycleGraph %s\n", checkCycle(noneCycleGraph) ? "has cycle" : "doesn't have cycle");

    return 0;
}