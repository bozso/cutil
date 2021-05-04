.PHONY: build tags

build:
	xmake build

tags:
	xmake project -k compile_commands
