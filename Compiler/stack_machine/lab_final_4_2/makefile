# 编译器和标志
CXX = g++
CXXFLAGS = -g

# 目标可执行文件
YUYI_EXECUTABLE = yuyi
MACHINE_EXECUTABLE = machine

# 源文件
YUYI_SOURCE = yuyi.cpp
MACHINE_SOURCE = machine.cpp
HEADER = cifa.h

# yuyi 依赖的测试文件
TEST_FILE = ./test.txt

# 默认目标
all: $(YUYI_EXECUTABLE) $(MACHINE_EXECUTABLE)

# 编译 yuyi 可执行文件
$(YUYI_EXECUTABLE): $(YUYI_SOURCE) $(HEADER) $(TEST_FILE)
	$(CXX) $(CXXFLAGS) -o $@ $<

# 编译 machine 可执行文件
$(MACHINE_EXECUTABLE): $(MACHINE_SOURCE) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $<

# 清理生成的文件
clean:
	rm -f $(YUYI_EXECUTABLE) $(MACHINE_EXECUTABLE)

# 运行 yuyi
run1: $(YUYI_EXECUTABLE)
	./$(YUYI_EXECUTABLE) $(TEST_FILE)

# 运行 machine
run2: $(MACHINE_EXECUTABLE)
	./$(MACHINE_EXECUTABLE)

.PHONY: all clean run1 run2