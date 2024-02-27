#!/usr/bin/env bash

pushd ../ > /dev/null
num=$(basename $(pwd))
# echo $num
popd > /dev/null

git add ./ && git commit -m "leetcode $num in rust" && git push
