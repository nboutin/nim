sudo perf record  -g ./nim
sudo perf report --sort comm,dso