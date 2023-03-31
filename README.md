A tiny example project to use cmake with some external libraries.

### Usage
Run `cmake ..` inside `./build/` to create the `./build/Makefile` and then `make` inside `./build/` to create the libraries and the executables. The executables can be then found inside `./build/examples/` and `./build/tests/`. All the tests can be executed using the `ctest` command inside `./build/tests/`


### Dependencies
CGAL and googletest are Fetched inside `./build/_deps/` but the dependencies of CGAL should already be in the system.


### Folder structure:
* `./include/<libname>/`        : The header files for the <libname> library.
* `./src/`                      : All source files needed for the libraries (none yet).
* `./examples/`                 : Any examples using the libraries.
* `./tests/`                    : Unit tests for the functions defined (using the external gtest library).


### basic cmake functions used:
* `add_subdirectory(<dir>)`                             : Parse `./<dir>/CMakeLists.txt`
* `add_library(<lib> <SCOPE> <cpp-files>)`              : Define target named `<lib>` to be a library developed in `<cpp-files>`
* `target_include_libraries(<lib> <SCOPE> <path>)`      : The header files of the library target `<lib>` can be found in `<path>`
* `add_executable(<exec> <SCOPE> <cpp-files>)`          : Define target named `<exec>` to be an executable developed in `<cpp-files>`
* `target_link_libraries(<exec> <SCOPE> <lib>)`         : The executable target `<exec>` uses the library target `<lib>`


### TODOs
* Explicitly list CGAL deps and try to fetch everything needed.
* Before fetching an external library test if it already exists in the system.
* Disable `gmock`, since it is not (yet) needed for the tests.
* Expand the root `CMakeLists.txt` to:
    * Include warning flags for the compiler.
    * Be cross platform.
    * Protect user from running cmake in the root folder.
    * ...
* Check that the usage of every `<SCOPE>=PUBLIC|PRIVATE|INTERFACE` makes sense.
* Add comments.
* Examine how the googletest library is used and decide if every command is useful.

