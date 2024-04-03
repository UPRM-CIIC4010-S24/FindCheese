#include "Maze.h"

Maze::Maze(string fileName){

    // Load the images
    remy.load("remy.png");
    remyCheese.load("remy_win.png");
    remyDead.load("remy_lose.png");
    cheese.load("cheese.png");
    this->fileName = fileName;

    reset();
}

void Maze::draw(){
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetLineWidth(3);
    ofSetColor(0);
    ofNoFill();
    ofDrawRectangle(border);

    if (maze.size() == 0)
        ofLogError("Maze::draw") << "Maze is empty";

    if (maze[0].size() == 0)
        ofLogError("Maze::draw") << "Maze row is empty";

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            ofNoFill();
            switch(maze[i][j]){
                case WALL:
                    ofFill();
                case FREE:
                    ofSetColor(0);
                    break;
                case VISITED:
                    ofSetColor(255, 0, 0);
                    break;
                default:
                    ofSetColor(255, 255, 0);
            }

            ofRectangle border(
                this->border.getLeft() + j * cellWidth, 
                this->border.getTop() + i * cellHeight, 
                cellWidth, 
                cellHeight);

            ofDrawRectangle(border);
        }
    }
    // Draw remy at the current position
    ofRectangle border(
        this->border.getLeft() + currentX * cellWidth, 
        this->border.getTop() + currentY * cellHeight, 
        cellWidth, 
        cellHeight);

    ofSetColor(255,255,255);

    // If remy has reached the goal, draw the win image
    if (currentX == goalX && currentY == goalY){
        remyCheese.draw(border);
    }
    else{
        // If remy has lost, draw the lose image
        if (lost)
            remyDead.draw(border);
        else
            remy.draw(border);

        // Draw the goal
        border = ofRectangle(
            this->border.getLeft() + goalX * cellWidth, 
            this->border.getTop() + goalY * cellHeight, 
            cellWidth, 
            cellHeight);
        cheese.draw(border);
    }

}

ofImage Maze::generateMazePreview(){
    ofImage preview;
    preview.allocate(maze[0].size()*50, maze.size()*50, OF_IMAGE_COLOR);
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            ofColor color;
            switch(maze[i][j]){
                case WALL:
                    color = ofColor(0);
                    break;
                case FREE:
                    color = ofColor(255);
                    break;
                case VISITED:
                    color = ofColor(255, 0, 0);
                    break;
                default:
                    color = ofColor(255, 255, 0);
            }

            // Handle special tiles
            if (i == remyX && j == remyY)
                color = ofColor::gray; // Remy
            else if (i == goalY && j == goalX)
                color = ofColor::yellow; // Cheese (goal


            for(int y = 0; y < 50; y++)
                for(int x = 0; x < 50; x++)
                    preview.setColor(j*50 + x, i*50 + y, color);
        }
    }
    preview.update();
    return preview;
}

void Maze::reset(){

    // Clear the maze
    maze.clear();

    // Load the maze from the .txt file
    ofBuffer buffer = ofBufferFromFile(fileName);
    if(buffer.size()){
        for(auto line : buffer.getLines()){                    

            vector<MazeTile> row;
            for(auto tile : ofSplitString(line, " ")){
                MazeTile tileType = (MazeTile)ofToInt(tile);

                // Handle special tiles
                // Special tiles are converted to free tiles
                if (tileType == START){
                    // Set the current position
                    currentX = row.size();
                    currentY = maze.size();

                    // Set the starting position for when we need to reset
                    remyX = currentX;
                    remyY = currentY;
                    tileType = FREE;
                }
                else if (tileType == GOAL){
                    // Set the goal position
                    goalX = row.size();
                    goalY = maze.size();
                    tileType = FREE;
                }
                row.push_back(tileType);
            }

            maze.push_back(row);
        }

        // Set the maze border
        border = ofRectangle(
            ofGetWidth() * .01, 
            ofGetHeight() * .1, 
            ofGetWidth() * .75, 
            ofGetHeight() * .75
        );

        // Set the cell width and height
        cellWidth = border.getWidth() / maze[0].size();
        cellHeight = border.getHeight() / maze.size();
    }

    // Set the lost variable to false
    lost = false;
}

bool Maze::isFree(int x, int y){
    if (x < 0 || x >= maze[0].size() || y < 0 || y >= maze.size())
        return false;
    return maze[y][x] == FREE || maze[y][x] == GOAL;
}

bool Maze::isFree(pair<int, int> pos){
    return isFree(pos.first, pos.second);
}