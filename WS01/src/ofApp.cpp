#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    receiver.setup(8888);
    scene = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage message;
        receiver.getNextMessage(message);
        value = message.getArgAsFloat(0);
        items = ofSplitString(message.getAddress(), "/");
        address = ofToChar(items.back());
        cout << address << '\n';
        switch (address) {
            case 'a' : fader01 = value; break;
            case 'b' : fader02 = value; break;
            case 'c' : fader03 = value; break;
            case '1' : scene = 1; break;
            case '2' : scene = 2; break;
            case '3' : scene = 3; break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (scene) {
        case 1:
            ofSetColor(255);
            ofDrawCircle(ofGetWidth() / 4, ofGetHeight() / 2, fader01 * 300);
            ofDrawCircle(ofGetWidth() * 2 / 4, ofGetHeight() / 2, fader02 * 300);
            ofDrawCircle(ofGetWidth() * 3 / 4, ofGetHeight() / 2, fader03 * 300);
            break;
        case 2:
            ofSetColor(255);
            ofPushMatrix();
            ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
            ofFill();
            ofRotate(ofGetElapsedTimef() * fader02 * 300, 1, 1, 0);
            ofDrawBox(0, 0, 0, fader01 * 300, fader01 * 300, fader01 * 300);
            ofNoFill();
            ofDrawBox(0, 0, 0, fader03 * 600, fader03 * 600, fader03 * 600);
            ofPopMatrix();
            ofFill();
            break;
        case 3:
            ofPushMatrix();
            ofNoFill();
            ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
            for (int i = 0; i < int(fader01 * 100); i++) {
                ofSetColor(ofRandom(255));
                ofDrawBox(sin(ofGetElapsedTimef() * (i + 1) * 3) * fader02 * 400, cos(ofGetElapsedTimef() * (i + 1) * 3) * fader02 * 400, 0, fader03 * 400, fader03 * 400, fader03 * 400);
            }
            ofPopMatrix();
            ofFill();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
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
