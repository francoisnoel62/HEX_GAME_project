Hex101 - Command Line Hex Game
==============================
How to create an Hex Game in C language ?


Description
-----------

A command line C language implementation of [Game of Hex](http://en.wikipedia.org/wiki/Hex_(board_game)), with a text interface.

It was created as a requirement of the *Advanced Programming* course at IUT Paris-Descartes, Paris.

This program requires C99 support, which is not always provided by older versions of gcc. 


Sample Game
-----------

    ---------------- HEX -----------------
    
                             1
          0 1 2 3 4 5 6 7 8 9 0
       10  - - - - - - - - - - B  10
         9  - - - - - - - - - W B  9
          8  - - - - W - - W W B -  8
           7  - - - - - W - - W B -  7
            6  - - - - - - - - W B -  6
             5  - - - - - B W - - - -  5
              4  - - - - B W - - - - -  4
               3  - - - - B B B B - - -  3
                2  - - - W W W W B B - -  2
                 1  - - - - - - W W B - -  1
                  0  - - - - - - - - B - -  0
                      0 1 2 3 4 5 6 7 8 9 1
                                           0
    
    ---------------------------------------------
    
    Black just moved (9, 6).
    Player (White) connects horizontally.
    CPU (Black) connects vertically.
    Enter move coordinate X:
