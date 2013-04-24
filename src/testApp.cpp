#include "testApp.h"

void testApp::setup() {
	width = 800;
	height = 600;
	canvas.allocate(width, height, OF_IMAGE_GRAYSCALE);
	canvasPixels = canvas.getPixels();
	
	ofFile notesFile;
	notesFile.open("notes.csv");
	ofBuffer notesBuffer = notesFile.readToBuffer();

	int i = 0;
	while (!notesBuffer.isLastLine()) {
		vector<string> parts = ofSplitString(notesBuffer.getNextLine(), ",");
		noteNames[i] = parts[1];
		noteFreqs[i] = ofToFloat(parts[2]);
		i++;
	}
	
	cout << noteFreqs[40] << endl;

	startTime = ofGetSystemTime();
}

void testApp::update() {
	float middleC = noteFreqs[40];
	float middleCSharp = noteFreqs[41];
	float middleE = noteFreqs[44];
	float tenorC = noteFreqs[52];
	
	unsigned long long now = ofGetSystemTime();
	
	// Units are seconds.
	float elapsed = (now - startTime) / 1000.0;
	
	int p1x = width * 0.5;
	int p1y = height * 0.5;
	int p2x = width * 0.7;
	int p2y = height * 0.6;
	
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			canvasPixels[y * width + x] =
				getNotePixel(tenorC, elapsed, p1x, p1y, x, y) * 0.25
				+ getNotePixel(middleC, elapsed, p2x, p2y, x, y) * 0.25;
		}
	}
}

void testApp::draw() {
	canvas.setFromPixels(canvasPixels, width, height, OF_IMAGE_GRAYSCALE);
	canvas.draw(0, 0);
}

unsigned char testApp::getNotePixel(float f, float t, int ox, int oy, int px, int py) {
	int dx = px - ox;
	int dy = py - oy;
	float d = sqrt(dx * dx  +  dy * dy);
	
	if (d > speedOfSound * t) {
		// Sound hasn't reached this pixel yet.
		return 0;
	}
	
	return (sin((speedOfSound * t - d) * speedOfSound / f) + 1) / 2 * 255;
}

void testApp::keyPressed(int key) {
}

void testApp::keyReleased(int key) {
}

void testApp::mouseMoved(int x, int y) {
}

void testApp::mouseDragged(int x, int y, int button) {
}

void testApp::mousePressed(int x, int y, int button) {
}

void testApp::mouseReleased(int x, int y, int button) {
}

void testApp::windowResized(int w, int h) {
}

void testApp::gotMessage(ofMessage msg) {
}

void testApp::dragEvent(ofDragInfo dragInfo) {
}