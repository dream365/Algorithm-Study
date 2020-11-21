class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        visit = {}
        queue = []
        first = -1
        
        if len(graph) == 1 and len(graph[0]) == 0:
            return True
        
        for idx, node in enumerate(graph):
            if 0 == len(node):
                visit[idx] = True
            else:
                if first == -1:
                    first = idx
                
        queue.append((first, True))
        
        while len(queue) != 0 or len(visit.keys()) != len(graph):
            if len(queue) == 0:
                for idx, node in enumerate(graph):
                    if idx not in visit.keys():
                        queue.append((idx, True))
                        break
            node = queue.pop(0)
            num = node[0]
            flag = node[1]
            if num in visit.keys():
                if visit[num] != flag:
                    return False
            else:
                visit[num] = flag
                for n in graph[num]:
                    queue.append((n, not flag))
        
        return True
        
