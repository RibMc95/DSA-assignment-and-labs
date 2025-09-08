// Redone implementation for ShapeMaker
#include <iostream>
#include "shapemaker.h"
using namespace std;

// Constructors
ShapeMaker::ShapeMaker() : canvasWidth(21), canvasHeight(21), drawingSymbol('*') {}
ShapeMaker::ShapeMaker(int width, int height, char symbol)
    : canvasWidth(width), canvasHeight(height), drawingSymbol(symbol) {}

// Getters
int ShapeMaker::getCanvasWidth() const { return canvasWidth; }
int ShapeMaker::getCanvasHeight() const { return canvasHeight; }
char ShapeMaker::getDrawingSymbol() const { return drawingSymbol; }

// Setters
void ShapeMaker::setCanvasWidth(int width) { canvasWidth = width; }
void ShapeMaker::setCanvasHeight(int height) { canvasHeight = height; }
void ShapeMaker::setDrawingSymbol(char symbol) { drawingSymbol = symbol; }

// Drawing methods
void ShapeMaker::drawHorizontalLine() const
{
    int mid = canvasHeight / 2;
    for (int i = 0; i < canvasHeight; ++i)
    {
        if (i == mid)
        {
            for (int j = 0; j < canvasWidth; ++j)
            {
                cout << drawingSymbol;
            }
        }
        else
        {
            for (int j = 0; j < canvasWidth; ++j)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void ShapeMaker::drawVerticalLine() const
{
    int mid = canvasWidth / 2;
    for (int i = 0; i < canvasHeight; ++i)
    {
        for (int j = 0; j < canvasWidth; ++j)
        {
            if (j == mid)
            {
                cout << drawingSymbol;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void ShapeMaker::drawFilledSquare() const
{
    int size = std::min(canvasWidth, canvasHeight);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << drawingSymbol;
        }
        cout << endl;
    }
}

void ShapeMaker::drawOpenSquare() const
{
    int size = std::min(canvasWidth, canvasHeight);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                cout << drawingSymbol;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void ShapeMaker::drawSmileyFace() const
{
    int size = std::min(canvasWidth, canvasHeight);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                cout << drawingSymbol;
            // Eyes
            else if ((i == size / 3 && (j == size / 3 || j == 2 * size / 3)))
                cout << 'O';
            // Nose
            else if (i == size / 2 && j == size / 2)
                cout << '^';
            // Mouth
            else if (i == 2 * size / 3 && j > size / 3 && j < 2 * size / 3)
                cout << '_';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

void ShapeMaker::drawOpenCircle() const
{
    int size = std::min(canvasWidth, canvasHeight);
    int r = size / 2;
    int cx = r, cy = r;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int dx = i - cx, dy = j - cy;
            int dist = dx * dx + dy * dy;
            if (dist >= r * r - r && dist <= r * r + r)
            {
                cout << drawingSymbol;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main()
{
    ShapeMaker sm;
    cout << "Default Canvas: " << sm.getCanvasWidth() << "x" << sm.getCanvasHeight() << ", Symbol: " << sm.getDrawingSymbol() << endl;
    cout << "\nHorizontal Line:\n";
    sm.drawHorizontalLine();
    cout << "\nVertical Line:\n";
    sm.drawVerticalLine();
    cout << "\nFilled Square:\n";
    sm.drawFilledSquare();
    cout << "\nOpen Square:\n";
    sm.drawOpenSquare();
    cout << "\nSmiley Face:\n";
    sm.drawSmileyFace();
    cout << "\nOpen Circle:\n";
    sm.drawOpenCircle();

    // Custom canvas
    ShapeMaker custom(15, 15, '#');
    cout << "\nCustom Canvas: " << custom.getCanvasWidth() << "x" << custom.getCanvasHeight() << ", Symbol: " << custom.getDrawingSymbol() << endl;
    cout << "\nHorizontal Line:\n";
    custom.drawHorizontalLine();
    cout << "\nVertical Line:\n";
    custom.drawVerticalLine();
    cout << "\nFilled Square:\n";
    custom.drawFilledSquare();
    cout << "\nOpen Square:\n";
    custom.drawOpenSquare();
    cout << "\nSmiley Face:\n";
    custom.drawSmileyFace();
    cout << "\nOpen Circle:\n";
    custom.drawOpenCircle();
    return 0;
}
