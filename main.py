import pprint


def find_path(graph: dict[str, list[str]],
              start: str,
              end: str,
              path: list[str] = []) -> list[str] | None:
    path.append(start)

    if start == end:
        return path
    if start not in graph:
        return None

    for node in graph[start]:
        if node not in path:
            newpath: list[str] = find_path(graph, node, end, path)
            if newpath:
                return newpath

    return None


def dfs(graph: dict[str, list[str]], node: str, visited: set[str] = []) -> set[str]: 
    if node not in visited:
        visited.append(node)
        for n in graph[node]:
            dfs(graph,n, visited)
            
    return visited

def find_articulation_points(graph: dict[str, list[str]]) -> list[str]:
    visited: set[str] = set()
    time: dict[str, int] = {}
    low: dict[str, int] = {}
    parent: dict[str, str] = {}
    articulation_points: set[str] = set()
    discovery_time: int = 0

    def dfs(node: str) -> None:
        nonlocal discovery_time
        visited.add(node)
        time[node] = discovery_time
        low[node] = discovery_time
        discovery_time += 1
        children: int = 0
	
        if node in graph:
            for neighbor in graph[node]:
                if neighbor not in visited:
                    parent[neighbor] = node
                    children += 1
                    dfs(neighbor)
                    low[node] = min(low[node], low[neighbor])

                    if ((parent.get(node) is None and children > 1)) or (parent.get(node) is not None and low[neighbor] >= time[node]):
                        articulation_points.add(node)
                elif neighbor != parent.get(node):
                    low[node] = min(low[node], time[neighbor])

    for node in graph:
        if node not in visited:
            dfs(node)

    return list(articulation_points)


def main() -> None:
    order: int = int(input())
    graph: dict[str, list[str]] = {}

    for i in range(0, order):
        temp: list = input().split(" ")
       	graph[temp[0]] = temp[1::]

    soln: set[str] = dfs(graph, 'a')
    print(soln)
        

if __name__ == "__main__":
    main()
