.PHONY: build tags

build:
	xmake f -m debug
	xmake build

release:
	xmake f -m release
	xmake build

test:
	xmake f -m debug
	xmake build test
	xmake run test

doc:
	xmake doxygen --outputdir=doc

tags:
	xmake project -k compile_commands
