const { exec } = require("child_process");
const ip = require("ip");
const express = require("express");
const app = express();
const port = 3000;

app.get("/", (req, res) => res.send("Hello World!"));
app.get("/20gg", (req, res) => {
  kill_Google_Chrome();
  res.sendStatus(200);
});

app.listen(port, () => {
  console.log(`Example app listening at http://${ip.address()}:${port}`);
});

function kill_Google_Chrome() {
  exec('killall "Google Chrome"', (error, stdout, stderr) => {
    if (error) {
      console.log(`error: ${error.message}`);
      return;
    }
    if (stderr) {
      console.log(`stderr: ${stderr}`);
      return;
    }
    console.log(`killed`);
  });
}
