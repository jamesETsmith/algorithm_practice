#include <array>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using half_edge = std::pair<size_t, double>; // Connected vertex and weight

struct graph {
  std::vector<std::vector<half_edge>> edges;
  size_t n_vertices;
  size_t n_edges;

  graph(std::vector<std::vector<double>> &adj_matrix) {
    n_vertices = adj_matrix.size();

    edges.clear();
    n_edges = 0;
    for (size_t i = 0; i < n_vertices; i++) {
      edges.push_back({{}});
      for (size_t j = 0; j < n_vertices; j++) {
        if (adj_matrix[i][j] != 0) {
          edges[i].push_back({j, adj_matrix[i][j]});
          n_edges++;
        }
      }
    }
  }

  const std::vector<std::vector<half_edge>> &get_edges() { return edges; }

  friend std::ostream &operator<<(std::ostream &os, const graph &g);
};

std::ostream &operator<<(std::ostream &os, const graph &g) {
  os << "Graph has " << g.n_vertices << " vertices" << std::endl;
  os << "Graph has " << g.n_edges << " edges" << std::endl;

  if (g.n_vertices < 10) {
    std::vector<std::vector<double>> adj_matrix(
        g.n_vertices, std::vector<double>(g.n_vertices));
    for (size_t i = 0; i < g.n_vertices; i++) {
      for (size_t j = 0; j < g.edges[i].size(); j++) {
        auto [e2, w] = g.edges[i][j];
        adj_matrix[i][e2] = w;
      }
    }

    for (auto r : adj_matrix) {
      for (auto el : r) {
        os << el << " ";
      }
      os << std::endl;
    }
  } else {
    os << "The adjacency matrix is too large to print to stdout." << std::endl;
  }

  return os;
}

int dijkstra(const graph &g, size_t source, size_t destination);