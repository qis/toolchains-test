system = linux

all: all/$(system)

all/linux:
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-linux
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-linux-llvm

all/windows:
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-static
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-msvc
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-llvm

install: install/$(system)

install/linux:
	@$(MAKE) -f makefile.triplet system=$(system) overlay=/opt/ports triplet=x64-linux install
	@$(MAKE) -f makefile.triplet system=$(system) overlay=/opt/ports triplet=x64-linux-llvm install

install/windows:
	@$(MAKE) -f makefile.triplet system=$(system) overlay=C:\Workspace\ports triplet=x64-windows install
	@$(MAKE) -f makefile.triplet system=$(system) overlay=C:\Workspace\ports triplet=x64-windows-static install
	@$(MAKE) -f makefile.triplet system=$(system) overlay=C:\Workspace\ports triplet=x64-windows-msvc install
	@$(MAKE) -f makefile.triplet system=$(system) overlay=C:\Workspace\ports triplet=x64-windows-llvm install

run: run/$(system)

run/linux:
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-linux run
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-linux-llvm run

run/windows:
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows run
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-static run
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-msvc run
	@$(MAKE) -f makefile.triplet system=$(system) triplet=x64-windows-llvm run

format:
	@cmake -P format.cmake

clean:
	@cmake -E remove_directory build
