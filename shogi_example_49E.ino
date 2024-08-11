// Variables to store the previous state of each sensor
int prevSensorA1 = 0;
int prevSensorA2 = 0;
int prevSensorA3 = 0;
int prevSensorA4 = 0;

// Variables to store the last high sensor
int lastHighSensor = 0;  // 0 = None, 1 = A1, 2 = A2, 3 = A3, 4 = A4

void setup() {
  Serial.begin(9600);

  // Initialize the analog pins as inputs
  for (int i = A0; i <= A3; i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  int sensorA1 = analogRead(A0);
  int sensorA2 = analogRead(A1);
  int sensorA3 = analogRead(A2);
  int sensorA4 = analogRead(A3);

  // Assuming a threshold for detecting a high signal from the Hall effect sensor
  int threshold = 600;  // Adjust based on your sensor's characteristics

  // Check which sensor is currently high
  if (sensorA1 > threshold) {
    if (lastHighSensor != 1) {
      Serial.println("Movement detected: " + getSensorName(lastHighSensor) + " to A1");
      lastHighSensor = 1;
    }
  }
  else if (sensorA2 > threshold) {
    if (lastHighSensor != 2) {
      Serial.println("Movement detected: " + getSensorName(lastHighSensor) + " to A2");
      lastHighSensor = 2;
    }
  }
  else if (sensorA3 > threshold) {
    if (lastHighSensor != 3) {
      Serial.println("Movement detected: " + getSensorName(lastHighSensor) + " to A3");
      lastHighSensor = 3;
    }
  }
  else if (sensorA4 > threshold) {
    if (lastHighSensor != 4) {
      Serial.println("Movement detected: " + getSensorName(lastHighSensor) + " to A4");
      lastHighSensor = 4;
    }
  }

  // Update the previous state with the current state for the next loop iteration
  prevSensorA1 = sensorA1;
  prevSensorA2 = sensorA2;
  prevSensorA3 = sensorA3;
  prevSensorA4 = sensorA4;

  delay(1000);  // Delay between checks
}

// Helper function to get sensor name
String getSensorName(int sensorId) {
  switch (sensorId) {
    case 1: return "A1";
    case 2: return "A2";
    case 3: return "A3";
    case 4: return "A4";
    default: return "None";
  }
}
