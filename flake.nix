{
  #    _____       __    _               __    _ __
  #   / ___/____ _/ /_  (_)___  ___     / /   (_) /_  _________ ________  __
  #   \__ \/ __ `/ __ \/ / __ \/ _ \   / /   / / __ \/ ___/ __ `/ ___/ / / /
  #  ___/ / /_/ / /_/ / / / / /  __/  / /___/ / /_/ / /  / /_/ / /  / /_/ /
  # /____/\__,_/_.___/_/_/ /_/\___/  /_____/_/_.___/_/   \__,_/_/   \__, /
  #                                                                /____/
  #          A library for toy compiler written from scratch on C
  description = "Building necessary implementations for a compiler named Sabine";

  # Repos
  inputs = {
    # If you want something stable
    # nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-24.05";

    # If you want fresh deps out of oven
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";

    # A few useful nix functions for painless flake management
    utils.url = "github:numtide/flake-utils";
  };

  outputs =
    { self
    , nixpkgs
    , utils
    } @ inputs:
    utils.lib.eachDefaultSystem
      (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        # Nix script formatter
        formatter = pkgs.nixfmt-rfc-style;

        # Development environment
        devShells = {
          default = import ./shell.nix { inherit pkgs; };
        };

        # Output packages
        packages.default = pkgs.callPackage ./. { };
      })

    // # and

    # Possible static attrsets (just in case for the future)
    { };
}
