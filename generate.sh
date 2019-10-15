rm ./index.html
rm -rf ./images
echo "<html><body>" >> index.html
echo "<h4>cmake</h4><pre>" >> index.html
cmake . >> index.html
echo "</pre>" >> index.html
echo "<h4>make</h4><pre>" >> index.html
make clean
make >> index.html
echo "</pre>" >> index.html
./cw1 1

