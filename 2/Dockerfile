FROM ubuntu
RUN apt-get update
RUN apt install gcc gdb gcc-multilib nano -y
COPY lab2.s .
RUN gcc -m32 lab2.s -o lab2S
CMD ./lab2S
