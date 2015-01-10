OBJ += decode.bin
SOURES += Que.h Que.cpp Tes.h Main.cpp Planted.h

$(OBJ): $(SOURES)
	g++ $^ -o $@ 

clean:
	rm $(OBJ)

