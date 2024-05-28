from pymongo import MongoClient
from aes_ecc_audio import encrypt_ECC, curve, audio_to_binary, binary_to_audio,decrypt_ECC
import binascii
import hashlib, secrets, binascii
import os
import uuid
import time

# Connect to MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client.Data
collection = db.Audios

# ==================================Input Path==================================
audio_file_path = "Client-Side\PythonEncryptData\AudioEncrypt\AudioInput\sample_audio.mp3"


# Generate ECC key pair
privKey = secrets.randbelow(curve.field.n)
pubKey = privKey * curve.g


 # =====================>Calculating Time Taken for Text Data===============>
start_time=((time.time()*1000))

audio_data = audio_to_binary(audio_file_path)
encrypted_audio = encrypt_ECC(audio_data, pubKey)

end_time=((time.time()*1000))

print("\n\nTime taken to encrypt Audios data : ",(end_time-start_time)," milliseconds")
        # =========================================================================

# Convert encrypted audio to MongoDB document format
encrypted_audio_doc = {
    'ciphertext': binascii.hexlify(encrypted_audio[0]),
    'nonce': binascii.hexlify(encrypted_audio[1]),
    'authTag': binascii.hexlify(encrypted_audio[2]),
    'ciphertextPubKey': hex(encrypted_audio[3].x) + hex(encrypted_audio[3].y % 2)[2:]
}

# Insert encrypted audio document into MongoDB collection
collection.insert_one(encrypted_audio_doc)

print("Encrypted audio",encrypted_audio_doc)
print('\n\nAudio encrypted and saved to MongoDB successfully.')




unique_filename = f"decrypted_audio_{uuid.uuid4().hex}.mp3"
output_path = os.path.join("Client-Side","src", "PythonDecrypt", "Audio", unique_filename)

start_time = time.time()*1000;
decryptedMsg = decrypt_ECC(encrypted_audio, privKey)
binary_to_audio(decryptedMsg, output_path)
end_time = time.time()*1000;

