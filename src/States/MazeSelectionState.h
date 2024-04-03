#include "State.h"
#include <vector>
#include "Button.h"
#include "Maze.h"

class MazeSelectionState : public State {
    private:
        ofTrueTypeFont font;
        vector<Button*> buttons;
        vector<Button*> imageButtons;
        int selectedMaze = -1;
        vector<Maze> mazes;

    public:
        MazeSelectionState(vector<Maze> mazes){
            font.load("font.otf", 24);
            this->mazes = mazes;
            reset();
        }
        void update();
        void draw();
        void reset();
        void mousePressed(int x, int y, int button);
        int getSelectedMaze(){return selectedMaze;};
};