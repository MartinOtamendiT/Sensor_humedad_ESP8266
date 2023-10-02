const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <link rel="icon" href="./img/nopal.png">
  <title>SP-D</title>
  <style>
    html{
        font-family: Arial;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        margin: 0px auto;
        text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 2rem; }
    .units { font-size: 1.5rem; }
    .labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
    #Progress_Status {
      width: 80%%;
      background-color: #ddd;
    }  
    #myprogressBar {
      width: 1%%;
      height: 35px;
      background-color: #0592a4;
      text-align: center;
      line-height: 32px;
      color: black;
    }
  </style>
</head>
<body>
    <h2>Monitor SP-D</h2>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i> 
    <span class="labels">Humedad:</span>
    <span id="humidity">%HUMIDITY%</span>
    <span class="units">%%</span>
    <div id="Progress_Status">
      <div id="myprogressBar"></div>
    </div>
  </p>
</body>
<script>
var element = document.getElementById("myprogressBar");
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
      element.style.width = Number(this.responseText) + "%%";
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;
</script>
</html>
)rawliteral";

const char index_mini_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head><meta name="viewport" content="width=device-width,initial-scale=1"><link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous"><link rel="icon" href="./img/nopal.png"><title>SP-D</title><style>html{font-family:Arial;display:flex;flex-direction:column;justify-content:center;align-items:center;margin:0 auto;text-align:center}h2{font-size:3rem}p{font-size:2rem}.units{font-size:1.5rem}.labels{font-size:1.5rem;vertical-align:middle;padding-bottom:15px}#Progress_Status{width:80%%;background-color:#ddd}#myprogressBar{width:1%%;height:35px;background-color:#0592a4;text-align:center;line-height:32px;color:#000}</style></head><body><h2>Monitor SP-D</h2><p><i class="fas fa-tint" style="color:#00add6"></i><span class="labels">Humedad:</span><span id="humidity">%HUMIDITY%</span><span class="units">%%</span><div id="Progress_Status"><div id="myprogressBar"></div></div></p></body><script>var element=document.getElementById("myprogressBar");setInterval(function(){var e=new XMLHttpRequest;e.onreadystatechange=function(){4==this.readyState&&200==this.status&&(document.getElementById("humidity").innerHTML=this.responseText,element.style.width=Number(this.responseText)+"%%")},e.open("GET","/humidity",!0),e.send()},1e4)</script></html>
)rawliteral";
