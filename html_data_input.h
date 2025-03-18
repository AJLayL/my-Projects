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
