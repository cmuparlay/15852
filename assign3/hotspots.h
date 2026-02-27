#include <atomic>
#include "parlaylib/include/parlay/primitives.h"
#include "parlaylib/include/parlay/sequence.h"

template <typename vertex, typename graph>
auto hotspots(parlay::sequence<vertex> U, const graph& G) {
  vertex n = G.size();

  // n indicates that has not been visited
  auto nearest = parlay::tabulate<std::atomic<vertex>>(n, [&] (long i) {return n;});

  // mark the set U as visited from self
  parlay::parallel_for(0, U.size(), [&] (long i) {
    nearest[U[i]] = U[i];});

  // to be filled in
  std::cout << "nothing running : need to implement" << std::endl;

  // convert from sequence of atomics to a regular sequence
  return parlay::tabulate(n, [&] (long i) {return nearest[i].load();});
}
