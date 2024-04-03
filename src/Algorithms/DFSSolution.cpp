#include "DFSSolution.h"

bool DFSSolution::solveHelper(
    int x,
    int y,
    Maze &maze,
    vector<pair<int, int>> &solutionPath,
    vector<pair<int, int>> &pathTaken
) {
    // Create a stack to store the coordinates of the cells to visit
    stack<pair<int, int>> toVisit;

    // Create a set to store the coordinates of the cells that have been visited
    set<pair<int, int>> visited;

    // Create a map to store the parent of each cell
    map<pair<int, int>, pair<int, int>> parent;

    // Create a vector to store the possible moves
    vector<pair<int, int>> moves = {
        make_pair(0, 1),    // Down
        make_pair(1, 0),    // Right
        make_pair(-1, 0),   // Left
        make_pair(0, -1)    // Up
    };

    // Add the starting cell to the queue
    toVisit.push(make_pair(x, y));

    // While there are cells to visit
    while (!toVisit.empty()) {
        // Get the coordinates of the cell to visit
        pair<int, int> current = toVisit.top();
        toVisit.pop();

        // If the cell has been visited, skip it
        if (visited.find(current) != visited.end()) {
            continue;
        }

        // Populate the path taken
        pathTaken.push_back(current);

        // If the cell is the end cell
        if (current == maze.getGoalPosition()) {
            // Populate the solution path
            populateSolutionPath(parent, make_pair(x, y), current, solutionPath);
            return true;
        }

        // Add the cell to the set of visited cells
        visited.insert(current);

        // Get the neighbors of the cell
        vector<pair<int, int>> neighbors;

        for (pair<int, int> move : moves) {
            int newX = current.first + move.first;
            int newY = current.second + move.second;

            if (maze.isFree(newX, newY)) {
                neighbors.push_back(make_pair(newX, newY));
            }
        }

        for (pair<int, int> neighbor : neighbors) {
            // If the neighbor has not been visited
            if (visited.find(neighbor) == visited.end()) {
                // Add the neighbor to the queue
                toVisit.push(neighbor);
                // Set the parent of the neighbor to the current cell
                parent[neighbor] = current;
            }
        }
    }

    return false;
}

void DFSSolution::populateSolutionPath(
    map<pair<int, int>, pair<int, int>> &parents,
    pair<int, int> start,
    pair<int, int> end,
    vector<pair<int, int>> &solutionPath
) {
    pair<int, int> current = end;

    while (current != start) {
        solutionPath.push_back(current);
        current = parents[current];
    }

    solutionPath.push_back(start);
    reverse(solutionPath.begin(), solutionPath.end());
}