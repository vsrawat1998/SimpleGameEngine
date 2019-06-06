#include "MainGame.h" // Includes the class MainGame to support basic game operations
#include<iostream>
using namespace std;
int main(int argc,char** argv) { // The parameters are required so that the SDL main()
	// does not clash with this main()

	MainGame mainGame;
	mainGame.run();
	cout << "Enter any key to quit!!!";
	char a;
	cin >> a; 
	return 0;
}