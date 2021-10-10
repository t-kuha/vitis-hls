#include <iostream>

#include "hls.h"

int main(int argc, char* argv[])
{
	stream_t out;
	if_t pixel;
	petten_gen_axis(out);

	// Read out & show some data
	size_t num_pixel = out.size();
	std::cout << "-- # pixels: " << num_pixel << std::endl;
	for(size_t i = 0; i < num_pixel; i++){
		out >> pixel;
		if(i < 10){
			std::cout << "-- output pixel value @" << i << ": " << std::hex << pixel.data << std::endl;
		}
	}

	return 0;
}
