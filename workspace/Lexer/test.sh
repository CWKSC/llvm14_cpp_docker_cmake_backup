#!/bin/bash
cd out/build

find -name CTestTestfile.cmake \
| sed -e "s|^\./||" -e "s|/CTestTestfile.cmake||" \
| while read path; do
    (
        echo -e "\n\e[32m[$path]\e[0m"
        cd $path
        ctest
        if (($?)); then
            echo -e "\n\e[31m[Failed] Press any key to continue...\e[0m"
            read -p "" < /dev/tty
        fi
        echo 
    )
done


