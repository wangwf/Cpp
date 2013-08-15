EXE    =tutorial
SOURCES=$(wildcard *.C)
OBJS   =$(patsubst %.C, %, $(SOURCES) )
#OBJS   =$(patsubst %.C, %.o, $(SOURCES) )

LIBS  =  -pthread
CXXFLAGS+=-std=c++0x -Wall -Weffc++ -Wunused-variable -fpermissive



all: $(EXE)

$(EXE): $(OBJS)
#	$(CXX) $(OBJS) $(LIBS) -o $@

%: %.C
#	$(CXX)  $(CPPFLAGS) $(CXXFLAGS)  $(CCOPTS) -c $<
	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS)  $(CCOPTS)  $<  $(LIBS)


clean:
	rm -rf $(OBJS) $(EXE) o
