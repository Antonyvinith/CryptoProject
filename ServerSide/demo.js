const { exec } = require("child_process");
    var pwd = "abc";
    exec("gcc Gautham_LightweightENC.c -lm", (error, stdout, stderr) => {
    if (error) {
        console.log(error);
        return;
    }
    if (stderr) {
        console.log(stderr);
        return;
    }
    });
    exec("./a.out < new.txt", (error, stdout, stderr) => {
    if (error) {
        return;
    }
    if (stderr) {
        pwd = stderr;
        console.log(pwd);
        return;
    }
    });