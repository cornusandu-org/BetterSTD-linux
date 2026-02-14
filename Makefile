CC = g++
CAR = gcc-ar
CXXFLAGS = -Wall -O0 -Iinclude/bstd -Iinclude -std=gnu++23

SOURCES := $(shell find ./src -name "*.cpp")

.PHONY: all
.PHONY: build
.PHONY: devtest
.PHONY: clean
.PHONY: clear

all: build
	@printf "\n===== Linking =====\n"
	@printf "\n"
	@printf "[/] Creating static archive\r"
	@{ $(CAR) rcs bstdl.a $(shell find ./tmp -name "*.o") 2>rcs.log; } || { printf "[-] Failed to create static archive\n\n"; cat rcs.log; exit 1; } 
	@printf "[+] Created static archive         \n"
	@mkdir -p dist
	@mv bstd.a dist/bstdl.a

build:
	@mkdir -p tmp
	@printf "\n===== Building =====\n\n"
	@for item in $(SOURCES); do \
		printf "[/] Building $$item\r"; \
		{ $(CC) $(CXXFLAGS) -c $$item 2>log.txt; } || { printf "[-] Failed to build $$item        \n\n"; cat log.txt; exit 1;}; \
		printf "[+] Built $$item          \n"; \
	done

devtest:
	@$(CC) tests/test.cpp dist/bstd_linux.a -Iinclude -o test -O0
	
	@if ./test; then \
	    printf "\n\n\nTests succeeded/passed\n"; \
	else \
	    printf "\n\n\nTests failed\n"; \
	    exit 1; \
	fi

clean:
	@rm -f *.o
	@rm -f $(shell find . -name "*.o")
	@rm -f ./*log*
	@mkdir -p tmp

clear: clean
	@rm -rf $(shell find ./dist -name '*.a') $(shell find ./tmp)
	@rm -f test
	@mkdir -p tmp
