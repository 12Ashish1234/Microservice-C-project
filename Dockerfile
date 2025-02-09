# Testing
FROM ubuntu:24.04
RUN apt-get update && apt-get install -y curl g++
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -o test_graph graph.cpp -lgtest -lgtest_main -pthread
CMD ["./create_json"]
