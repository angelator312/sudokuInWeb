# Setup some variables
ifeq (, $(shell which podman 2> /dev/null))
ifeq (, $(shell which docker 2> /dev/null))
$(error "No docker or podman in $(PATH), install podman or docker")
else
CRT = docker
USERNS = host
endif
else
CRT = podman
USERNS = keep-id
endif


all:sudoku-main html/sudoku.js

html/sudoku.js: sudoku-js.cpp Board.hpp Index.hpp
	mkdir -p html
	$(CRT) run --rm -v `pwd`:/src:z -u `id -u`:`id -g` --userns=$(USERNS) emscripten/emsdk emcc -lembind $< -o $@
	cp index.html html

%:%.cpp Board.hpp Index.hpp
	clang++ $<  -g -o $@