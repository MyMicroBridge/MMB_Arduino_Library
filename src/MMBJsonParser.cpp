#include "Arduino.h"

#include "MMBJsonParser.h"
	
//---PUBLIC---

//costruttore
MMBJsonParser::MMBJsonParser() {

	//message.toCharArray(_jsonMessage, JSON_MESSAGE_SIZE);

	// _jsonString.replace("\n", "");
	// _jsonString.replace("\t", "");
	// _jsonString.replace(" ", "");

	//Serial.println("----MESSAGE----\n");

	//Serial.print(_jsonMessage);

	//debugPrint("\n");

	// //debugPrint("OK");

	// //creo json object
	// _json = &_jsonBuffer.parseObject(_jsonMessage);


	// if (!(*_json).success()) {
	// 	debugPrint("_json parseObject() failed\n");
	// }

}

//destroyer
MMBJsonParser::~MMBJsonParser() {

}


//---PARSE FUNCTION
void MMBJsonParser::parseJson(char *message) { //devono essere già stati eliminati \n \t e spazi
	debugPrint(F("\n\n---MESSAGE TO PARSE---\n\n"));
	debugPrint(message);

	strcpy(_jsonMessage, message);
	//strcat(_jsonMessage, "\0");

	//creo json object
	_json = &_jsonBuffer.parseObject(_jsonMessage);


	if (!(*_json).success()) {
		debugPrint(F("_json parseObject() failed\n"));
	}
}

void MMBJsonParser::parseJson(String message) { //elimino \n \t e spazi
	
	message.replace("\n", "");
	message.replace("\t", "");
	message.replace(" ", "");

	debugPrint(F("\n\n---MESSAGE TO PARSE---\n\n"));
	debugPrint(message);



	message.toCharArray(_jsonMessage, JSON_MESSAGE_SIZE);

	//strcpy(_jsonMessage, message);
	//strcat(_jsonMessage, "\0");

	//creo json object
	_json = &_jsonBuffer.parseObject(_jsonMessage);


	if (!(*_json).success()) {
		debugPrint(F("_json parseObject() failed\n"));
	}
}


//---GET FUNCTION
int MMBJsonParser::getStatusCode() {
	return (*_json)["responses"][0]["status"]["code"];
}

JsonVariant MMBJsonParser::getValue(char *key) {
	return (*_json)["responses"][0]["data"]["default"]["value"];
}

//---DEBUG---
void MMBJsonParser::debugPrint(String msg) {

	if (DEBUG) {
		Serial.print(msg);
	}

}