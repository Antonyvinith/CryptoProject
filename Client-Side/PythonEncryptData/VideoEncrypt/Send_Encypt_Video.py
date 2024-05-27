from pymongo import MongoClient
import binascii
import hashlib, secrets
from aes_ecc_video import encrypt_ECC, curve, video_to_binary,decrypt_ECC,binary_to_video
from datetime import datetime
import uuid
import os
import time

client = MongoClient("mongodb://localhost:27017/")
db = client.Data
collection = db.Video

video_file_path = "Client-Side\PythonEncryptData\VideoEncrypt\VideoInput\\file_example_MP4_640_3MG.mp4"



privKey = secrets.randbelow(curve.field.n)
pubKey = privKey * curve.g

# =========>Calculating Time Taken For Encryption for Both AES and ECC<==============
start_time=((time.time()*1000))

video_binary = video_to_binary(video_file_path)
encrypted_msg = encrypt_ECC(video_binary, pubKey)

end_time=((time.time()*1000))

print("\n\nTime Taken For Video Encryption",(end_time-start_time)," Milliseconds")

# ============================================================================================

encrypted_msg_doc = {
    'ciphertext': binascii.hexlify(encrypted_msg[0]),
    'nonce': binascii.hexlify(encrypted_msg[1]),
    'authTag': binascii.hexlify(encrypted_msg[2]),
    'ciphertextPubKey': hex(encrypted_msg[3].x) + hex(encrypted_msg[3].y % 2)[2:]
}

print("\n\nEncrypted message:",encrypted_msg_doc);
collection.insert_one(encrypted_msg_doc)

print('\n\nVideo data encrypted and saved to MongoDB successfully.')




unique_filename = f"OutputVideo_{datetime.now().strftime('%Y%m%d_%H%M%S')}.mp4"
output_file_path = os.path.join("Client-Side","src","PythonDecrypt", "Videos", unique_filename)


start_time = time.time()*1000;
decryptedMsg = decrypt_ECC(encrypted_msg, privKey)
binary_to_video(decryptedMsg, output_file_path)
end_time=time.time()*1000;

print("\n\nTime Taken For Video Decryption",(end_time-start_time)," Milliseconds")

print("\n\nDecrypted Video data successfully saved  to the path",output_file_path)