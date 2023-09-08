# llvm14_cpp_docker_cmake_backup

Just a backup, when I try / learn llvm14 with cpp, Docker, and CMake

I remember it is broken, because I am refactoring the code but not finish

I wouldn't look it again, so it just a backup

Created in 2022

```ps1
.\build.ps1
.\up.ps1
.\bash.ps1
```

```shell
./install.sh
```

```shell
cd LexerUtil/
./run.sh
```

Ctrl + D to exit shell

```powershell
./down.ps1
```

## Expected Console Output: 

```
[+] Building 625.8s (13/13) FINISHED                                                                                                                 docker:default
 => [internal] load .dockerignore                                                                                                                              0.0s
 => => transferring context: 2B                                                                                                                                0.0s
 => [internal] load build definition from Dockerfile                                                                                                           0.0s
 => => transferring dockerfile: 3.01kB                                                                                                                         0.0s
 => [internal] load metadata for docker.io/library/ubuntu:20.04                                                                                                2.4s
 => [auth] library/ubuntu:pull token for registry-1.docker.io                                                                                                  0.0s
 => [1/8] FROM docker.io/library/ubuntu:20.04@sha256:33a5cc25d22c45900796a1aca487ad7a7cb09f09ea00b779e3b2026b4fc2faba                                          3.9s
 => => resolve docker.io/library/ubuntu:20.04@sha256:33a5cc25d22c45900796a1aca487ad7a7cb09f09ea00b779e3b2026b4fc2faba                                          0.0s
 => => sha256:6df89402372646d400cf092016c28066391a26f5d46c00b1153e75003465484d 2.30kB / 2.30kB                                                                 0.0s
 => => sha256:edaedc954fb53f42a7754a6e2d1b57f091bc9b11063bc445c2e325ea448f8f68 27.51MB / 27.51MB                                                               2.7s
 => => sha256:33a5cc25d22c45900796a1aca487ad7a7cb09f09ea00b779e3b2026b4fc2faba 1.13kB / 1.13kB                                                                 0.0s
 => => sha256:3246518d9735254519e1b2ff35f95686e4a5011c90c85344c1f38df7bae9dd37 424B / 424B                                                                     0.0s
 => => extracting sha256:edaedc954fb53f42a7754a6e2d1b57f091bc9b11063bc445c2e325ea448f8f68                                                                      1.0s
 => [2/8] RUN apt-get update && apt-get install -y tzdata                                                                                                     55.8s
 => [3/8] RUN apt-get update && apt-get install -y   wget   lsb-release   software-properties-common   zlib1g-dev   libc++-dev   libgtest-dev   libssl-dev    53.1s
 => [4/8] RUN wget https://apt.llvm.org/llvm.sh                                                                                                                1.1s
 => [5/8] RUN chmod +x llvm.sh                                                                                                                                 0.5s
 => [6/8] RUN ./llvm.sh 14 all                                                                                                                                57.6s
 => [7/8] RUN apt purge --auto-remove cmake &&   wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null |   gpg --dearmor - | tee /e  448.0s
 => [8/8] WORKDIR /workspace                                                                                                                                   0.0s
 => exporting to image                                                                                                                                         3.5s
 => => exporting layers                                                                                                                                        3.5s
 => => writing image sha256:34ad7d0dae3f624d68bc99399db2e378970e93e1dc79c4877354c940ef083910                                                                   0.0s
 => => naming to docker.io/library/meta_compiler                                                                                                               0.0s

What's Next?
  View summary of image vulnerabilities and recommendations → docker scout quickview
```

```
[+] Running 2/2
 ✔ Network metacompiler_default      Created                                                                                                                   0.0s 
 ✔ Container MetaCompiler_container  Started   
```

```
root@OwO:/workspace# 
```

