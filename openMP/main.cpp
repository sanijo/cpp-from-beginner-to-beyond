//compute the sum of two arrays in parallel 
#include <iostream>
#include <omp.h>


int main() { 
    
    int threads = 12;
    int id = 100;
    #pragma omp parallel
    {
    threads = omp_get_num_threads();
    id = omp_get_thread_num();
    std::cout << "\nHello from thread: " << id << "out of ";
    std::cout << threads << std::endl;
    }

    return 0;
}
