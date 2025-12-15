#include <bits/stdc++.h>
#include <cstdlib>
#include <thread>
#include "input/input.h"
using namespace std;





// variables
long long stage =0;// 0= screen calibrate
long long frame_time = 50;
bool clr_scr =0;
bool clr__scr =0;
vector<vector<char>> screen_char;

bool print_screen = 0;
long long x=3;
long long y=3;
long long sta=0;
stack<string> menu;
string screen;
vector<vector<char>> void_screen(x , vector<char> (y ,' '));
map<string, string> main_menu_data ={{"tittle","WELCOME TO YORK" },{"selecter","0"}};
long long main_menu_selecter=0;

string  conchtos(vector<vector<char>>scn){
    string s;
    for(auto vol:scn){
        for(auto val:vol)s.push_back(val);
        s.push_back('\n');
    }
    return s;    
}
vector<vector<char>> screenresize(long long x , long long y){
    vector<vector<char>> scr(x , vector<char> (y , ' '));
    for(long long i=0 ; i<y ; i++)scr[0][i]='-';
    for(long long i=0 ; i<y ; i++)scr[x-1][i]='-';
    for(long long i=0 ; i<x ; i++)scr[i][0]='|';
    for(long long i=0 ; i<x ; i++)scr[i][y-1]='|';
    return scr;
}
void clearscreen(bool type) {
    if(type){
        cout.flush();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    else {
        cout << "\033[H";
        // cout << "\033[2J\033[H";
        // printer(void_screen);
    }
}

void printer(vector<vector<char>> vec , bool hilou){
    string s=conchtos(vec);  
    if(s!=screen){
        screen =s;
        clearscreen(hilou);
        cout<<screen;
    }
}
void screen_size_limit(){
    clearscreen(1);
    cout<<"this game has been crashed due to limited screen size , please restart the game and claibrate bigger screen";
    this_thread::sleep_for(chrono::milliseconds(5000));
    exit(0);
}
vector<vector<char>> screen_maker(vector<string>&socho){
    vector<vector<char>> dominator = screenresize(x,y);
    long long xo=1;
    for(auto val:socho){
        if(xo+1==x)screen_size_limit();
        long long yo=1;
        for(auto valo:val){
            if(yo+1==y)screen_size_limit();
            dominator[xo][yo]=valo;
            yo++;
        }
        xo++;
    }
    return  dominator;
    
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cout << "\033[?25l";
    screen_char = screenresize(x,y);
    input::event e;
    string k="-";
    menu.push("screen_calibrate");
    cout<<"Calibrate your screen"<<endl<<endl<<"controls-> w,a,s,d , enter , space"<<endl<<endl<<"press enter to start calibrate your screen";
                
    while (true) {
        if(menu.empty()){
            clearscreen(1);
            cout<<"exiting in 5 seconds"<<endl;
            // cout.flush();
            this_thread::sleep_for(chrono::milliseconds(5000));
            return 0;

        }
        if((clr_scr)&&(!print_screen)){
            clearscreen(1);
            clr_scr=0;
        }
        if(clr_scr&&print_screen){
            printer(screen_char , 1);
            clr_scr=0;
            print_screen=0;
        }
        if(clr__scr&&print_screen){
            // clearscreen(0);
            printer(screen_char,0);
            clr_scr=0;
            print_screen=0;
        }
        
        this_thread::sleep_for(chrono::milliseconds(frame_time));
        k="-";

        if (input::pollEvent(e)) {
            if (e.keycode == input::key::Q)break;

            if(e.keycode == input::key::W)k="w";
            if(e.keycode == input::key::A)k="a";
            if(e.keycode == input::key::S)k="s";
            if(e.keycode == input::key::D)k="d"; 
            if(e.keycode == input::key::Enter)k="ent"; 
            if(e.keycode == input::key::Space)k="spc"; 
            // cout<<(int)e.key<<endl;      
            if(e.keycode == input::key::C){
                menu.pop();
                continue;
            }
        
        }
        // cout<<k;
        if(menu.top()=="screen_calibrate"){
            
            if(sta==0){
                if((k=="ent")||(k=="spc")){
                    sta=1;
                    clr_scr=1;
                    print_screen=1;
                }
                
                
            }
            else {
                bool ud=0, ud2=0;
                // cout<<"1";
                if(k=="w"){
                    x = max(3LL , x-1);
                    ud=1;
                    ud2=1;
                }
                else if(k=="s"){
                    x++;
                    ud=1;
                }
                else if(k=="a"){
                    y = max(3LL , y-1);
                    ud=1;
                    ud2=1;
                }
                else if(k=="d"){
                    y++;
                    ud=1;

                }
                else if(k=="ent"){
                    menu.pop();
                    menu.push("main_menu");
                    clearscreen(1);
                }
                
                if(ud){
                    screen_char =screenresize(x,y);
                    if(ud2)clr_scr=1;
                    else clr__scr=1;
                    print_screen=1;
                }
                
            }
        }
        else if(menu.top()=="main_menu"){
            
            vector<string> schco;
            vector<string> options = {"New Game" ,"Continue" ,"Load", "Settings" , "Quit"};
            schco.push_back(main_menu_data["tittle"]);
            schco.push_back("");
            
            for(long long i=0 ; i<options.size() ; i++){
                if(i==main_menu_selecter)schco.push_back("->"+options[i]);
                else schco.push_back(options[i]);
            }
            printer(screen_maker(schco),0);
            if(k=="w")main_menu_selecter--;
            if(k=="s")main_menu_selecter++;
            if(main_menu_selecter>=(long long )options.size())main_menu_selecter=0;
            if(main_menu_selecter<0)main_menu_selecter = (long long )options.size()-1;
            


            
        }

    }
}