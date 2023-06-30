PROJECT_NAME=buttchat

all: main.o qna.o
	g++ main.o qna.o -o ${PROJECT_NAME}

main.o:
	g++ -c main.cpp

qna.o:
	g++ -c qna.cpp

clean:
	rm -rf *.o ${PROJECT_NAME}