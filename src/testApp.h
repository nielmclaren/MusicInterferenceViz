#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	/**
	 * @param f Frequency of the note.
	 * @param t The time elapsed since the note started.
	 * @param ox, oy Origin of the sound.
	 * @param px, py The pixel whose value is being calculated.
	 * @return The pixel value in [0,256)
	 */
	unsigned char getNotePixel(float f, float t, int ox, int oy, int px, int py);
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	// Units are pixels per second.
	const float speedOfSound = 100;
	
	int width;
	int height;
	
	ofImage canvas;
	unsigned char* canvasPixels;
	
	string noteNames[88];
	
	// Units are Hz.
	float noteFreqs[88];
	
	// Units are milliseconds.
	unsigned long long startTime;
};
