FROM ubuntu
COPY 2_1.cpp .
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ 2_1.cpp -static
CMD ./a.out

