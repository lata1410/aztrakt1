//
//  tira.hpp
//  aztrakto1
//
//  Created by Lautaro on 1/6/18.
//
//

#ifndef tira_hpp
#define tira_hpp

#include <stdio.h>
#include "ofMain.h"

class Tira {
public:
	Tira();
	vector<ofPath> paths;
	vector<ofPoint> puntos;
	float cantidadVertices, cantidadPaths, separacion;
	void setup( int _cantidadPaths, int _cantidadVertices), draw(), agregarVertices(), update( float _nuevaPosX, float _nuevaPosY, ofColor _color);
	bool lineLine( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4 );
	float posXInicial = ofRandom(ofGetWidth()), posYInicial = ofRandom(ofGetHeight());
	float nuevaPosX, nuevaPosY;
	ofColor color;
};

#endif /* tira_hpp */
