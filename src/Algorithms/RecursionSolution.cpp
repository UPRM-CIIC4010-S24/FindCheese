#include "RecursionSolution.h"

bool RecursionSolution::solveHelper(
    int x,
    int y,
    Maze &maze,
    vector<pair<int, int>> &solutionPath,
    vector<pair<int, int>> &pathTaken
) {

    // Push the current cell to the path taken
    pathTaken.push_back(make_pair(x, y));
    solutionPath.push_back(make_pair(x, y));

    // Base case: We have reached the goal
    pair<int, int> goal = maze.getGoalPosition();
    if (x == goal.first && y == goal.second) {
        return true;
    }

    // Mark the current cell as visited
    // This way, we avoid infinite loops
    maze.setTile(x, y, MazeTile::VISITED);

    // Recursive case: Try all possible moves
    vector<pair<int, int>> possibleMoves = {
        make_pair(x, y-1),  // Up
        make_pair(x-1, y),  // Left
        make_pair(x+1, y),  // Right
        make_pair(x, y+1)   // Down
    };

    for (auto move : possibleMoves) {
        if (maze.isFree(move.first, move.second)) {
            if (solveHelper(move.first, move.second, maze, solutionPath, pathTaken)) {
                return true;
            }
        }
    }

    // If we reach this point, we have to backtrack
    solutionPath.pop_back();
    return false;
}