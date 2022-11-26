CXX=gcc
CXXFLAGS= -Werror 

run: cmp codec1.so codec2.so copy decode encode

cmp: cmp.c
	$(CXX) $(CXXFLAGS) $^ -o $@

copy: copy.c
	$(CXX) $(CXXFLAGS) $^ -o $@

decode: decode.o codec1.so codec2.so
	$(CXX) $(CXXFLAGS) decode.o -ldl -o $@

encode: encode.o codec1.so codec2.so
	$(CXX) $(CXXFLAGS) encode.o -ldl -o $@




encode.o: encode.c codec.h
	$(CXX) $(CXXFLAGS) -c encode.c

decode.o: decode.c codec.h
	$(CXX) $(CXXFLAGS) -c decode.c

codec1.o: codec1.c codec.h
	$(CXX) $(CXXFLAGS) -c codec1.c -o $@

codec2.o: codec2.c codec.h
	$(CXX) $(CXXFLAGS) -c codec2.c -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) $^ -o $@
%.so: %.o
	$(CXX) -shared -o $@ $<

clean:
	rm -f *.o cmp codec1.so codec2.so copy decode encode f1.txt f2.txt f3.txt f1_link.txt f4.txt f5.txt
