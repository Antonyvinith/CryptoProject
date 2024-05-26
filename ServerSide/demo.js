const { exec, spawn } = require("child_process");
const path = require("path");
const { MongoClient } = require("mongodb");



const uri = "mongodb://localhost:27017/"; 
const dbName = "Antony"; 
const collectionName = "Admin";


async function storeEncryptedText(encryptedText) {
  const client = await MongoClient.connect(uri);
  
  try {
    await client.connect();
    const database = client.db(dbName);
    const collection = database.collection(collectionName);

    const doc = { text: encryptedText, timestamp: new Date() };
    const result = await collection.insertOne(doc);
    console.log(`Encrypted text inserted with _id: ${result.insertedId}`);
  } catch (err) {
    console.error(`MongoDB error: ${err}`);
  } finally {
    await client.close();
  }
}

const sourceFilePath = path.join(__dirname, "Gautham_LightweightENC.c");

exec(`gcc ${sourceFilePath} -lm -o Gautham_LightweightENC.exe`, (compileError, compileStdout, compileStderr) => {
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
  const inputdata = "antony\n";

  const child = spawn(executablePath);

  let encryptedText = '';

  child.stdout.on("data", (data) => {
    encryptedText += data.toString();
  });

  child.stderr.on("data", (data) => {
    console.error(`stderr: ${data}`);
  });

  child.on("error", (error) => {
    console.error(`Execution error: ${error.message}`);
  });

  child.on("close", (code) => {
    console.log(`Child process exited with code ${code}`);
    if (encryptedText) {
      storeEncryptedText(encryptedText).catch(console.error);
    }
  });

  child.stdin.end(inputdata);
});
