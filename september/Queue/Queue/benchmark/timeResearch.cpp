
#include <benchmark/benchmark.h>

#include "circular_queue_impl.hpp"
#include "stack_queue_impl.hpp"

static const int kStart = 1;
static const int kFinish = 10;
static const int kStep = 1;
static const int nTests = 1e6;

static void BM_Stack_Queue(benchmark::State& state) {
  for (auto _ : state) {
    stack_queue::Queue<int> q;
    for (int i = 0; i < nTests; ++i) {
      q.push(i);
    }
    for (int i = 0; i < nTests; ++i) {
      q.pop();
    }
  }
}
BENCHMARK(BM_Stack_Queue)->DenseRange(kStart, kFinish, kStep)->Unit(benchmark::kMillisecond);

static void BM_Circular_Queue(benchmark::State& state) {
  for (auto _ : state) {
    circular_queue::Queue<int> q;
    for (int i = 0; i < nTests; ++i) {
      q.push(i);
    }
    for (int i = 0; i < nTests; ++i) {
      q.pop();
    }
  }
}
BENCHMARK(BM_Circular_Queue)->DenseRange(kStart, kFinish, kStep)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();