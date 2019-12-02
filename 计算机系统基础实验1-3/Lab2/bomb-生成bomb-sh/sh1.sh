./makebomb.pl -i 201414679 -s ./src -b ./bombs -l bomblab -u dqwang@hust.edu.cn -v 201414679
cd allbombs
mkdir bomb201414679
cd ..
cp ./bombs/bomb201414679/bomb ./allbombs/bomb201414679
cp ./bombs/bomb201414679/bomb.c ./allbombs/bomb201414679
cp ./bombs/bomb201414679/ID ./allbombs/bomb201414679
cp ./bombs/bomb201414679/README ./allbombs/bomb201414679
cd allbombs
zip -r 201414679.zip bomb201414679
cd ..