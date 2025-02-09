FROM ubuntu:24.04

# Install dependencies: g++, curl, cmake, and libgtest-dev
RUN apt-get update && apt-get install -y \
    curl \
    g++ \
    cmake \
    libgtest-dev

# Build Google Test libraries (libgtest.a and libgtest_main.a)
RUN cd /usr/src/gtest && \
    mkdir build && cd build && \
    cmake .. && \
    make && \
    cp lib/libgtest*.a /usr/lib/

# Copy your application source code into the container
# for testing
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

# Compile your application using C++17:
RUN g++ -g -I. -I/usr/src/gtest/googletest/include -L/usr/lib -std=c++17 -pthread graph.cpp -o test_graph -lgtest -lgtest_main

# Run the test executable
CMD ["./test_graph"]
