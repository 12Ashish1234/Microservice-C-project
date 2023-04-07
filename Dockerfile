FROM arm64v8/ubuntu:latest
RUN apt-get update && apt-get install -y curl g++
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -g -I. -std=c++11 -pthread create_json.cpp -o create_json
CMD ["./create_json"]
