const { exec } = require("child_process"); 

const env = { ...process.env, PATH: `C:/MinGW/bin:${process.env.PATH}` };


exec("gcc Gautham_LightweightENC.c -lm", { env }, (error, stdout, stderr) => {
  if (error) {
    console.error(`exec error: ${error}`);
    return;
  }
  if (stderr) {
    console.error(`stderr: ${stderr}`);
    return;
  }
  console.log(`stdout: ${stdout}`);

  // Execute the compiled program
  exec("./Gautham_LightweightENC < new.txt", { env }, (error, stdout, stderr) => {
    if (error) {
      console.error(`exec error: ${error}`);
      return;
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      return;
    }
    console.log(`stdout: ${stdout}`);
  });
});