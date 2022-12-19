# Chess in C++

A full Chess implementation in C++. The full set of Chess features are implemented, including pawn-promotion, pawn-double-move and en-passant.

The implementation follows various software design methodologies including the observer and decorator patterns, NVI and visitor method as well as making use of the object-oriented programming paradigm.

The game supports default and custom board setups

default board setup
- sets up the standard 8x8 board of chess with pieces in there standard starting locations

custom setup
- pieces can be placed in any location with exception to:
  - pawns cannot be placed on the first or last row of the board
  - both kings must be placed
  - kings cannot be placed in check
  - no piece can be placed if placing it would place a king in check
  - the game cannot start if it is stalemate

Additional features
- unlimited "undo" commands given that it is possible to actually undo the previous move
- "--help" gives displays all the players current options and can recommend valid moves
- graphical and command-line interface
