#!/bin/bash
rm -f ./report/index.html
rm -rf ./report/images
mkdir -p report
echo "<html><body>" >> report/index.html
echo "<h4>cmake output</h4><pre>" >> ./report/index.html
cmake . &>> ./report/index.html
make clean &>> ./report/index.html
echo "</pre>" >> ./report/index.html
echo "<h4>make output</h4><pre>" >> ./report/index.html
make &>> ./report/index.html
echo "</pre>" >> ./report/index.html
echo "<h4>program output</h4><pre>" >> ./report/index.html
./cw1 1  >> ./report/index.html
echo "</pre>" >> ./report/index.html
dir="$(pwd)"
echo "$dir"
parentzip="$(dirname $dir)/generate_$(whoami).zip"
zip -r "$parentzip" .
echo "report written, src & output zipped: now submit $parentzip"
