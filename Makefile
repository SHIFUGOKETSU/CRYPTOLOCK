##
# Project Title
#
# @file
# @version 0.1

CC=g++
flags = -lssl -lcrypto

run: main.cpp
	$(CC) $(flags) main.cpp -o diary
	./diary

# end
