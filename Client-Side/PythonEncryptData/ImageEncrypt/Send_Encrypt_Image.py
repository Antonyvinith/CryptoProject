from pymongo import MongoClient
from aes_ecc_image import encrypt_ECC, curve, image_to_byte_array,decrypt_ECC,decrypt_AES_GCM,byte_array_to_image
import binascii
import hashlib, secrets, binascii
from PIL import Image
import io
import os
import uuid
import time

# Connect to MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client.Data
collection = db.Images

# Load image from file
image_path = "Client-Side\PythonEncryptData\ImageEncrypt\ImageInput\Ghost1.jpg"
image = Image.open(image_path)

# Convert image to byte array
image_bytes = image_to_byte_array(image)

# Generate ECC key pair
privKey = secrets.randbelow(curve.field.n)
pubKey = privKey * curve.g



 # =====================>Calculating Time Taken for Image Data===============>
start_time=((time.time()*1000))

encrypted_image = encrypt_ECC(image_bytes, pubKey)

end_time=((time.time()*1000))

print("\n\nTime taken to encrypt Image data : ",(end_time-start_time)," Milliseconds")
        # =========================================================================


encrypted_image_doc = {
    'ciphertext': binascii.hexlify(encrypted_image[0]),
    'nonce': binascii.hexlify(encrypted_image[1]),
    'authTag': binascii.hexlify(encrypted_image[2]),
    'ciphertextPubKey': hex(encrypted_image[3].x) + hex(encrypted_image[3].y % 2)[2:]
}

print("\n\nEncrypted Message: " , encrypted_image_doc)

collection.insert_one(encrypted_image_doc)

print('\n\nImage encrypted and saved to MongoDB successfully.')


start_time=time.time()*1000;

decryptedMsg = decrypt_ECC(encrypted_image, privKey)

reconstructed_image = byte_array_to_image(decryptedMsg)

end_time=time.time()*1000;

print("\n\nTime Taken for Decryption of Image Data",(end_time-start_time),"Milliseconds")


unique_filename = f"decrypted_image_{uuid.uuid4().hex}.jpg"
output_path = os.path.join("Client-Side","src", "PythonDecrypt", "image", unique_filename)


reconstructed_image.save(output_path)
print(f'\n\nReconstructed image saved to {output_path}')

