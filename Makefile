BUILD_DIR := build
CMAKE := cmake
GPROF_FLAFS := -pg
DEBUG_FLAGS := -g

.PHONY: build
build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) ..
	$(MAKE) -C $(BUILD_DIR)

.PHONY: run
run:
	./build/icp-robots

.PHONY: all
all: build run

.PHONY: doxygen
doxygen:
	mkdir -p doc && doxygen Doxyfile

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) html/ doc/
