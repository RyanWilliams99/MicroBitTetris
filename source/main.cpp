/**
 * File: main.cpp
 * Author: Ryan Williams
 * Date: 02-01-2019
 * Desc: Tetris in c++ on a MicroBit
 */
#include "MicroBit.h"

MicroBit uBit;

void displayArray();
void removeRow(int);

bool pressedA = false; //Set to false initially
bool pressedB = false;

void onButtonA(MicroBitEvent) //On button a
{
    pressedA = true;
}

void onButtonB(MicroBitEvent)
{
    pressedB = true;
}

int piecePostionColumn = 0; //Current falling piece position
int piecePostionRow = 0;
int x; //Used in for loops
int y;
int i;
int score; //Player score
int temp; //Used in removeRow Function
int display[5][5]; //Used to store where which pixels should be turned on

int main()
{
    uBit.display.scroll("GET READY");
    //Listens for button presses
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA, MESSAGE_BUS_LISTENER_IMMEDIATE);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB, MESSAGE_BUS_LISTENER_IMMEDIATE);
    uBit.init(); //Initialise

    while(1)
    {
        uBit.display.image.setPixelValue(piecePostionColumn,piecePostionRow - 1,0); //Delete old player pixel
        displayArray(); //Display current layout
        uBit.sleep(150 - score * 5); //Sleep less based on how much score

        if(pressedA && display[piecePostionRow][piecePostionColumn - 1] == 0 && piecePostionColumn - 1 > -1) //If A pressed move left
        {
            piecePostionColumn--; //Move piece left if button a is pressed
            pressedA = false;
        }
        else if(pressedB && display[piecePostionRow][piecePostionColumn + 1] == 0 && piecePostionColumn + 1 < 5) //If B pressed move piece right
        {
            piecePostionColumn++;
            pressedB = false;
        }

        uBit.display.image.setPixelValue(piecePostionColumn,piecePostionRow,255); //Set Piece pixel on
        uBit.sleep(150 - score * 5);
        if (display[piecePostionRow + 1][piecePostionColumn] == 0 && piecePostionRow != 4) //If next pixel empty && not at bottom
        {
            piecePostionRow++; //Move Down
        }
        else //If next pixel is 1 or at the bottom, Add piece to display array
        {
            display[piecePostionRow][piecePostionColumn] = 1;
            piecePostionColumn = rand() % 5; //Get random number for new piece position
            piecePostionRow = 0;
            if (display[piecePostionRow + 1][piecePostionColumn] == 1) //If new piece is on column with 4 pieces player died
            {
                uBit.display.image.setPixelValue(piecePostionColumn,piecePostionRow,255);
                uBit.sleep(2000);
                uBit.display.scroll("DIED SCORE:");
                uBit.display.scroll(score);
                uBit.display.scroll("TILT TO RESTART");
                while(1) //Make user tilt MicroBit to restart
                {
                    if (uBit.accelerometer.getX() > 750 || uBit.accelerometer.getX() < -750) //Getting x value from accelerometer
                        uBit.reset(); //Same as pressing reset button
                }
            }

        }
        for (i = 4; i > -1; i--) //Checking to see if a row has 5 on pixels start from bottom
        {
            if (display[i][0] == 1 && display[i][1] == 1 && display[i][2] == 1 && display[i][3] == 1 && display[i][4] == 1)
            {
                score++;
                for (x = 0; x < 5; x++)
                {
                    display[i][x] = 0; //If it does turn all of and call remove row
                }
                removeRow(i); //Call removeRow
            }
        }
    }
}

void removeRow(int rowToBeRemoved) //Takes a int as to which row to remove
{
    for (x = rowToBeRemoved - 1; x > -1; x--) //Every row above should fall down
    {
        for (y = 0; y < 5; y++)
        {
            temp = display[x][y];
            display[x + 1][y] = temp; //Set to whatever the value above was
        }
    }
}

void displayArray() //Displays the 5x5 array to respective LEDs, usually after being updated by remove row etc
{
    for (x = 0; x < 5; x++) //For every row
    {
        for (y = 0; y < 5; y++) //For every column
        {
            if (display[y][x] == 1) //If value is 1 turn on respective pixel
            {
                uBit.display.image.setPixelValue(x,y,255);
            }
            else
            {
                uBit.display.image.setPixelValue(x,y,0);
            }
        }
    }
}