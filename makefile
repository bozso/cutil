.PHONY: build tags

build:
	xmake f -m debug
	xmake build

release:
	xmake f -m release
	xmake build

tags:
	xmake project -k compile_commands
