#pragma once

#include "ofMain.h"

class Button{

    private:
        ofRectangle clickBox;   
        ofTrueTypeFont font;
        string text;
        ofImage image;
        ofColor color;
        const int CLICK_DURATION = 1;
        int clickCount = 0;

    public:

        Button(int centerX, int centerY, int width, int height, string text, ofColor color=ofColor::thistle){
            this->clickBox = ofRectangle(centerX - width/2, centerY - height/2, width, height);
            this->text = text;
            this->font.load("font.otf", 12);
            this->color = color;
        }

        Button(int centerX, int centerY, int width, int height, ofImage image){
            this->clickBox = ofRectangle(centerX - width/2, centerY - height/2, width, height);
            this->image = image;
        }

        ofRectangle getBounds(){
            return clickBox;
        }

        void update(){
            if (clickCount > 0){
                clickCount--;
            }
        }

        void draw(){

            // Draw the image if it exists
            if (this->image.isAllocated()){
                this->image.draw(clickBox);
                return;
            }

            // Draw the button with the text
            ofFill();
            ofSetColor(color);
            ofDrawRectangle(clickBox);
            ofSetColor(ofColor::black);
            font.drawString(text, clickBox.x + clickBox.width/2 - font.stringWidth(text)/2, clickBox.y + clickBox.height/2 + font.stringHeight(text)/2);
            // clear the color
            ofSetColor(ofColor::white);
        }

        void mousePressed(int x, int y){
            if (clickBox.inside(x, y)){
                clickCount = CLICK_DURATION;
            }
        }

        bool wasPressed(){
            return clickCount > 0;
        }

        void setImage(ofImage image){
            this->image = image;
        }

        void setText(string text){
            this->text = text;
        }

        // Constructor
        // wasPressed()
        // onClick()
        // mousePressed(int x, int y)

};