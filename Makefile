BUILD_DIR := build
CMAKE := cmake
QT_INCLUDE_DIR := /usr/include/x86_64-linux-gnu/qt5
SRC := $(wildcard ../src/**/*.cpp)
HEADER := $(wildcard ../src/**/*.h)

.PHONY: build
build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) ..
	$(MAKE) -C $(BUILD_DIR)

.PHONY: run
run:
	./build/icp-robots

.PHONY: tests
tests:
	cd tests && $(CMAKE) . && $(MAKE) && ./tests

.PHONY: all
all: build run

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) && cd tests/ && rm -rf CMakeFiles cmake_install.cmake CMakeCache.txt Makefile tests