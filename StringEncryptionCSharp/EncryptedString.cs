using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringEncryptionCSharp
{
    class EncryptedString
    {
        private string data;

        public EncryptedString(string text) => data = Encrypt(text);

        /// <summary>
        /// Create a new object using an encrypted value
        /// </summary>
        public static EncryptedString FromEncrypted(string encrypted)
        {
            EncryptedString newString = new EncryptedString("");
            newString.data = encrypted;
            return newString;
        }

        /// <summary>
        /// Gets the raw encrypted value
        /// </summary>
        public string GetEncrypted() => data;

        /// <summary>
        /// Get the decrypted value
        /// </summary>
        public string GetDecrypted() => Decrypt();

        private string Encrypt(string value)
        {
            Random r = new Random(value.Length);
            string newEncrypted = "";
            for (int i = 0; i < value.Length; i++)
                newEncrypted += Convert.ToChar((value[i] + r.Next(1, 255)) % 255);
            return newEncrypted;
        }

        private string Decrypt()
        {
            Random r = new Random(data.Length);
            string newDecrypted = "";
            for (int i = 0; i < data.Length; i++)
            {
                var rand = r.Next(1, 255);
                int decryptVal = data[i] - rand;
                if (decryptVal < 0)
                    decryptVal += 255;
                newDecrypted += Convert.ToChar(decryptVal);
            }
                
            return newDecrypted;
        }

        public static implicit operator string(EncryptedString v) => v.Decrypt();
    }
}
