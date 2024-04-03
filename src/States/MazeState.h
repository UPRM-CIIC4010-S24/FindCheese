#include "State.h"
#include "Maze.h"
#include "Button.h"
#include "AbstractSolution.h"
#include "DFSSolution.h"
#include "BFSSolution.h"
#include "RecursionSolution.h"

class MazeState : public State{
    private:

        int selectedMaze = 0;
        ofTrueTypeFont resultFont;
        ofTrueTypeFont uiFont;
        ofTrueTypeFont statisticsFont;

        // Images so that we can toggle between play and pause
        ofImage playButtonImage;
        ofImage pauseButtonImage;

        // Buttons
        Button* playButton;
        Button* forwardButton;
        Button* backwardButton;
        Button* resetButton;
        Button* nextSolutionButton;
        Button* previousSolutionButton;
        Button* seeSolutionButton;

        // Sounds
        ofSoundPlayer loseSound;
        ofSoundPlayer winSound;

        vector<Maze> mazes;

        // Variables for the end; once we reach the end of pathToTake
        bool solved = false;                    // Whether or not we reached the goal of the maze
        bool finishedVisualization = true;     // True when pathIndex == pathToTake.size()
        int secondDelay = 0;                    // A counter that goes to 60
        int transparency = 0;                   // The transparency of the result screen

        // Maze Visualization Variables
        vector<pair<int, int>> pathToTake;      // The path to visualize
        vector<pair<int, int>> explorationPath; // The path taken to explore the maze   
        vector<pair<int, int>> solutionPath;    // The path to take to solve the maze
        int pathIndex = 0;                      // The index of the path to take
        bool visualizeSolution = false;         // Whether or not to visualize the solution
                                                // If false, the exploration path will be visualized
                                                // instead. If true, the solution path will be visualized
        bool autoPlay;                          // Whether or not to automatically play the visualization
        const int AUTO_PLAY_DELAY = 20;         // The delay between each step in the auto play
        int autoPlayCounter;                    // The counter for the auto play delay

        vector<string> mazeAlgorithmNames;


        // Maze Algorithms
        AbstractSolution* solution;             // The solution to use
        vector<AbstractSolution*> solutions;    // The solutions to choose from
        int solutionIndex = 0;                  // The index of the solution to use

        // Functions
        void advancePath();
        void retreatPath();

    public:
        MazeState(vector<Maze> mazes);
        void update();
        void draw();
        void reset();
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
        void setSelectedMaze(int selectedMaze){this->selectedMaze = selectedMaze;};
};