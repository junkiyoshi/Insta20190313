#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int radius = 200;

	this->cam.begin();
	
	vector<ofColor> colors = { ofColor(255, 0, 0), ofColor(0, 255, 0), ofColor(0, 0, 255) };

	for (int z = -300; z <= 300; z += 80) {

		ofPushMatrix();
		ofRotate(ofNoise((z + 300) * 0.001 + ofGetFrameNum() * 0.008) * 720);

		int color_index = 0;
		for (int deg = 0; deg < 360; deg += 120) {

			ofSetColor(39);
			ofNoFill();
			ofBeginShape();
			for (int tmp_deg = deg; tmp_deg < deg + 100; tmp_deg++) {

				ofVertex(glm::vec3(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD), z));
			}
			ofEndShape();

			ofSetColor(colors[color_index++]);
			ofFill();
			ofDrawSphere(glm::vec3(radius * cos((deg + 110) * DEG_TO_RAD), radius * sin((deg + 110) * DEG_TO_RAD), z), 15);
		}

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}