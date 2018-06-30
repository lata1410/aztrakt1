//
//  tira.cpp
//  aztrakto1
//
//  Created by Lautaro on 1/6/18.
//
//

#include "tira.hpp"

Tira::Tira(){
	

}

void Tira::setup( int _cantidadPaths, int _cantidadVertices ){
	cantidadVertices = _cantidadPaths;
	cantidadPaths = _cantidadVertices;
	separacion = 0;
	for(int i = 0; i < cantidadPaths; i++){
		ofPath nuevoPath;
		paths.push_back(nuevoPath);
	}
	for(int i = 0; i < paths.size(); i++){
		paths[i].setFilled( false );
		paths[i].setStrokeColor(ofColor(255,255,0));
		paths[i].setStrokeWidth(1);
	}
	posXInicial = ofRandom( ofGetWidth()/2 - (ofGetWidth() - 300 )/2, ofGetWidth()/2 +(ofGetWidth()-300)/2 );
	posYInicial = ofRandom(ofGetHeight()/2 - (ofGetHeight()-200)/2, ofGetHeight()/2 +(ofGetHeight()-200)/2);

	nuevaPosX = 0;
	nuevaPosY = 0;
	for( int c = 0; c < cantidadVertices; c++){
		ofPoint nuevoVertice;
		nuevoVertice.x = ofRandom( ofGetWidth()/2 - (ofGetWidth() - 300 )/2, ofGetWidth()/2 +(ofGetWidth()-300)/2 );
		nuevoVertice.y = ofRandom( ofGetHeight()/2 - (ofGetHeight()-200)/2, ofGetHeight()/2 +(ofGetHeight()-200)/2 );
//		if(lineLine( puntos[c-].x, puntos[c-1].y, <#float x2#>, <#float y2#>, <#float x3#>, <#float y3#>, <#float x4#>, <#float y4#>)){
//		
//		}
		puntos.push_back( nuevoVertice );
	}
}

void Tira::draw(){
	ofSetColor( 0 );
	for (int i = 0; i < cantidadPaths; i++) {
		paths[i].setColor(color);
		paths[i].draw(nuevaPosX, nuevaPosY);
	}
}

void Tira::agregarVertices(){
	for( int i = 0; i < cantidadPaths; i++ ){
		separacion = ofRandom(10, 50);
		for( int z = 0; z < cantidadVertices; z++ ){
			paths[i].lineTo( puntos[z].x + separacion * i  , puntos[z].y + separacion *  i  );
		}
	}
}
void Tira::update( float _nuevaPosX, float _nuevaPosY, ofColor _color){
	nuevaPosX = _nuevaPosX;
	nuevaPosY = _nuevaPosY;
	color = _color;
};
bool Tira::lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	
	// calculate the distance to intersection point
	float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
	float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
	//println(uA);
	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
		
		// optionally, draw a circle where the lines meet
		//float intersectionX = x1 + (uA * (x2-x1));
		//float intersectionY = y1 + (uA * (y2-y1));
		//fill(255,0,0);
		//noStroke();
		//ellipse(intersectionX,intersectionY, 20,20);
		return true;
	}
	return false;
}

























