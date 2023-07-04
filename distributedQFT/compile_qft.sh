cmake .. -DUSER_SOURCE="qft.cpp" -DOUTPUT_EXE="qft.out" \
    -DMULTITHREADED=0 -DDISTRIBUTED=0 -DGPUACCELERATED=0 \
    -DPRECISION=2  # works with double
make