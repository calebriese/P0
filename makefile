CC 	 = gcc
CFLAGS   = -std=c99
TARGET   = OUTNAME
OBJFILES = main.o tree.o
  
$(TARGET): $(OBJFILES)  
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) 

main.o: main.c tree.c
	gcc -c main.c tree.h -std=c99

list.o: tree.c tree.h node.h
	gcc -c tree.c
clean: 
	rm -f $(OBJFILES) $(TARGET)
