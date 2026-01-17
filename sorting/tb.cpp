#include <iostream>

#include "hls.h"

int main(int argc, char* argv[]) {
    data_t arr[9] = {9, 5, 7, 2, 8, 4, 6, 3, 1};
    data_t arr_out[9] = {0};

    std::cout << "[INFO] before sorting: ";
    for(int i = 0; i < 9; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;

    hls_sorting_network_9(arr, arr_out);

    std::cout << "[INFO] after sorting: ";
    for(int i = 0; i < 9; i++){
        std::cout << arr_out[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
