#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "tira.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	void agregarTiraPressed(), borrarTiraPressed();
	vector<Tira> tiras;
	
//	ofxFloatSlider radius;
//	ofxColorSlider color;
//	ofxVec2Slider center;
//	ofxIntSlider circleResolution;
//	ofxToggle filled;
//	ofxButton twoCircles;
//	ofxButton ringButton;
//	ofxLabel screenSize;
//
	bool hide;
	ofxIntSlider cantidadVertices, cantidadPaths, vectorSelector;
	ofxButton agregarTira, borrarTira;
	ofxFloatSlider posicionx, posiciony;
	ofxColorSlider color;
	ofxToggle cambiar;
	ofxPanel gui;
	
	int vecSelAnterior;
};
