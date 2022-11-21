CXX=gcc
CXXFLAGS= -Werror -Wsign-conversion

run: cmp codec1 codec2 copy decode encode

cmp: cmp.c
	$(CXX) $(CXXFLAGS) $^ -o $@

demo: Demo.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Renana Rimon
StudentTest1.cpp:  
	curl https://raw.githubusercontent.com/renanarimon/cpp_5b_test/master/Test.cpp > $@

# Shauli Taragin
StudentTest2.cpp: 
	curl https://raw.githubusercontent.com/ShauliTaragin/Orgchart-A/main/Test.cpp > $@

# Dvir Gev
StudentTest3.cpp: 
	curl https://raw.githubusercontent.com/dvirGev/CPP--Ex5-par1/main/Test.cpp > $@

tidy:
	clang-tidy $(SOURCES) $(TIDY_FLAGS) --

valgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(OBJECTS) *.o test* 
	rm -f StudentTest*.cpp
