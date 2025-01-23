{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  packages = with pkgs; [
    gdb
    clang-tools
  ];
  nativeBuildInputs = with pkgs; [
    cmake
    ninja
  ];
  hardeningDisable = [ "fortify" ];

  # https://nullprogram.com/blog/2023/04/29/
  ASAN_OPTIONS = "abort_on_error=1:halt_on_error=1";
  UBSAN_OPTIONS = "abort_on_error=1:halt_on_error=1";
}
