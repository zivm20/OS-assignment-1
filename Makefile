CXX=gcc
CXXFLAGS= -Werror 

run: cmp codec1.so codec2.so copy decode encode

cmp: cmp.o
	$(CXX) $(CXXFLAGS) $^ -o $@
cmp.o: cmp.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@
#test
codec1: codec1.o codec.h
	$(CXX) $(CXXFLAGS) $^ -o $@
#------
codec1.so: codec1.o
	$(CXX) -shared -fPIC $^ -o $@
codec1.o: codec1.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

codec2.so: codec2.o 
	$(CXX) -shared $^ -o $@
codec2.o: codec2.c codec.h
	$(CXX) $(CXXFLAGS) -c $^ -o $@

copy: copy.o
	$(CXX) $(CXXFLAGS) $^ -o $@
copy.o: copy.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

decode: decode.o codec1.so
	$(CXX) $(CXXFLAGS) $^ -o $@
decode.o: decode.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

encode: encode.o 
	$(CXX) $(CXXFLAGS) $^ -o $@
encode.o: encode.c 
	$(CXX) $(CXXFLAGS) -c $^ -o $@


clean:
	rm -f *.o cmp codec1 codec2 copy decode encode
