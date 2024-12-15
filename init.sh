#!/bin/bash
function compilation()
{
    cmake -B ./build && cmake --build build
}

function tests()
{
    cd build
    ctest --output-on-failure
    cd ../
}

if [ "$#" -eq 0 ]
then
    compilation
else
    if [ "$1" = "tests" ]
    then
        tests
    else
        compilation
    fi
fi
