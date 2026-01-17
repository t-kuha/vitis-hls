#include "hls.h"

#include <string.h>

#define SWAP(a, b) if (arr[a] > arr[b]) { data_t tmp = arr[a]; arr[a] = arr[b]; arr[b] = tmp; }

void hls_sorting_network_9(data_t data[9], data_t data_out[9])
{
#pragma HLS INTERFACE mode=m_axi port=data
#pragma HLS INTERFACE mode=m_axi port=data_out

    data_t arr[9];
    memcpy(arr, data, 9 * sizeof(data_t));
    
    SWAP(0, 1);
    SWAP(3, 4);
    SWAP(6, 7);
    SWAP(1, 2);
    SWAP(4, 5);
    SWAP(7, 8);
    SWAP(0, 1);
    SWAP(3, 4);
    SWAP(6, 7);
    SWAP(0, 3);
    SWAP(3, 6);
    SWAP(0, 3);
    SWAP(1, 4);
    SWAP(4, 7);
    SWAP(1, 4);
    SWAP(2, 5);
    SWAP(5, 8);
    SWAP(2, 5);
    SWAP(1, 3);
    SWAP(5, 7);
    SWAP(2, 6);
    SWAP(4, 6);
    SWAP(2, 4);
    SWAP(2, 3);
    SWAP(5, 6);

    memcpy(data_out, arr, 9 * sizeof(data_t));
}
