#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H

void initialize(int width, int height, char symbol);
void return_canvas(int width, int height, char symbol);
void set_canvas_height(int height);
void set_canvas_width(int width);
void set_canvas_symbol(char symbol);
void mid_canvas_horizontal_line(int width);
void mid_canvas_vertical_line(int height);
void mid_canvas_filled_square(int width);
void mid_canvas_empty_square(int width);
void mid_canvas_smiley_face(int width);
void mid_canvas_wide_open_circle(int width);

class ShapeMaker
{
private:
    int canvasWidth;
    int canvasHeight;
    char drawingSymbol;

public:
    // Constructors
    ShapeMaker();
    ShapeMaker(int width, int height, char symbol);

    // Getters
    int getCanvasWidth() const;
    int getCanvasHeight() const;
    char getDrawingSymbol() const;

    // Setters
    void setCanvasWidth(int width);
    void setCanvasHeight(int height);
    void setDrawingSymbol(char symbol);

    // Drawing methods
    void drawHorizontalLine() const;
    void drawVerticalLine() const;
    void drawFilledSquare() const;
    void drawOpenSquare() const;
    void drawSmileyFace() const;
    void drawOpenCircle() const; // BONUS
};


#endif // SHAPE_MAKER_H