#include <bits/stdc++.h>
#include <cstdlib>
#include <thread>
#include "input/input.h"
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


using namespace std;
int main(){
    Input::Event e;

    while (true) {




        
        if (Input::pollEvent(e)) {
            if (e.key == Input::Key::Q)
                break;

            if (e.key == Input::Key::Up)
                std::cout << "UP\n";
            if(e.key == Input::Key::W)
                cout<<"w"<<endl;

            if(e.key == Input::Key::C)clearScreen();
        }
    }
}