#include <benchmark/benchmark.h>
#include <iostream>

#include "../includes/Stack.h"
#include "../includes/Stack_impl.h"

static void stackBench(benchmark::State &addit) {
    int len = addit.range(0);

    for(auto _ : addit) {
        Stack <uint32_t> s1;
        change_factor(s1, len / 10);

        for(int i = 0; i < 1e6; ++i) {
            s1.push(i);
        }
    }
}

BENCHMARK(stackBench)->DenseRange(4, 9)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();