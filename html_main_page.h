
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
