 #include "graphicdisplay.h"

 GraphicDisplay::GraphicDisplay (GameManager &game):
    game{game}, win{height, width} {}


// one "block" is a 10x10 pixel square
 void GraphicDisplay::display() {
    // draw column and row coordinates
    // need to see what Bhavya wrote before doing this
    // draw the board and pieces
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            char tile = game.getTile(i - 1, j - 1);
            int x = j * 10;
            int y = i * 10;
            if (i + j % 2 == 0) {
                win.fillRectangle(x, y, 10, 10, 3);
            }
            else {
                win.fillRectangle(x, y, 10, 10, 0);
            }
            if (tile != ' ' && tile != '_') {
                //std::string msg = (1, tile);
                win.drawString(x + 5, y + 5, "e");
            }
        }
    }
 }
