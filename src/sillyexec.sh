#!/bin/bash

mkexecall="make all"
mkexecrun="make run"
chrformat="\033[3;36m"

echo    -e ${chrformat}
echo    -e "compiling to binaries..."
$mkexecall
echo    -e
echo    -e "export the environment variable where the tockend is hosted"
export $(cat .env | xargs)
echo    -e "done!!"
echo    -e

echo    -e "exec..."
$mkexecrun