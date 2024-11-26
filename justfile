build:
  cmake --build ./build

clean:
  rm -rf ./build

format:
	# I used absolute path because silly me aliased find to ripgrep
	/usr/bin/find . -iname '*.h' -o -iname '*.c' -exec clang-format -style=file -i {} \;
