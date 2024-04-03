#include "AbstractSolution.h"

class BFSSolution : public AbstractSolution{
    public:
        bool solveHelper(
            int x,
            int y,
            Maze &maze,
            vector<pair<int, int>> &solutionPath,
            vector<pair<int, int>> &pathTaken
        );

        void populateSolutionPath(
            map<pair<int, int>, pair<int, int>> &parents,
            pair<int, int> start,
            pair<int, int> end,
            vector<pair<int, int>> &solutionPath
        );
};