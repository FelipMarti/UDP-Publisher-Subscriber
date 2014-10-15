CC=gcc

PUB=udp-publisher
SUB=udp-subscriber
POBJ=$(PUB).o
SOBJ=$(SUB).o

all: $(PUB) $(SUB)

$(PUB): $(POBJ)
	$(CC) -o $(PUB) $(POBJ) 

$(SUB): $(SOBJ)
	$(CC) -o $(SUB) $(SOBJ) 

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(POBJ) $(SOBJ) $(PUB) $(SUB)


