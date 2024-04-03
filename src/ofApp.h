#pragma once

#include "ofMain.h"
#include "State.h"
#include "TitleScreenState.h"
#include "MazeSelectionState.h"
#include "MazeState.h"
#include "Maze.h"
#include "Button.h"

class ofApp : public ofBaseApp{

	private:

		// States
		State* currentState;
		TitleScreenState* titleScreenState;
		MazeSelectionState* mazeSelectionState;
		MazeState* mazeState;

		// Openframeworks variables
		ofTrueTypeFont font;
		ofImage background;
		Button* musicButton;
		ofImage musicIcon;
		ofImage muteIcon;
		ofSoundPlayer music;

		
		vector<Maze> mazes;

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
