const { MongoClient } = require("mongodb");
const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");
const { exec, spawn } = require("child_process");

const app = express();
app.use(cors());
const fs = require("fs").promises;
const path = require("path");

app.use(bodyParser.json());

// ==============>Create Admin API<======================

app.post("/CreateAdmin", async (req, res) => {
  const { username, password } = req.body;

  if (!username || !password) {
    return res
      .status(400)
      .json({ error: "Username and password are required" });
  }

  //   ================>To Verify Duplicate User<=========================

  //   ============>To Store All users<===================
  try {
    const uri = "mongodb://localhost:27017/";
    const dbName = "Data";
    const collectionName = "users";
    const client = new MongoClient(uri);
    await client.connect();
    const database = client.db(dbName);
    const collection = database.collection(collectionName);

    const doc = {
      Username: username,
      Password: password,
    };

    collection.insertOne(doc);
  } catch (err) {
    console.error(`MongoDB error: ${err}`);
  }

  // =============================>Authentication Algorithm to store User Details<===================
  async function storeEncryptedText(
    encryptedTextUsername,
    encryptedTextPassword
  ) {
    const uri = "mongodb://localhost:27017/";
    const dbName = "Data";
    const collectionName = "Users";

    const client = new MongoClient(uri);

    try {
      await client.connect();
      const database = client.db(dbName);
      const collection = database.collection(collectionName);

      const doc = {
        Username: encryptedTextUsername,
        Password: encryptedTextPassword,
        timestamp: new Date(),
      };
      const result = await collection.insertOne(doc);
      console.log(`Encrypted text inserted with _id: ${result.insertedId}`);
      res.send(result);
    } catch (err) {
      console.error(`MongoDB error: ${err}`);
    } finally {
      await client.close();
    }
  }
  // ======================>Running the C Algorithms Exceuting and performing a Callback to get the data Using EXEC===================>
  function compileAndRunEncryption(inputData, callback) {
    const sourceFilePath = path.join(__dirname, "Gautham_LightweightENC.c");

    exec(
      `gcc ${sourceFilePath} -lm -o Gautham_LightweightENC.exe`,
      (compileError, compileStdout, compileStderr) => {
        if (compileError) {
          console.error(`Compilation error: ${compileError.message}`);
          return;
        }
        if (compileStderr) {
          console.error(`Compilation stderr: ${compileStderr}`);
          return;
        }
        console.log(`Compilation stdout: ${compileStdout}`);

        const executablePath = path.join(
          __dirname,
          "Gautham_LightweightENC.exe"
        );

        const child = spawn(executablePath);

        let output = "";

        child.stdout.on("data", (data) => {
          output += data.toString();
        });

        child.stderr.on("data", (data) => {
          console.error(`stderr: ${data}`);
        });

        child.on("error", (error) => {
          console.error(`Execution error: ${error.message}`);
        });

        child.on("close", (code) => {
          console.log(`Child process exited with code ${code}`);

          const encryptedMessage = extractEncryptedMessage(output);

          if (encryptedMessage) {
            callback(null, encryptedMessage);
          } else {
            callback(new Error("Encrypted message not found in output."));
          }
        });

        child.stdin.end(inputData);
      }
    );
  }

  //   =======================>Extracting the ONly Encrypt MEssage of C Output===================>

  function extractEncryptedMessage(output) {
    const encryptedMessageStart = "------Encrypted Message------";
    const encryptedMessageEnd = "------Decrypted Message------";

    const startIndex = output.indexOf(encryptedMessageStart);
    const endIndex = output.indexOf(encryptedMessageEnd);

    if (startIndex !== -1 && endIndex !== -1) {
      return output
        .slice(startIndex + encryptedMessageStart.length, endIndex)
        .trim();
    }

    return null;
  }

  compileAndRunEncryption(username, (err, encryptedUsername) => {
    if (err) {
      console.error(`Username encryption error: ${err.message}`);
      return;
    }

    console.log(`Encrypted username: ${encryptedUsername}`);

    compileAndRunEncryption(password, (err, encryptedPassword) => {
      if (err) {
        console.error(`Password encryption error: ${err.message}`);
        return;
      }

      console.log(`Encrypted password: ${encryptedPassword}`);

      storeEncryptedText(encryptedUsername, encryptedPassword).catch(
        console.error
      );
    });
  });
});

// ---------------View Video api
app.use(bodyParser.json());
app.get("/viewVideo", async (req, res) => {
  try {
    uri = "mongodb://localhost:27017/";
    const client = await MongoClient.connect(uri);
    const db = client.db("Data");

    var user = await db.collection("Video").find({}).toArray();

    res.send(user.map((video) => video.Video));
  } catch (error) {
    console.log(error);
  }
});

// ============>View Users APi======================

app.get("/viewUsers", async (req, res) => {
  try {
    uri = "mongodb://localhost:27017/";
    const client = await MongoClient.connect(uri);
    const db = client.db("Data");

    var user = await db.collection("users").find({}).toArray();
    console.log(user);
    res.send(user.map((user) => user.Username));
  } catch (error) {
    console.log(error);
  }
});

// =========================Login API==================================

app.get("/login", async (req, res) => {
  const { username, Password } = req.body;

  try {
    uri = "mongodb://localhost:27017/";
    const client = await MongoClient.connect(uri);
    const db = client.db("Data");
    var dbPassword;

    function extractAndDecryptMessage(output) {
      const encryptedMessageStart = "------Encrypted Message------";
      const encryptedMessageEnd = "------Decrypted Message------";

      const startIndex = output.indexOf(encryptedMessageStart);
      const endIndex = output.indexOf(encryptedMessageEnd);

      if (startIndex !== -1 && endIndex !== -1) {
        return output
          .slice(startIndex + encryptedMessageStart.length, endIndex)
          .trim();
      }

      return null;
    }

    var user = await db.collection("users").find({ username }).toArray();
    var password = await db.collection("users").find({ password }).toArray();

    for (var data of user) {
      console.log(data.password);
      dbPassword = data.password;
    }

    if (user == username&& password == Password) {
      res.json({ message: "Login successful" });
    } else {
      res.status(404).json({ error: "Login Failed User not found" });
    }
  } catch (error) {
    console.log(error);
  }
  // ==========================>Authentication Algorithm============================
});

// ==========================>Read All data genertated from the Python decryptions =================

app.get("/read-file", async (req, res) => {
  try {
    const filePath =
      "C:/Users/antony.vinith/Desktop/FinalYearProj/Client-Side/src/PythonDecrypt/TextData/DecryptedFile.txt";
    var fileData = (await fs.readFile(filePath, "utf-8")).toString();

    res.send({ success: true, data: fileData });
  } catch (error) {
    console.error("Error reading file:", error);
    res.status(500).send({ success: false, error: "Error reading file" });
  }
});

const videoDirectory = path.join(
  "C:/Users/antony.vinith/Desktop/FinalYearProj/frontend-apparel/src/PythonDecrypt"
);

// ====================>Read All Videos API============================

app.get("/api/getVideos", (req, res) => {
  fs.readdir(videoDirectory, (err, files) => {
    if (err) {
      return res.status(500).send("Unable to scan directory: " + err);
    }

    const videoFiles = files.filter((file) => file);

    const videoPaths = videoFiles.map((file) =>
      path.join(videoDirectory, file)
    );
    res.json(videoPaths);
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
