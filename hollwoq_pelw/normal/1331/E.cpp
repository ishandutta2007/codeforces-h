/**
 *    author:  tourist
 *    created: 01.04.2020 18:03:54       
**/
#include <bits/stdc++.h>

using namespace std;

vector<string> s = {
"                          # # ###### #                          ",
"                      # ### # # #  # #####                      ",
"                    ### #   #   ## #    #  #                    ",
"                 #### # # #####    #### # ### #                 ",
"                ##      # #     ####    # # # ##                ",
"              #  ## ##### ### ### #  # ##   #  # #              ",
"             ###  #  #      # #   ####  ## ## ## ##             ",
"           ###### ## ## ### ### ###    ##  #  #   ###           ",
"          ############    #     #   # ##  ## ## #  ###          ",
"         #################### #######  ####  ##########         ",
"        ################################################        ",
"       ##################################################       ",
"       ##################################################       ",
"      ####################################################      ",
"     ######################################################     ",
"     ######################################################     ",
"    ########################################################    ",
"   ##########################################################   ",
"     ########################################################   ",
"       ############   #  ##############   # # #############     ",
"  ##     #########  #   ############### #       ########        ",
"  ####     #####   ## #   ############### ## ##  # ##       ##  ",
" #######     #   ###  ###  ########### #  #   ##         ###### ",
" #########     #  #  ## ##   ######### ## #####  #    ######### ",
" ############ ## ###     ###  #######   #  #    ### ########### ",
" #########     #   ### ###   ######## # ##### #   #  # ######## ",
"############ ### #  #  #   #  ######  #  #    ## ###   #########",
"###########   #  # ## ### ### #### # ### ####  ###   # #########",
"########### ###### ####    #  # #    # #  # ####   ### #########",
"###########     #  #  ### ###   # # ## ## #  #   #  #  #########",
"############ ## #### ## ###   # ###     #### # ###### ##########",
"###########   ###  #  #   ### #  ### ####  # ###   #   #########",
"#############     ## ### ## ### ##     #  ## ##  #   # #########",
"############## ## #    # #    # #  # # ## #   ## ## ############",
"############    #### # # # # #### ## #  # ###  ###   ###########",
"############# #  #   ###   ####   #  ##    #  ##   #############",
"################   ###   # ## ## ## ##  # ### #  #  ############",
"##################   # ######     #######   #   ################",
" ################  #    ##### # ###########   #  ############## ",
" ##############################    ############################ ",
" ########################### #  # ############################# ",
" ######################### #   ################################ ",
"  ########################   #   #############################  ",
"  #######  ################### ###############################  ",
"   ####### # ################   ##################### #######   ",
"   #######   #   ###########  # ########### ##### #    ######   ",
"   ####### # # #  # #   ## # ##  # #  # ##   ##     # #######   ",
"    ########   ##     #       ##   ##      # #  ### ########    ",
"     ####### #  #### #### ###  ###    ### ##### # #########     ",
"     ########## #  #  #   # #### ### ## #     #   #########     ",
"      ########    ## ## #    #   # #    ### #   ##########      ",
"       ######### ##   ##### ## # #   # ##   #############       ",
"       #########  ###  # #   ###   # ###  #   ###########       ",
"        #########   ####   ### ## #### #### ############        ",
"         ######### ##    # #      #    # ##############         ",
"          ############ # #### ## ## # ##  ############          ",
"           #############    ####    #    ############           ",
"             #################### #################             ",
"              ####################################              ",
"                ################################                ",
"                 ##############################                 ",
"                    ########################                    ",
"                      ####################                      ",
"                          ############                          "};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  cout << (s[r][c] == '#' ? "IN" : "OUT") << '\n';
  return 0;
}