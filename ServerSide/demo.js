const { exec, spawn } = require("child_process");
const path = require("path");
const { MongoClient } = require("mongodb");

const uri = "mongodb://localhost:27017/";
const dbName = "Antony";
const collectionName = "Admin";
const username = "Vinith";
const password = "123";

async function storeEncryptedText(
  encryptedTextUsername,
  encryptedTextPassword
) {
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
  } catch (err) {
    console.error(`MongoDB error: ${err}`);
  } finally {
    await client.close();
  }
}

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

      const executablePath = path.join(__dirname, "Gautham_LightweightENC.exe");

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

// Encrypt the username
compileAndRunEncryption(username, (err, encryptedUsername) => {
  if (err) {
    console.error(`Username encryption error: ${err.message}`);
    return;
  }

  console.log(`Encrypted username: ${encryptedUsername}`);

  // Encrypt the password
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
