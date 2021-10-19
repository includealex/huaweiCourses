#include <benchmark/benchmark.h>
#include <iostream>

#include "../includes/Stack.h"

static void stackBench(benchmark::State &addit) {
    int len = addit.range(0);

    for(auto _ : addit) {
        Stack <uint32_t> s1;
        s1.change_factor(len / 10);

        for(int i = 0; i < 1e6; ++i) {
            s1.push(i);
        }
    }

}

BENCHMARK(stackBench)->DenseRange(4, 9)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
