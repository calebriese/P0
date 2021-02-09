CC 	 = gcc
CFLAGS   =
TARGET   = test
OBJFILES = listmain.o list.o
  
$(TARGET): $(OBJFILES)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

listmain.o: listmain.c list.c
	gcc -c listmain.c list.c

list.o: list.c   list.h	
	gcc -c list.c
clean: 
	rm -f $(OBJFILES) $(TARGET)
