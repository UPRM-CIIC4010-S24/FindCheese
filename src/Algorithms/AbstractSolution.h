#pragma once

#include "Maze.h"
#include <vector>

class AbstractSolution {

    protected:
        /** 
         * This function is called by the solve function. 
         * It should be implemented by the child class
         * and should contain the logic for solving the maze.
         * While solving the maze, the function should update the solutionPath
         * and pathTaken vectors.
        */
        virtual bool solveHelper(
            int x,
            int y,
            Maze &maze,
            vector<pair<int, int>> &solutionPath,
            vector<pair<int, int>> &pathTaken
        ) = 0;

    public:
        AbstractSolution(){}

        /**
         * Solves the maze and updates the solutionPath and pathTaken vectors.
         * 
         * @param maze -- the maze to solve
         * @param solutionPath -- the path taken to solve the maze
         * @param pathTaken  -- the path explored to find the solution
         */
        void solve(Maze maze, vector<pair<int, int>> &solutionPath, vector<pair<int, int>> &pathTaken){
            pair<int, int> start = maze.getStartPosition();

            // Call the helper function to solve the maze
            // The helper function allows us to keep track of what the current position is
            // instead of relying on the user to pass the current position
            solveHelper(
                start.first,
                start.second,
                maze,
                solutionPath,
                pathTaken
            );
        }
};