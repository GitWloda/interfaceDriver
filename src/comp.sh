clear
g++ -c *.h && g++ ./wlodaDriver.cpp -o test &&./test $* 
rm *.gch
