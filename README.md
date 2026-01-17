# Vitis HLS sample projects

## How to run

```shell-session
# Set up Vitis HLS
$ . <Vitis HLS tool directory>/settings64.sh 

# Go to one of the project of choice
$ cd <project directory>

# Run
$ vitis -s run.py
# or...
$ v++ -c --mode hls --config hls_config.cfg
```

***

## Projects

- pattern_generator: Video test pattern generator
- sorting: sorting network
  - based on: [yamamaya/SortingNetwork.c](https://gist.github.com/yamamaya/3e7691b7f129fa0c47e1fe9c3851d2f4)
