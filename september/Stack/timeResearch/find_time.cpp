#include <benchmark/benchmark.h>

// Everything should be rewritten!!!

static void stackBench(benchmark::State &addit) {
    int len = addit.range(0);
    double factor = 1 + len / 10;

    int counter_ = 1;
    int size_ = 1;


    for(auto _ : addit) {
        int* data_ = new int[32];
        for (int i = 0; i < 1e6; ++i) {
            if(counter_ = size_) {
                    int* tmp = data_;
                    data_ = new int[int(size_ * factor)];
                    std::copy(tmp, tmp + size_, data_);
                    size_ = (int)size_ * factor;
            }

            data_[counter_++] = i;
        }
        delete[] data_;
    }

}



BENCHMARK(stackBench)->DenseRange(4, 9)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
