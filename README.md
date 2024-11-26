<p align="center">
    <img src=".github/assets/header.png" alt="Sabine's {Library}">
</p>

<p align="center">
    <h3 align="center">A toy compiler named after Sabine.</h3>
</p>

<p align="center">
    <img align="center" src="https://img.shields.io/github/languages/top/sabine-lang/libsabine?style=flat&logo=c&logoColor=ffffff&labelColor=F05045&color=F05045" alt="Top Used Language">
    <a href="https://github.com/sabine-lang/libsabine/actions/workflows/test.yml"><img align="center" src="https://img.shields.io/github/actions/workflow/status/sabine-lang/libsabine/test.yml?style=flat&logo=github&logoColor=ffffff&labelColor=F05045&color=F05045" alt="Test CI"></a>
</p>

## Motivation

C is raw and it needs lotta abstractions to ease the development. Therefore, this repo was created to utilize all necessary implementations as a static library. Currently, the followings are implemented and can be used from your repo:

- buffer.h [[Source]](./include/sabine/buffer.h)
- vector.h [[Source]](./include/sabine/vector.h)

## Development

The project primarily utilizes Nix package manager for development. You need to have Nix package manager
installed on your machine. Lowkey, you migth try running project with your distro's coreutils dev toolchain
but I'm not going to guarantee you anything.

```shell
# This will use your current NixOS'es nixpkgs
nix-shell

# Utilize flake's locked nixpkgs version
nix develop -c $SHELL
```

## Compiling

> There used to be gnu makefile support, now it's gone. Maybe will be back in the future, but I'm not
planning to support further. My bad...

The manual shown below uses LLVM for compilation and development environment has been set up accordingly.

### nix run / nix build

```shell
nix build .
```

### Manual

```shell
mkdir -p ./build
cd ./build
cmake ..
cmake --build .
ls -la ./buld # there should be libsabine.a
```

## License

This project is licensed under WTFPL license which grants you what the fuckever you want. Just don't
roast me posting shit on X. I'm not that nerd of geek as you may think.

<p align="center">
    <img src=".github/assets/footer.png" alt="Sabine's {Library}">
</p>
