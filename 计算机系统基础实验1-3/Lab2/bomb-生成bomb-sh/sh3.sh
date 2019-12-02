./makebomb.pl -i 201414679 -s ./src -b ./bombs -l bomblab -u dqwang@hust.edu.cn -v 201414679
cd allbombs
mkdir CS201401
cd CS201401
mkdir U201414679
cd ../..
cp ./bombs/bomb201414679/bomb ./allbombs/CS201401/U201414679
cp ./bombs/bomb201414679/bomb.c ./allbombs/CS201401/U201414679
cp ./bombs/bomb201414679/ID ./allbombs/CS201401/U201414679
cp ./bombs/bomb201414679/README ./allbombs/CS201401/U201414679
cd allbombs
zip -r CS201401.zip CS201401
cd ..
