FROM ubuntu:20.04

# LLVM Version
ENV LLVM_VERSION="14"

# Install common package
ENV TZ=Asia/Hong_Kong
RUN apt-get update && apt-get install -y tzdata
RUN apt-get update && apt-get install -y \
  wget \
  lsb-release \
  software-properties-common \
  zlib1g-dev \
  libc++-dev \
  libgtest-dev \
  libssl-dev \
  pkg-config

# Install LLVM 
RUN wget https://apt.llvm.org/llvm.sh
RUN chmod +x llvm.sh 
RUN ./llvm.sh ${LLVM_VERSION} all

# Install cargo
# RUN apt-get update && apt-get install -y cargo
# ENV PATH="${PATH}:/root/.cargo/bin"

# Install sccache
# https://github.com/rust-lang/cargo/issues/7515
# ENV CARGO_HTTP_MULTIPLEXING=false
# RUN cargo install --version 0.3.3 --locked sccache 
# ENV CMAKE_C_COMPILER_LAUNCHER=sccache
# ENV CMAKE_CXX_COMPILER_LAUNCHER=sccache

# Install latest CMake
RUN apt purge --auto-remove cmake && \
  wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | \
  gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null && \
  apt-add-repository 'deb https://apt.kitware.com/ubuntu/ focal main' && \
  apt-get install -y cmake

# Cpp
ENV CC="/bin/clang-${LLVM_VERSION}"
ENV CXX="/bin/clang++-${LLVM_VERSION}"
ENV CPLUS_INCLUDE_PATH="${CPLUS_INCLUDE_PATH}:/usr/include/llvm-${LLVM_VERSION}/:/usr/include/llvm-c-${LLVM_VERSION}/:/workspace/CppIncludeHeader/"

# CMake Config Script
ENV CMakeUtil_DIR="/workspace/CMakeUtil"

# Library Path
ENV RegexUtil_Path="/workspace/RegexUtil/src/RegexUtil/"
ENV InterfaceUtil_Path="/workspace/InterfaceUtil/src/InterfaceUtil/"
ENV PrinterUtil_Path="/workspace/PrinterUtil/src/PrinterUtil/"

ENV InputterUtil_Path="/workspace/InputterUtil/src/InputterUtil/"
ENV ListTreeUtil_Path="/workspace/ListTreeUtil/src/ListTreeUtil/"
ENV CombinatorUtil_Path="/workspace/CombinatorUtil/src/CombinatorUtil/"
ENV SemanticUtil_Path="/workspace/SemanticUtil/src/SemanticUtil/"
ENV TransformerUtil_Path="/workspace/TransformerUtil/src/TransformerUtil/"
ENV LexerCombinatorUtil_Path="/workspace/LexerCombinatorUtil/src/LexerCombinatorUtil/"
ENV LexerUtil_Path="/workspace/LexerUtil/src/LexerUtil/"
ENV ParserCombinatorUtil_Path="/workspace/ParserCombinatorUtil/src/ParserCombinatorUtil/"
ENV ParserUtil_Path="/workspace/ParserUtil/src/ParserUtil/"
ENV LLVMIRUtil_Path="/workspace/LLVMIRUtil/src/LLVMIRUtil"
ENV TypeCheckerUtil_Path="/workspace/TypeCheckerUtil/src/TypeCheckerUtil"
ENV CodeGeneratorUtil_Path="/workspace/CodeGeneratorUtil/src/CodeGeneratorUtil"

ENV MetaLexer_Path="/workspace/MetaLexer/src/MetaLexer/"
ENV MetaParser_Path="/workspace/MetaParser/src/MetaParser/"
ENV Lexer_Path="/workspace/Lexer/src/Lexer/"
ENV Parser_Path="/workspace/Parser/src/Parser/"
ENV TypeChecker_Path="/workspace/TypeChecker/src/TypeChecker/"
ENV CodeGenerator_Path="/workspace/CodeGeneratorUtil/src/CodeGeneratorUtil/"
ENV MetaCompiler_Path="/workspace/MetaCompiler/src/MetaCompiler/"

WORKDIR /workspace
