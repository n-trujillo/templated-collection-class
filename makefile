all: Collection.h collection-test.cpp Jeans.cpp Jeans.h Jeans_test.cpp Jeans_test.h Stress_ball.cpp Stress_ball.h Stress_ball_test.cpp Stress_ball_test.h
	g++ collection-test.cpp Jeans.cpp Stress_ball.cpp Jeans_test.cpp Stress_ball_test.cpp -o test

clean:
	rm -f test

run: test
	./test