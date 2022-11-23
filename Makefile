CXX=gcc
CXXFLAGS= -Werror 

run: cmp codec1 codec2 copy decode encode

cmp: cmp.c
	$(CXX) $(CXXFLAGS) $^ -o $@

codec1: codec1.c codec.h
	$(CXX) $(CXXFLAGS) $^ -o $@

codec2: codec2.c codec.h
	$(CXX) $(CXXFLAGS) $^ -o $@

copy: copy.c
	$(CXX) $(CXXFLAGS) $^ -o $@

decode: decode.c
	$(CXX) $(CXXFLAGS) $^ -o $@

encode: encode.c
	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	rm -f *.o cmp codec1 codec2 copy decode encode
