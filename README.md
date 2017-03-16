# tron-clone
Hello, I see you have come across my only working, completely bug free, simple game.<br>
tron-clone is exactly what it says on the tin. It is a remake of the game tron.<hr>

# Disclaimers:
* This repository was created as a simple test of my C++ and SDL skills. I attempt to make use of the best practises yet I have a long way to go.
* This repository does have SDL and cmake as dependencies, so, if you do not have them and still wish to play my (underwhelming) game, please install them.
* This repository has only been tested on Mac OSX, as for Linux I believe it should work and as for Windows, if used with Cygwin the game should (in theory) run properly.

# Quickstart guide:
To begin playing clone the repository using this command:
```
git clone https://github.com/Balajanovski/tron-clone.git
```
Enter the directory via command line then type:
```
cmake .
```
Doing this generates a makefile using your system's C++ compiler, linking all required libraries in the process as well.<br>
To build the binary file type:
```
make
```
And to play just run
```
./Tron
```
Enjoy!


**Note:**<br>
Uses SDL
