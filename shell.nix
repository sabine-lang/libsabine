{
  pkgs ? import <nixpkgs> { },
}:
let
  # Extract the lib folder from a package
  getLibrary = pkg: "${pkg}/lib";
in
pkgs.stdenv.mkDerivation {
  name = "libsabine-shell";

  nativeBuildInputs = with pkgs; [
    # LLVM & Clang toolchain
    cmake
    llvmPackages.llvm
    llvmPackages.clang-tools

    # Hail the Nix
    nixd
    nixfmt-rfc-style

    # Launch scripts
    just
  ];

  # Necessary Environment Variables
  NIX_LDFLAGS = "-L${(getLibrary pkgs.llvmPackages.llvm)}";
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
    pkgs.llvmPackages.llvm
  ];

  shellHook = ''
    echo "$(tput bold)$(tput setaf 4)Time to muse my musy musy!$(tput sgr0)"
    echo "$(tput rev)$(tput setaf 4)You're in LLVM nix shell environment...$(tput sgr0)"

    source ${./.github/scripts/log.sh}

    bootstrap () {
      local _cwp="$(pwd)"
      local _build="$(pwd)/build"

      log "warn" "let's see if build folder is fine..."

      if [ -d "$_build" ]; then
        log "trace" "seems like everything lookin' fine here..."

        return
      fi

      if [ ! -d "$_build" ]; then
        log "warn" "boostrapping build directory..."
        mkdir -p $_build

        # Enter build folder
        cd $_build

        # Bootstrap cmake
        cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

        # Return back
        cd $_cwp
      fi

      return
    }

    bootstrap
  '';
}
