CC = gcc
CFLAGS = -Wall

TARGET = simpleCSVsorter
TARGET2 = mergesort
RM = rm

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).c ; $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(TARGET2).c
    
$(TARGET2): $(TARGET2).c ; $(CC) $(CFLAGS) -c $(TARGET2).c
    
clean: ; $(RM) $(TARGET) ; $(RM) $(TARGET2).o