#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	hide = false;
	vecSelAnterior = 0;
	agregarTira.addListener(this, &ofApp::agregarTiraPressed);
	borrarTira.addListener(this, &ofApp::borrarTiraPressed);
	
	gui.setup();
	gui.add(cantidadVertices.setup( "Cantidad de Vertices", 2, 2, 10 ));
	gui.add(cantidadPaths.setup( "Cantidad de Repeats", 2, 2, 10 ));
	gui.add( vectorSelector.setup( "Tira Numero", 0, 0 , 0 ) );
	gui.add( agregarTira.setup( "Nueva Tira" ) );
	gui.add( borrarTira.setup( "Borrar Tira" ) );
	gui.add( cambiar.setup("Cambiar", false));
	gui.add( posicionx.setup("X", 0,  -ofGetWidth(), ofGetWidth()));
	gui.add( posiciony.setup("Y", 0,  -ofGetHeight(), ofGetHeight()));
	gui.add(color.setup("Color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	
}
//--------------------------------------------------------------
void ofApp::exit(){
	agregarTira.removeListener(this, &ofApp::agregarTiraPressed);
}

//--------------------------------------------------------------
void ofApp::update(){
	//Actualizo cuando cambia vectorSelector
	if( tiras.size() > 0 ) {
		if(vectorSelector != vecSelAnterior){
			posicionx = tiras[vectorSelector].nuevaPosX;
			posiciony = tiras[vectorSelector].nuevaPosY;
			color = tiras[vectorSelector].color;
			vecSelAnterior = vectorSelector;
		}
		tiras[vectorSelector].update( posicionx, posiciony, color);

	}
}
//--------------------------------------------------------------
void ofApp::agregarTiraPressed(){
	Tira nuevaTira;
	nuevaTira.setup( cantidadVertices, cantidadPaths );
	nuevaTira.agregarVertices();
	tiras.push_back( nuevaTira );
	vectorSelector.setMax( tiras.size() - 1 );
}

//--------------------------------------------------------------
void ofApp::borrarTiraPressed(){
	if(tiras.size() > 0 ){
		tiras.erase(tiras.begin() + vectorSelector);
		vectorSelector.setMax( tiras.size() - 1 );
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255, 0, 0);
	ofDrawRectangle( ofGetWidth() / 3, ofGetHeight(), ofGetWidth() - 300, ofGetHeight() - 200);
	
	for(int i = 0; i < tiras.size(); i++){
		tiras[i].draw();
	}

	if(!hide){
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if ( key == 'h') {
		hide = !hide;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
