

#include <ESP8266WiFi.h>                                                // esp8266 library
#include <FirebaseArduino.h>                                             // firebase library
#include <Firebase.h>

#define FIREBASE_HOST "megaboth007.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "0hpnoqJQ5lQBFfnfWrSfplWa3ugIb71e4yO9ZZGN"                    // the secret key generated from firebase
#define WIFI_SSID "AndroidAP"                                          // input your home or public wifi name 
#define WIFI_PASSWORD "iwbu1988"  

long duration;
// defines pins numbers
 int trigPin = D9;  
 int echoPin = D8;  
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
// connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}
    
 

void loop() {

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  Firebase.setFloat("Distance", distance);  
}
