#include "textdisplay.h"
#include "observer.h"

TextDisplay::TextDisplay (GameManager &game):
    game{game}, win{height, width} {}

void TextDisplay::display(){
    for (int i = 0; i <= row; i++){
        if (i == 9){ //prints blank line before printing column letters
            out << std::endl;
            continue;
        }

        for (int j = 0; j < col; j++){
            if (j == 0 && sidenums > 0){ //prints the row numbers
                out << sidenums << " ";
                sidenums -= 1;
            } else if (j == 0 && sidenums == 0){ // special case when printing column letters
                out << "  ";
            }else if (j == 8){ // prints the column letters
                out << bottomletters;
                bottomletters += 1;            
            } else{
                //out << getTile();
            }
        }
        out << std::endl; //prints new line to go to next row
    }
}


