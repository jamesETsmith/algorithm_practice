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

TEST_CASE("Two cycles") {
  std::vector<std::vector<double>> adj_matrix = {
      {0, 2, 6, 0, 0, 0, 0},   {2, 0, 0, 5, 0, 0, 0},  {6, 0, 0, 8, 0, 0, 0},
      {0, 5, 8, 0, 10, 15, 0}, {0, 0, 0, 10, 0, 6, 2}, {0, 0, 0, 15, 6, 0, 6},
      {0, 0, 0, 0, 2, 6, 0},
  };
  graph g{adj_matrix};
  std::cout << g << std::endl;

  int distance;

  distance = dijkstra(g, 0, 1);
  CHECK(distance == 2);

  distance = dijkstra(g, 0, 2);
  CHECK(distance == 6);

  distance = dijkstra(g, 0, 3);
  CHECK(distance == 7);

  distance = dijkstra(g, 0, 4);
  CHECK(distance == 17);

  distance = dijkstra(g, 0, 5);
  CHECK(distance == 22);

  distance = dijkstra(g, 0, 6);
  CHECK(distance == 19);
}