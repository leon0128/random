CXX = g++-9 
CXXFLAGS = -w
PROGRAM = test
DIR = src
OBJS = $(patsubst %.cpp, %.o, $(wildcard $(DIR)/*.cpp))

$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(PROGRAM)

clean:
	rm -f $(DIR)/*.o $(PROGRAM)