#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "dijkstra.hpp"
#include "doctest.h"

// TEST_CASE("no sites") {
//   std::vector<std::vector<half_edge>> edges;
//   edges.push_back({{}});
//   graph g{edges};
//   int distance = dijkstra(g, 0, 0);
//   CHECK(distance == 0);
// }

TEST_CASE("graph from adjacency matrix") {
  std::vector<std::vector<double>> adj_matrix = {{0, 1.}, {1, 0.}};
  graph g(adj_matrix);
  CHECK(g.get_edges().size() == 2);
  std::cout << g << std::endl;
}

TEST_CASE("3 sites") {

  std::vector<std::vector<double>> adj_matrix = {
      {0., 3., 1.}, {3., 0., 1.}, {1., 1., 0.}};
  graph g{adj_matrix};
  std::cout << g << std::endl;
  int distance = dijkstra(g, 0, 1);
  CHECK(distance == 2);
}