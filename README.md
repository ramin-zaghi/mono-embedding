### == Description ==
This is a fork of https://github.com/shana/mono-embedding which shows how you can embed the Mono virtual machine runtime into your C/C++ projects.

I have changed the original code which targeted Windows and Microsoft Visual Studio to enable building on Mac OSX.

You should also be able to build this on any platform which supports variations of the GNU GCC toolchain (Linux and Windows included).

### == Prerequisites ==
Please apply the following two patches and build a copy of the upstream Mono runtime, which can be located at [https://github.com/mono/mono](https://github.com/mono/mono)

The two patches you will need can be found at:
[https://github.com/mono/mono/compare/4cb3f77b4bbf703b1cda59db2f5aee206e35d31a...shana:embedding](https://github.com/mono/mono/compare/4cb3f77b4bbf703b1cda59db2f5aee206e35d31a...shana:embedding)

You will also need to have the tools used on the command line in the build section below.

### == How to build on Mac OSX ==
~~~~
PREFIX=/path/to/your/mono/installation
MONO_EMBEDDING=/path/to/your/clone/of/mono-embedding
export PATH=$PREFIX/bin:$PATH

cd "${MONO_EMBEDDING}/Bootstrap/"

GCCFLAGS=`pkg-config --cflags --libs mono-2`

# NOTE: The -m32 option below must match how you build your Mono runtime
g++ -m32 -std=c++11 *.cpp $GCCFLAGS -o bootstrap

cd "${MONO_EMBEDDING}/Bootstrap/Managed/"
$PREFIX/bin/mcs EmbedThings.cs /target:library
~~~~

### == How to run on Mac OSX ==
All you need to run this on Mac OSX is to run the &quot;bootstrap&quot; from the build step and pass the directory where it can find the ./mono/ directory of your build of the Mono runtime excluding the /mono/ itself from the path.

e.g.
~~~~
$ cd Bootstrap/
$ ./bootstrap /path/to/where/your/mono/is # Do not include the /mono/ iteself
~~~~
