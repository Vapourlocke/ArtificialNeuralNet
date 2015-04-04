ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLDFLAGS   := $(shell root-config --ldflags)
ROOTLIBS     := $(shell root-config --libs)

########################################################################################
# explicitly written these variables are:
# ROOTCFLAGS   := -pthread -I/usr/local/cern/root//include
# ROOTLIBS     := -L/usr/local/cern/root//lib -lCore -lCint -lHist \
#	-lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix \
#	-lPhysics -pthread -lm -ldl -rdynamic
########################################################################################


CC      = g++
CFLAGS  = -I.



OBJ =  obj/AMFANN_v4.o 
#OBJ += obj/run.o 
OBJ += obj/runroot.o

#OBJ = obj/*

obj/%.o: %.C AMFANN.h
	$(CC)  -c -o $@ $< $(CFLAGS) $(ROOTCFLAGS) 


#run: $(OBJ)
#	$(CC) -o run $^ $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)


runroot: $(OBJ)
	$(CC) -o runroot $^ $(CFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) 

.PHONY: clean

clean:
	rm -f obj/*.o run