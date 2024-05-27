from pymongo import MongoClient
import binascii
import hashlib, secrets, binascii
from aes_ecc import encrypt_ECC, curve,decrypt_ECC
import time

# Connect to MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client.Data
collection = db.TextData


def encrypt_and_save_to_mongodb(text_message):
    global decryptedMsg
    try:
  
        message = text_message

 
        privKey = secrets.randbelow(curve.field.n)
        pubKey = privKey * curve.g

         # =====================>Calculating Time Taken for Text Data===============>
        start_time=((time.time()*1000))

        encryptedMsg = encrypt_ECC(message, pubKey)

        end_time=((time.time()*1000))

        print("\n\nTime taken to encrypt Text data : ",(end_time-start_time)," Milliseconds")
        # =========================================================================

        encryptedMsgObj = {
            'ciphertext': binascii.hexlify(encryptedMsg[0]).decode(),
            'nonce': binascii.hexlify(encryptedMsg[1]).decode(),
            'authTag': binascii.hexlify(encryptedMsg[2]).decode()
        }

     
        collection.insert_one(encryptedMsgObj)
        print("\n\nData Encrypted",encryptedMsg)

        decryptedMsg=decrypt_ECC(encryptedMsg,privKey)
        print(decryptedMsg)
        writeDecryptedData(decryptedMsg)

        print('\n\nText Data encrypted and saved to MongoDB successfully')
    except Exception as e:
        print('Error:', str(e))

def writeDecryptedData(decryptedMsg):
    path = "Client-Side\\src\\PythonDecrypt\\TextData\\DecryptedFile.txt"  
    start_time=time.time()*1000;
    decryptedMsg=decryptedMsg.decode('utf-8')
    end_time=time.time()*1000;

    print("\n\n Time Taken for Decrypted Text Data", (end_time-start_time),"Milliseconds")
    try:
        with open(path, "a") as file:
            file.write("\n\n\n")
            file.write(decryptedMsg[1:])
        print("\n\nDecrypted data has been written to the file successfully.to",path)
    except Exception as e:
        print("Error:", str(e))

if __name__ == '__main__':
 
    with open('Client-Side\\PythonEncryptData\\TextEncrypt\\InputText\\Text.txt', 'rb') as file:
        msg = file.read()
        encrypt_and_save_to_mongodb(msg)
        
       
   
