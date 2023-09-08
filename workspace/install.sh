#!/bin/bash

function install() {
    (
        echo "[install $1]"
        cd $1
        ./clean.sh
        ./cmake.sh
        ./build.sh
        ./install.sh
        echo 
    )
}

install RegexUtil
install InterfaceUtil
install ListTreeUtil

install CombinatorUtil

install LexerCombinatorUtil
install LexerUtil

install ParserCombinatorUtil
install ParserUtil

