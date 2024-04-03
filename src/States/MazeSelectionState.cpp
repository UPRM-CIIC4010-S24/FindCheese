#include "MazeSelectionState.h"

void MazeSelectionState::update(){
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->update();
        imageButtons[i]->update();
    }
}

void MazeSelectionState::draw(){

    ofSetColor(ofColor::black);
    // Write "Select a maze" centered at the top of the screen
    font.drawString("Select a maze", ofGetWidth()/2 - font.stringWidth("Select a maze")/2, 30);


    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->draw();
        imageButtons[i]->draw();
    }

}

void MazeSelectionState::reset(){

    State::reset();

    buttons.clear();
    // Create 10 buttons and 10 images
    for (int i = 0; i < 10; i++){

        buttons.push_back(new Button(
            ofGetWidth()/2 +(ofGetWidth()/5 * ((i%5)-2)), 
            ofGetWidth()/3 + ofGetWidth()/3*(i/5),  
            100, 
            50, 
            "Maze " + ofToString(i)
        ));

        imageButtons.push_back(new Button(
            ofGetWidth()/2 +(ofGetWidth()/5 * ((i%5)-2)), 
            ofGetWidth()/3 + ofGetWidth()/3*(i/5)-115,  
            150, 
            150, 
            mazes[i].generateMazePreview()
        ));
    }




}

void MazeSelectionState::mousePressed(int x, int y, int button){
    for (int i = 0; i < buttons.size(); i++){
        buttons[i]->mousePressed(x, y);
        imageButtons[i]->mousePressed(x, y);

        if (buttons[i]->wasPressed() || imageButtons[i]->wasPressed()){
            selectedMaze = i;
            this->setFinished(true);
            this->setNextState(GAME);
        }
    }
}