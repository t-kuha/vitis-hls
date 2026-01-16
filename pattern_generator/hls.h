#ifndef _HLS_H_
#define _HLS_H_

#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef ap_axiu<24, 1, 1, 1>	if_t;
typedef hls::stream<if_t> 		stream_t;

void patten_gen_axis(stream_t& out);

#endif //	_HLS_H_
