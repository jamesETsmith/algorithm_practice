#include "dijkstra.hpp"

int dijkstra(const graph &g, size_t source, size_t destination) {

  // std::vector<std::vector<half_edge>> p(g.n_vertices);
  std::vector<bool> intree(g.n_vertices + 1);
  std::vector<int> distance(g.n_vertices + 1);
  std::vector<size_t> parent(g.n_vertices + 1);

  int v, w;
  double weight;
  int dist;

  for (size_t i = 0; i < g.n_vertices; i++) {
    intree[i] = false;
    distance[i] = std::numeric_limits<int>::max();
    parent[i] = -1;
  }

  distance[source] = 0; // Should be unnecessary
  v = source;

  while (intree[v] == false) {
    intree[v] = true;
    const std::vector<half_edge> &connected = g.edges[v];

    for (size_t j = 0; j < connected.size(); j++) {
      auto [w, weight] = connected[j];
      if (distance[w] > (distance[v] + weight)) {
        distance[w] = distance[v] + weight;
        parent[w] = v;
      }
    }

    v = 1;
    dist = std::numeric_limits<int>::max();

    for (size_t i = 0; i < g.n_vertices; i++) {
      if ((intree[i] == false) && (dist > distance[i])) {
        dist = distance[i];
        v = i;
      }
    }
  }
  return distance[destination];
}