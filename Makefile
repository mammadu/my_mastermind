TARGET = my_ngram
SRC_DIR = src
SRC = $(SRC_DIR)/$(TARGET).c
OBJ_DIR = obj
OBJ = $(OBJ_DIR)/$(TARGET).o
CFLAGS = -Wall -Wextra -g3 -Werror

all : $(TARGET)

$(TARGET) : $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ) 

$(OBJ) : $(SRC)
	gcc $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all