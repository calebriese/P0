CC 	 = gcc main.c tree.c -o P0 -std=c99
CFLAGS   =
TARGET   =
OBJFILES =
  
$(TARGET): $(OBJFILES)  
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) 

main.o: main.c tree.c
	gcc main.c tree.c -o P0 -std=c99

clean: 
	rm -f P0 main.o tree.o *.inorder *.preorder *.postorder
