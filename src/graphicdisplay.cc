 #include "graphicdisplay.h"

 GraphicDisplay::GraphicDisplay (GameManager &game, int row, int col):
    game{game}, win{(width + 1) * 10, (height + 1) * 10}, width{width}, height{height} {}


// one "block" is a 10x10 pixel square
 void GraphicDisplay::display() {
    win.fillRectangle(x, y, 10, 10, 0);

    // need to see what Bhavya wrote before doing this
    // draw the board and pieces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
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
                win.drawString(x + 5, y + 5, 'e');
            }
        }
    }
 }
