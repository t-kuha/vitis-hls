# Setting
set PRJ_DIR  _prj
set PART     xc7z020clg400-1
set PERIOD   6.7


# Create project (remove data from previous run)
open_project ${PRJ_DIR} -reset

# Test bench files
add_files -tb "hls.h tb.cpp"
# HLS files & create solution for Vivado flow
set_top patten_gen_axis
add_files hls.cpp
open_solution "solution1" -flow_target vivado -reset
set_part ${PART} 

create_clock -period ${PERIOD} -name default
csim_design
csynth_design
cosim_design
export_design -flow impl -rtl verilog -format ip_catalog

close_solution
close_project
