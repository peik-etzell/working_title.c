with import <nixpkgs> { };
# put clang after clang-tools to make clangd work
mkShell { buildInputs = [ cmake ninja gdb clang-tools clang ]; }
