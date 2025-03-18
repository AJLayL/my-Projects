#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// LED pin
const int ledPin = 2;
int blinkTime = 0;

WebServer server(80);

// Variables to store setup values
String dippingHeight = "";
String dippingSpeed = "";

// HTML content for setup and data pages
const char* setupPage = R"rawliteral(
<!DOCTYPE HTML>
<html>
<body>
  <h1>Setup Page</h1>
  <form id="setupForm">
    <p>
      <label for="height">Dipping Height:</label>
      <input type="text" id="height" name="height"><br><br>
    </p>
    <p>
      <label for="speed">Dipping Speed:</label>
      <input type="text" id="speed" name="speed"><br><br>
    </p>
    <input type="button" value="Submit" onclick="submitSetupForm()">
  </form>
  <br>
  <button onclick="navigateToDataPage()"> DATA  </button>

  <script>
    function submitSetupForm() {
      var height = document.getElementById('height').value;
      var speed = document.getElementById('speed').value;

      var xhr = new XMLHttpRequest();
      var url = `/submitSetup?height=${encodeURIComponent(height)}&speed=${encodeURIComponent(speed)}`;
      
      xhr.open("GET", url, true);
      xhr.send();
    }

    function navigateToDataPage() {
      window.location.href = '/data';
    }
    
  </script>
</body>
</html>
)rawliteral";

const char* dataPage = R"rawliteral(
<!DOCTYPE HTML>
<html>
<body>
  <h1>Data Collection Page</h1>
  <form id="dataForm">
    <p>
      <label for="date">Date:</label>
      <input type="date" id="date" name="date"><br><br>
    </p>
    <p>
      <label for="time">Time of experiment:</label>
      <input type="time" id="time" name="time"><br><br>
    </p>
    <p>
      <label for="thicknessBefore">Thickness Before:</label>
      <input type="text" id="thicknessBefore" name="thicknessBefore"><br><br>
    </p>
    <p>
      <label for="thicknessAfter">Thickness After:</label>
      <input type="text" id="thicknessAfter" name="thicknessAfter"><br><br>
    </p>
    <input type="button" value="Submit" onclick="submitDataForm()">
  </form>
  <br>
  <button onclick="navigateToDataHome()"> HOME </button>

  <script>
    function submitDataForm() {
      var date = document.getElementById('date').value;
      var time = document.getElementById('time').value;
      var thicknessBefore = document.getElementById('thicknessBefore').value;
      var thicknessAfter = document.getElementById('thicknessAfter').value;

      var xhr = new XMLHttpRequest();
      var url = `/submitData?date=${encodeURIComponent(date)}&time=${encodeURIComponent(time)}&thicknessBefore=${encodeURIComponent(thicknessBefore)}&thicknessAfter=${encodeURIComponent(thicknessAfter)}`;
      
      xhr.open("GET", url, true);
      xhr.send();
    }
   function navigateToDataHome() {
      window.location.href = '/';
    }
  </script>
</body>
</html>
)rawliteral";

void handleSetupPage() {
  server.send(200, "text/html", setupPage);
}

void handleDataPage() {
  server.send(200, "text/html", dataPage);
}

void handleSetupSubmit() {
  if (server.hasArg("height") && server.hasArg("speed")) {
    dippingHeight = server.arg("height");
    dippingSpeed = server.arg("speed");

    Serial.println("Setup Submission Received:");
    Serial.println("Dipping Height: " + dippingHeight);
    Serial.println("Dipping Speed: " + dippingSpeed);

    blinkTime = dippingHeight.toInt();

    server.send(200, "text/html", "Setup submission received!");
  } else {
    server.send(400, "text/html", "Incomplete setup submission.");
  }
}

void handleDataSubmit() {
  if (server.hasArg("date") && server.hasArg("time") && server.hasArg("thicknessBefore") && server.hasArg("thicknessAfter")) {
    String date = server.arg("date");
    String time = server.arg("time");
    String thicknessBefore = server.arg("thicknessBefore");
    String thicknessAfter = server.arg("thicknessAfter");

    Serial.println("Data Submission Received:");
    Serial.println("Date: " + date);
    Serial.println("Time: " + time);
    Serial.println("Thickness Before: " + thicknessBefore);
    Serial.println("Thickness After: " + thicknessAfter);

    server.send(200, "text/html", "Data submission received!");
  } else {
    server.send(400, "text/html", "Incomplete data submission.");
  }
}

void setup() {
  // Start the Serial communication to send messages to the computer
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  delay(10);

  // Setup LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Wait for the connection to establish
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleSetupPage);
  server.on("/data", handleDataPage);
  server.on("/submitSetup", handleSetupSubmit);
  server.on("/submitData", handleDataSubmit);

  server.begin();
  Serial.println("HTTP server started");
}

void reconnecting_to_wifi() { // Reconnect to Wi-Fi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnecting to WiFi...");
    WiFi.begin(ssid, password);
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
      delay(500);
      Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Reconnected to WiFi");
    }
  }
}

void loop() {
  reconnecting_to_wifi(); 

  if (blinkTime > 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  server.handleClient();
}
