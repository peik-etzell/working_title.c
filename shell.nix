{ pkgs ? import <nixpkgs> { } }:
# put clang after clang-tools to make clangd work
pkgs.mkShell {
  buildInputs = with pkgs; [ ccache cmake ninja gdb clang-tools ];

  CMAKE_C_COMPILER_LAUNCHER = "ccache";
  CMAKE_C_FLAGS_DEBUG = "-g -O0";
  CMAKE_GENERATOR = "Ninja";
  CMAKE_EXPORT_COMPILE_COMMANDS = "ON";
}
