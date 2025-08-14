#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm> // para std::reverse
#include <functional> // para std::function
#include <stack> // para std::stack

template <typename T>
void addNeighbours(
  const T& node,
  std::queue<T>& searchQueue,
  std::unordered_map<T, std::vector<T>>& parentsMap,
  const std::unordered_map<T, std::vector<T>> &graph) {
    
  auto it = graph.find(node);
  if (it != graph.end()) {
    for (const auto& currNode : it->second) {

      // Cola de busqueda
      searchQueue.push(currNode);

      // Mapa de padres
      if (parentsMap.find(currNode) == parentsMap.end()) {
        std::vector<T> nuevoVectorPadres;
        nuevoVectorPadres.emplace_back(node);
        parentsMap.insert({currNode, nuevoVectorPadres});
      } else {
        parentsMap[currNode].emplace_back(node);
      }
    }
  }
}

template <typename T>
void printPath(const std::vector<T>& path) {
    if (path.empty()) {
        std::cout << "No path found!" << std::endl;
        return;
    }
    std::cout << "Shortest path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << "Path length: " << path.size() - 1 << " steps" << std::endl;
}

template <typename T>
bool isMangoSeller(T& node) {
  return (node == "mango seller!");
}

template <typename T>
void getShortestPath(const T &begin, 
        const std::unordered_map<T, std::vector<T>>& parentsMap, const T& target) {
          
    std::vector<T> path;
    T current = target;
    // Reconstruir hacia atrás tomando el PRIMER padre (BFS garantiza que sea shortest)
    while (current != begin) {
        path.push_back(current);
        auto it = parentsMap.find(current);
        if (it == parentsMap.end() || it->second.empty()) {
            printPath(std::vector<T>{}); // Pasar vector vacío para "No path found"
            return;
        }
        current = it->second[0]; // Tomar el primer padre (todos son shortest en BFS)
    }
    path.push_back(begin);
    std::reverse(path.begin(), path.end());
    printPath(path);
}

template <typename T>
bool breadthFirstSearch(const T &begin,
        const std::unordered_map<T, std::vector<T>> &graph) {

  std::queue<T> searchQueue;
  std::unordered_set<T> searched;
  std::unordered_map<T, std::vector<T>> parentsMap;
  std::vector<T> shortestPath;
  addNeighbours(begin, searchQueue, parentsMap, graph);  // ← Agregar parentsMap
  while (!searchQueue.empty()) {
    // Tomar el del frente
    T currNode = searchQueue.front(); searchQueue.pop();
    // Revisar solo los que no he revisado
    if (searched.find(currNode) == searched.end()) {
      // Ver si es mango seller
      if (isMangoSeller(currNode)) {
        std::cout << currNode << " sells mangos" << std::endl;
        getShortestPath(begin, parentsMap, currNode);
        return true;
      } else {
        addNeighbours(currNode, searchQueue, parentsMap, graph);
      }
      searched.insert(currNode);
    }
  }
  return false;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"you", {"alice", "bob", "claire"}});
    graph.insert({"bob", {"anuj", "peggy"}});
    graph.insert({"alice", {"peggy"}});
    graph.insert({"claire", {"mango seller!", "jonny"}});
    graph.insert({"anuj", {}});
    graph.insert({"peggy", {}});
    graph.insert({"mango seller!", {}});
    graph.insert({"jonny", {"mango seller!"}});

    std::string name = "you";
    bool result = breadthFirstSearch(name, graph);
    std::cout << "Found mango seller: " << result << std::endl;
}