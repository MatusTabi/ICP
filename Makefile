BUILD_DIR := build
CMAKE := cmake

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

.PHONY: setui
setui:
	uic gui.ui -o ui_gui.h

.PHONY: all
all: setui build run

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) && cd tests/ && rm -rf CMakeFiles cmake_install.cmake CMakeCache.txt Makefile tests build-icp-robots-Desktop_Qt_6_6_2_MinGW_64_bit-Debug