```
root@OwO:/workspace# ./install.sh 
[install RegexUtil]
-- The C compiler identification is Clang 14.0.6
-- The CXX compiler identification is Clang 14.0.6
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /bin/clang-14 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /bin/clang++-14 - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (3.1s)
-- Generating done (0.9s)
-- Build files have been written to: /workspace/RegexUtil/out/build
[ 11%] Building CXX object RegexUtil/Structure/RegexMatchResult/CMakeFiles/RegexUtil_Structure_RegexMatchResult.dir/RegexMatchResult.cpp.o
[ 11%] Built target RegexUtil_Structure_RegexMatchResult
[ 22%] Building CXX object RegexUtil/GlobalCache/CMakeFiles/RegexUtil_GlobalCache.dir/GlobalCache.cpp.o
[ 22%] Built target RegexUtil_GlobalCache
[ 33%] Building CXX object RegexUtil/MultiSearch/CMakeFiles/RegexUtil_MultiSearch.dir/MultiSearch.cpp.o
[ 33%] Built target RegexUtil_MultiSearch
[ 44%] Building CXX object RegexUtil/SingleSearch/CMakeFiles/RegexUtil_SingleSearch.dir/SingleSearch.cpp.o
[ 44%] Built target RegexUtil_SingleSearch
[ 55%] Building CXX object RegexUtil/Structure/CaptureGroup/CMakeFiles/RegexUtil_Structure_CaptureGroup.dir/CaptureGroup.cpp.o
[ 55%] Built target RegexUtil_Structure_CaptureGroup
[ 66%] Building CXX object RegexUtil/CMakeFiles/RegexUtil.dir/dummy.cpp.o
[ 77%] Linking CXX static library libRegexUtil.a
[ 77%] Built target RegexUtil
[ 88%] Building CXX object CMakeFiles/Main.dir/main.cpp.o
[100%] Linking CXX executable Main
[100%] Built target Main
[ 11%] Building CXX object RegexUtil/Structure/RegexMatchResult/CMakeFiles/RegexUtil_Structure_RegexMatchResult.dir/RegexMatchResult.cpp.o
[ 11%] Built target RegexUtil_Structure_RegexMatchResult
[ 22%] Building CXX object RegexUtil/GlobalCache/CMakeFiles/RegexUtil_GlobalCache.dir/GlobalCache.cpp.o
[ 22%] Built target RegexUtil_GlobalCache
[ 33%] Building CXX object RegexUtil/MultiSearch/CMakeFiles/RegexUtil_MultiSearch.dir/MultiSearch.cpp.o
[ 33%] Built target RegexUtil_MultiSearch
[ 44%] Building CXX object RegexUtil/SingleSearch/CMakeFiles/RegexUtil_SingleSearch.dir/SingleSearch.cpp.o
[ 44%] Built target RegexUtil_SingleSearch
[ 55%] Building CXX object RegexUtil/Structure/CaptureGroup/CMakeFiles/RegexUtil_Structure_CaptureGroup.dir/CaptureGroup.cpp.o
[ 55%] Built target RegexUtil_Structure_CaptureGroup
[ 66%] Linking CXX static library libRegexUtil.a
[ 77%] Built target RegexUtil
[ 88%] Building CXX object CMakeFiles/Main.dir/main.cpp.o
[100%] Linking CXX executable Main
[100%] Built target Main
Install the project...
-- Install configuration: ""
-- Installing: /usr/lib/libRegexUtil.a
-- Installing: /usr/lib/RegexUtil/cmake/RegexUtilConfig.cmake
-- Up-to-date: /usr/include
-- Installing: /usr/include/RegexUtil
-- Installing: /usr/include/RegexUtil/GlobalCache
-- Installing: /usr/include/RegexUtil/GlobalCache/GlobalCache.h
-- Installing: /usr/include/RegexUtil/include.h
-- Installing: /usr/include/RegexUtil/MultiSearch
-- Installing: /usr/include/RegexUtil/MultiSearch/MultiSearch.h
-- Installing: /usr/include/RegexUtil/SingleSearch
-- Installing: /usr/include/RegexUtil/SingleSearch/SingleSearch.h
-- Installing: /usr/include/RegexUtil/Structure
-- Installing: /usr/include/RegexUtil/Structure/CaptureGroup
-- Installing: /usr/include/RegexUtil/Structure/CaptureGroup/CaptureGroup.h
-- Installing: /usr/include/RegexUtil/Structure/include.h
-- Installing: /usr/include/RegexUtil/Structure/RegexMatchResult
-- Installing: /usr/include/RegexUtil/Structure/RegexMatchResult/RegexMatchResult.h

...
```

```
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [extern]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [sin]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [x]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [extern]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [putchard]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [char]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//]
except [.*
] matchString: [ it is comment
]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [func]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [foo]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [a]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [sin]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [a]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [main]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [if]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [1]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
]
except [ +] matchString: [        ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [putchard]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [42]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [else]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
]
except [ +] matchString: [        ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [putchard]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [43]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [for]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [i]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [1]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [5]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [1]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
]
except [ +] matchString: [        ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] matchString: [putchard]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] matchString: [42]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] matchString: [    ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] fail
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] matchString: [4.0]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] fail
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] matchString: [3.0]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] fail
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] matchString: [3.0]
except [ +] matchString: [ ]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] matchString: [-4.0]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)]
except [ +] fail
except [
]
except [ +] fail
except [
] fail
except [(] fail
except [)] fail
except [{] fail
except [}] fail
except [[] fail
except []] fail
except [,] fail
except [//] fail
except [[+-]?\d*\.\d*] fail
except [[+-]?\d+] fail
except [\"(\\.|[^"\\])*\"] fail
except [\w\w*] fail
expect Any, but text is empty
extern sin(x)
extern putchard(char)
// it is comment
func foo(a) (
    sin a
)
main (
    if 1 (
        putchard 42
    ) else (
        putchard 43
    )
    for i 1 5 1 (
        putchard 42
    )
    * 4.0 (+ 3.0 (- 3.0 -4.0))
)
[extern]
[ ]
[sin]
[(]
[x]
[)]
[
]
[extern]
[ ]
[putchard]
[(]
[char]
[)]
[
]
[//]
[ it is comment
]
[func]
[ ]
[foo]
[(]
[a]
[)]
[ ]
[(]
[
]
[    ]
[sin]
[ ]
[a]
[
]
[)]
[
]
[main]
[ ]
[(]
[
]
[    ]
[if]
[ ]
[1]
[ ]
[(]
[
]
[        ]
[putchard]
[ ]
[42]
[
]
[    ]
[)]
[ ]
[else]
[ ]
[(]
[
]
[        ]
[putchard]
[ ]
[43]
[
]
[    ]
[)]
[
]
[    ]
[for]
[ ]
[i]
[ ]
[1]
[ ]
[5]
[ ]
[1]
[ ]
[(]
[
]
[        ]
[putchard]
[ ]
[42]
[
]
[    ]
[)]
[
]
[    ]
[*]
[ ]
[4.0]
[ ]
[(]
[+]
[ ]
[3.0]
[ ]
[(]
[-]
[ ]
[3.0]
[ ]
[-4.0]
[)]
[)]
[
]
[)]
[
]
```
