{
  description = "Project devshell";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            gdb
            valgrind
            clang-tools
          ];
          nativeBuildInputs = with pkgs; [ gnumake ];
          hardeningDisable = [ "fortify" ];

          # https://nullprogram.com/blog/2023/04/29/
          ASAN_OPTIONS = "abort_on_error=1:halt_on_error=1";
          UBSAN_OPTIONS = "abort_on_error=1:halt_on_error=1";
        };
      }
    );
}
