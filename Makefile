# Boost C++ library
BOOST = /usr/local/include/boost_1_64_0

# Linear-algebra library

# HTSLIB library for reading BAM files

CC     = g++
CFLAGS = -g -O2
CPPFLAGS = -c -std=c++11
DFLAGS =
LIBS   = -lpthread -lz -lboost_filesystem -lboost_thread -lboost_system -lboost_timer -lboost_chrono -lrt

# Where the header are (no need to modify this)
INCLUDE = src

EXEC         = runTask
SOURCES      = $(wildcard *.cpp)
OBJECTS      = $(SOURCES:.cpp=.o)
OBJECTS_TEST = $(SOURCES_TEST:.cpp=.o)

$(EXEC): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(OBJECTS) $(OBJECTS_TEST) $(CFLAGS) $(DFLAGS) $(LIBS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $(DFLAGS) -I $(INCLUDE) -I ${BOOST} $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(DFLAGS) $(CPPFLAGS) -I $(INCLUDE) -I ${BOOST} $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS) $(OBJECTS_TEST)
