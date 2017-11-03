#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  int winX, winY, winW, winH;

  ofSetLogLevel(LOGLEVEL);
  ofLogToConsole();
  ofLogVerbose() << "Starting...";
  ofLogVerbose() << "ofApp::setup";

  ofBackground(128, 128, 128, 255);

  cursorImage.load("cursor.png");
}

//--------------------------------------------------------------
void ofApp::update() {
  WiiMouse.processEvents();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255,255,255);
  cursorImage.draw(mouseX, mouseY);
}

void ofApp::exit() {
  ofLog() << "Exiting...";
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
// Mouse moved doesn't fire when mouse dragged does.
  ofLog(OF_LOG_VERBOSE, "mouseMoved x: %d, y: %d", x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
// Mouse drag is mouseMoved with button pressed
  ofLog(OF_LOG_VERBOSE, "mouseDragged x: %d, y: %d, button: %d", x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  ofLog(OF_LOG_VERBOSE, "mousePressed x: %d, y: %d, button: %d", x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  ofLog(OF_LOG_VERBOSE, "mouseReleased x: %d, y: %d, button: %d", x, y, button);
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

void ofApp::wiiMouseConnect() {
  ofLog(OF_LOG_VERBOSE, "Press A + B on wiimote.");
}

void ofApp::wiiMouseConnected(int connected, int found) {
  ofLog(OF_LOG_VERBOSE, "Connected to %i wiimotes (of %i found).", connected, found);
}

//--------------------------------------------------------------
void ofApp::wiiMouseMoved(int x, int y) {
    ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Moved,x,y);
    ofNotifyEvent(ofEvents().mouseMoved,mouseEventArgs);
}

//--------------------------------------------------------------
void ofApp::wiiMouseDragged(int x, int y, int button) {
    ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Dragged,x,y,button);
    ofNotifyEvent(ofEvents().mouseDragged,mouseEventArgs);
  //ofLog(OF_LOG_VERBOSE, "wiiMouseDragged x: %d, y: %d, button: %d", x, y, button);
}

//--------------------------------------------------------------
void ofApp::wiiMousePressed(int x, int y, int button) {

  if (button == WIIMOTE_BUTTON_B) {
      ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Moved,x,y, OF_MOUSE_BUTTON_LEFT);
      ofNotifyEvent(ofEvents().mousePressed,mouseEventArgs);
  } else if (button == WIIMOTE_BUTTON_A) {
      ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Moved,x,y, OF_MOUSE_BUTTON_RIGHT);
      ofNotifyEvent(ofEvents().mousePressed,mouseEventArgs);
  } else  if (button == WIIMOTE_BUTTON_HOME) {
      ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Moved,x,y, OF_MOUSE_BUTTON_MIDDLE);
      ofNotifyEvent(ofEvents().mousePressed,mouseEventArgs);
  }
}

//--------------------------------------------------------------
void ofApp::wiiMouseReleased(int x, int y, int button) {
    if (button == WIIMOTE_BUTTON_B) {
        ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Released, x, y, OF_MOUSE_BUTTON_LEFT);
        ofNotifyEvent(ofEvents().mousePressed, mouseEventArgs);
    } else if (button == WIIMOTE_BUTTON_A) {
        ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Released, x, y, OF_MOUSE_BUTTON_RIGHT);
        ofNotifyEvent(ofEvents().mousePressed, mouseEventArgs);
    } else if (button == WIIMOTE_BUTTON_HOME) {
        ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Released, x, y, OF_MOUSE_BUTTON_MIDDLE);
        ofNotifyEvent(ofEvents().mousePressed, mouseEventArgs);
    }
}
//--------------------------------------------------------------
void ofApp::wiiMouseButtonHeld(int x, int y, int button) {
}


